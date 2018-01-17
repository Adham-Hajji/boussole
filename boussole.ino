#include "bibliotheque.h"

/* Variables */

NineAxesMotion capteur;                                // objet associé au capteur
Adafruit_RGBLCDShield ecran = Adafruit_RGBLCDShield (); // objet associé à l'écran ecran
float angleActuel,                                    // variable stockant l'angle actuel de la boussole
      anglePrecedent;                                 // variable stockant l'angle précédent de la boussole
String directionActuelle,                             // variable stockant la direction actuelle de la boussole
       directionPrecedente;                           // variable stockant la direction précédente de la boussole


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

  initialiserCapteur (capteur);
  initialiserEcran (ecran);

  // Affichage du message de démarrage
  afficherTexteCentre (ecran, 0, "Boussole");
  afficherTexteCentre (ecran, 1, "Projet Arduino");
  delay (3000);
  ecran.clear ();
  afficherTexteCentre (ecran, 0, "Demarrage...");


  // Effaçage du message de démarrage + On affiche le strict minimum pour améliorer les performances (A NE PAS SUPPRIMER)
  delay (1000);
  ecran.clear ();
  ecran.setCursor (0, 0);
  ecran.print ("Angle:");
  ecran.setCursor (0, 0);
}


/* Boucle principale */

void loop ()
{
  // Effectuer les actions de rafraîchissement de l'écran ecran
  if (millis () % DUREE_PERIODE == 0)
  {
    // Si la réactualisation manuelle est activée
    #if MODE_CAPTEUR == MANUAL
      capteur.updateMag ();
      capteur.updateCalibStatus ();
    #endif

    // On créer des variables mémoires pour stocker les informations à comparer
    anglePrecedent = angleActuel;
    directionPrecedente = String (directionActuelle);

    // On obtient les résultats à jour
    angleActuel = obtenirAnglePitch (capteur);
    directionActuelle = determinerDirection (angleActuel);

    // Si l'angle calculé est différent du précédent, alors on rafraîchit la zone d'affichage correspondante
    if (int (anglePrecedent*180/PI) != int (angleActuel*180/PI))
    {
      ecran.setCursor (7, 0);
      ecran.print ("         ");
      ecran.setCursor (7, 0);
      ecran.print (String (int (angleActuel*180/PI)) + " deg  ");
    }

    // Si la direction calculée est différente de la précédente, on rafraîchit la ligne
    if (!directionPrecedente.equals (directionActuelle))
    {
      Serial.println ("Actualisé ");
      ecran.setCursor (0, 1);
      ecran.print ("                ");
      afficherTexteCentre (ecran, 1, directionActuelle);
    }
  }
}
