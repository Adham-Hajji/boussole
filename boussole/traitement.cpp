#include "bibliotheque.h"

/*
 * Cette fonction initialise les composants de la carte Arduino.
 */
void initialiserArduino ()
{
  I2C.begin ();
  
  gCapteur.initSensor ();
  gCapteur.setOperationMode (OPERATION_MODE_NDOF);
  gCapteur.setUpdateMode (MODE_CAPTEUR);
  
  gEcran.begin (16, 2);
  gEcran.noCursor ();
  gEcran.display ();
} // initialiserArduino ()

/*
 * Cette fonction initialise les flèches indiquant les touches ainsi que les directions.
 */
void initialiserCaracteres ()
{
  gEcran.createChar (FLECHE_NORD, gFleches[0]);
  gEcran.createChar (FLECHE_SUD, gFleches[1]);
  gEcran.createChar (FLECHE_OUEST, gFleches[2]);
  gEcran.createChar (FLECHE_EST, gFleches[3]);
  gEcran.createChar (FLECHE_NORD_OUEST, gFleches[4]);
  gEcran.createChar (FLECHE_NORD_EST, gFleches[5]);
  gEcran.createChar (FLECHE_SUD_OUEST, gFleches[6]);
  gEcran.createChar (FLECHE_SUD_EST, gFleches[7]);
} // initialiserCaracteres ()

/**
 * Cette fonction réactualise les données du capteur.
 */
void actualiserCapteur ()
{
  gCapteur.updateCalibStatus ();
  gCapteur.updateMag ();
} // actualiserCapteur ()

/**
 * Gestionnaire du mode séléction. 
 */
void procedureModeSelection ()
{
  // Afficher le menu après avoir appuyé sur le bouton SELECT.
  if (gMode != MODE_SELECTION) {
    gMode = MODE_SELECTION;
    afficherMenu ();
  }

  // On vide les variables mémoires si elles ne sont pas vides
  if (gAngle) gAngle = 3*PI; // valeur impossible à atteindre par le capteur pour forcer l'affichage des modes
  if (gDirection) gDirection = F ("");

  // On récupère l'entrée utilisateur
  uint8_t vBouton = gEcran.readButtons ();

  // On détermine quel bouton a été appuyé
  if (vBouton && vBouton == BUTTON_UP) {
    gEtat = ETAT_MODE;
    gMode = MODE_STANDARD;
  }
  else if (vBouton && vBouton == BUTTON_DOWN) {
    gEtat = ETAT_MODE;
    gMode = MODE_LUDIQUE;
  }
} // procedureModeSelection ()

/**
 * Gestionnaire du mode standard.
 */
void procedureModeStandard ()
{
  afficherModeStandard (
    obtenirAngle (),
    obtenirDirection (obtenirAngle ())
  );
} // procedureModeStandard ()

/**
 * Gestionnaire du mode ludique.
 */
void procedureModeLudique ()
{
  afficherModeLudique (
    obtenirDirection (obtenirAngle ()),
    obtenirFleche (obtenirDirection (obtenirAngle ()))
  );
} // procedureModeLudique ()
