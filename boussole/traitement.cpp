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
  gEcran.createChar (FLECHE_NORD, new uint8_t [8] {B00100, B01110, B11111, B00100, B00100, B00100, B00000, B00000});       // flèche nord
  gEcran.createChar (FLECHE_SUD, new uint8_t [8] {B00000, B00000, B00100, B00100, B00100, B11111, B01110, B00100});        // flèche sud
  gEcran.createChar (FLECHE_OUEST, new uint8_t [8] {B00000, B00100, B01100, B11111, B01100, B00100, B00000, B00000});      // flèche ouest
  gEcran.createChar (FLECHE_EST, new uint8_t [8] {B00000, B00100, B00110, B11111, B00110, B00100, B00000, B00000});        // flèche est
  gEcran.createChar (FLECHE_NORD_OUEST, new uint8_t [8] {B11100, B11000, B10100, B00010, B00001, B00000, B00000, B00000}); // flèche du nord-ouest
  gEcran.createChar (FLECHE_NORD_EST, new uint8_t [8] {B00111, B00011, B00101, B01000, B10000, B00000, B00000, B00000});   // flèche du nord-est
  gEcran.createChar (FLECHE_SUD_OUEST, new uint8_t [8] {B00000, B00000, B00000, B00001, B00010, B10100, B11000, B11100});  // flèche du sud-ouest
  gEcran.createChar (FLECHE_SUD_EST, new uint8_t [8] {B00000, B00000, B00000, B10000, B01000, B00101, B00011, B00111});    // flèche du sud-est
} // initialiserCaracteres ()

/**
 * Cette fonction réactualise les données du capteur.
 */
void actualiserCapteur ()
{
  gCapteur.updateCalibStatus ();
  gCapteur.updateQuat ();
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
