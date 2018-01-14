/* Import des librairies */

#include <NineAxesMotion.h>        // Librairie contenant l'API du capteur
#include <Wire.h>                  // Librairie de communication entre les composants
#include <Adafruit_RGBLCDShield.h> // Librairies contenant l'API de l'écran LCD


/* Définition de macro-constantes */

#define DUREE_PERIODE 20          // Durée avant le rafraîchissement
#define SENSOR_UPDATE_MODE MANUAL // Type de rafraîchissement du sensor


/* Variables */

NineAxesMotion sensor;                                // objet associé au capteur
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield (); // objet associé à l'écran LCD
float angleActuel,                                    // variable stockant l'angle actuel de la boussole
      anglePrecedent;                                 // variable stockant l'angle précédent de la boussole
String directionActuelle,                             // variable stockant la direction actuelle de la boussole
       directionPrecedente;                           // variable stockant la direction précédente de la boussole


/* Fonctions */

/**
 * Cette fonction affiche du texte centrée sur l'écran LCD
 * @param lcd L'objet représentant l'écran LCD
 * @param ligne Le numéro de la ligne sur laquelle écrire le texte
 * @param texte Texte à écrire
 */
void texteCentre (Adafruit_RGBLCDShield& lcd, const byte& ligne, const String& texte)
{
  uint8_t texteLongueur = texte.length (); // On récupère le nombre de caractères du texte que l'on souhaite afficher
  // On positionne le curseur de l'écran LCD avant d'écrire le texte centré
  lcd.setCursor (16 / 2 - texteLongueur / 2, ligne);
  lcd.print (texte);
}

/**
 * Cette fonction détermine la direction (Nord, Sud, Est, Ouest) actuelle de la boussole
 * @param angle L'angle en radians
 */
String determinerDirection (float angle)
{
  if (angle >= 0)       // premier cadran concernant le nord, l'ouest et le sud
  {
    if (angle >= 0 && angle < PI/8)
      return "Sud";
    else if (angle >= PI/8 && angle < 3*PI/8)
      return "Sud-Ouest";
    else if (angle >= 3*PI/8 && angle < 5*PI/8)
      return "Ouest";
    else if (angle >= 5*PI/8 && angle < 7*PI/8)
      return "Nord-Ouest";
    else if (angle >= 7*PI/8 && angle <= 9*PI/8)
      return "Nord";
  }
  else if (angle <= -0) // second cadran concernant le nord, l'est et le sud
  {
    if (angle > -PI/8 && angle <= -0)
      return "Sud";
    else if (angle > -3*PI/8 && angle <= -PI/8)
      return "Sud-Est";
    else if (angle > -5*PI/8 && angle <= -3*PI/8)
      return "Est";
    else if (angle > -7*PI/8 && angle <= -5*PI/8)
      return "Nord-Est";
    else
      return "Nord";
  }
}


/* Configuration du programme */

void setup ()
{
  // Initialisation des composants de la boussole
  Serial.begin (115200);
  I2C.begin ();
  sensor.initSensor ();

  // Initialisation de l'écran
  lcd.begin (16, 2);
  lcd.noCursor ();
  lcd.noBlink ();
  lcd.display ();

  // Affichage du message de démarrage
  texteCentre (lcd, 0, "Boussole");
  texteCentre (lcd, 1, "Projet Arduino");
  delay (3000);
  lcd.clear ();
  texteCentre (lcd, 0, "Demarrage...");

  // Configuration du shield 9-Axes Motion
  sensor.setOperationMode (OPERATION_MODE_NDOF);
  sensor.setUpdateMode (SENSOR_UPDATE_MODE);

  // Effaçage du message de démarrage + On affiche le strict minimum pour améliorer les performances (A NE PAS SUPPRIMER)
  delay (1000);
  lcd.clear ();
  lcd.setCursor (0, 0);
  lcd.print ("Angle:");
  lcd.setCursor (0, 0);
}


/* Boucle principale */

void loop ()
{
  // Effectuer les actions de rafraîchissement de l'écran LCD
  if (millis () % DUREE_PERIODE == 0)
  {
    // Si la réactualisation manuelle est activée
    #if SENSOR_UPDATE_MODE == MANUAL
      sensor.updateMag ();
      sensor.updateCalibStatus ();
    #endif

    // On créer des variables mémoires pour stocker les informations à comparer
    anglePrecedent = angleActuel;
    directionPrecedente = String (directionActuelle);

    // On obtient les résultats à jour
    angleActuel = atan2 (sensor.readMagY (), sensor.readMagX ()) - PI/4;
    directionActuelle = determinerDirection (angleActuel);

    // Si l'angle calculé est différent du précédent, alors on rafraîchit la zone d'affichage correspondante
    if (int (anglePrecedent*180/PI) != int (angleActuel*180/PI))
    {
      lcd.setCursor (7, 0);
      lcd.print (String (int (angleActuel*180/PI)) + " deg  ");
    }

    // Si la direction calculée est différente de la précédente, on rafraîchit la ligne
    if (!directionPrecedente.equals (directionActuelle))
    {
      Serial.println ("Actualisé ");
      lcd.setCursor (0, 1);
      lcd.print ("                ");
      texteCentre (lcd, 1, directionActuelle);
    }
  }
}
