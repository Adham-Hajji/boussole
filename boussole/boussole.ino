//------------------------------------------------------------------------------------//

/* Bibliothèque */

#include "bibliotheque.h"

//------------------------------------------------------------------------------------//

/* Définition des variables globales */

// Variables d'état

float gAngle;      // variable stockant l'angle actuel de la boussole
String gDirection; // variable stockant la direction actuelle de la boussole
byte gEtat;        // variable stockant l'état du programme
byte gMode;        // variable stockant le mode actuel du programme

// Composants

NineAxesMotion gCapteur;                                 // objet associé au capteur
Adafruit_RGBLCDShield gEcran = Adafruit_RGBLCDShield (); // objet associé à l'écran

//------------------------------------------------------------------------------------//

/*
 * Fonction de configuration d'Arduino.
 */
void setup ()
{
  gEtat = ETAT_INITIALISATION;
  
  initialiserArduino ();
  initialiserCaracteres ();
  afficherDemarrage ();
  afficherMenu ();

  gEtat = ETAT_SELECTION;
  gMode = MODE_SELECTION;
}

//------------------------------------------------------------------------------------//

/**
 * Boucle d'exécution du processeur Arduino
 */
void loop ()
{
  if (gEtat == ETAT_SELECTION) {
    procedureModeSelection ();
  }
  
  else if (gEtat == ETAT_MODE)
  {
    if (gMode == MODE_STANDARD) procedureModeStandard ();
    else if (gMode == MODE_LUDIQUE) procedureModeLudique ();
  }
}