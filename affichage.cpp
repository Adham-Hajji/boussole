#include "bibliotheque.h"

/**
 * Cette fonction affiche du texte centrée sur l'écran ecran
 * @param ecran L'objet représentant l'écran LCD
 * @param ligne Le numéro de la ligne sur laquelle écrire le texte
 * @param texte Texte à écrire
 */
void afficherTexteCentre (Adafruit_RGBLCDShield &ecran, const byte &ligne, const String &texte)
{
  uint8_t texteLongueur = texte.length ();
  ecran.setCursor (16 / 2 - texteLongueur / 2, ligne);
  ecran.print (texte);
}

/**
 * Cette fonction affiche un écran de démarrage avec du texte
 * @param ecran L'objet représentant l'écran LCD
 */
void afficherDemarrage (Adafruit_RGBLCDShield &ecran)
{
  ecran.clear ();
  afficherTexteCentre (ecran, 0, "Boussole");
  afficherTexteCentre (ecran, 1, "Projet Arduino");
  delay (3000);
  ecran.clear ();
  afficherTexteCentre (ecran, 0, "Demarrage...");
  delay (1000);
  ecran.clear ();
}

/**
 * Cette fonction affiche un menu pour sélectionner un mode
 * @param ecran L'objet représentant l'écran LCD
 */
void afficherMenu (Adafruit_RGBLCDShield &ecran)
{
  
}

/**
 * Cette fonction affiche le mode standard de la boussole sur l'écran
 * @param ecran L'objet représentant l'écran LCD
 */
void afficherModeStandard (Adafruit_RGBLCDShield &ecran)
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
    directionActuelle = determinerDirectionPitch (angleActuel);

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

