#include "bibliotheque.h"

/*
 * Cette fonction initialise les composants de la carte Arduino.
 */
void initialiserArduino ()
{
  #if CONFIGURATION == TEST
    Serial.begin (115200);
  #endif
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
  const PROGMEM byte lFleches [8][8] =
  {
    {B00100, B01110, B11111, B00100, B00100, B00100, B00000, B00000}, // flèche nord
    {B00000, B00000, B00100, B00100, B00100, B11111, B01110, B00100}, // flèche sud
    {B00000, B00100, B01100, B11111, B01100, B00100, B00000, B00000}, // flèche ouest
    {B00000, B00100, B00110, B11111, B00110, B00100, B00000, B00000}, // flèche est
    {B11100, B11000, B10100, B00010, B00001, B00000, B00000, B00000}, // flèche du nord-ouest
    {B00111, B00011, B00101, B01000, B10000, B00000, B00000, B00000}, // flèche du nord-est
    {B00000, B00000, B00000, B00001, B00010, B10100, B11000, B11100}, // flèche du sud-ouest
    {B00000, B00000, B00000, B10000, B01000, B00101, B00011, B00111}  // flèche du sud-est
  };

  gEcran.createChar (FLECHE_NORD, lFleches[0]);
  gEcran.createChar (FLECHE_SUD, lFleches[1]);
  gEcran.createChar (FLECHE_OUEST, lFleches[2]);
  gEcran.createChar (FLECHE_EST, lFleches[3]);
  gEcran.createChar (FLECHE_NORD_OUEST, lFleches[4]);
  gEcran.createChar (FLECHE_NORD_EST, lFleches[5]);
  gEcran.createChar (FLECHE_SUD_OUEST, lFleches[6]);
  gEcran.createChar (FLECHE_SUD_EST, lFleches[7]);
} // initialiserCaracteres ()

/**
 * Cette fonction réactualise les données du capteur.
 */
void actualiserCapteur ()
{
  gCapteur.updateMag ();
  gCapteur.updateEuler ();
  gCapteur.updateCalibStatus ();
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

  #if CONFIGURATION == PERFORMANCE
    // On vide les variables mémoires si elles ne sont pas vides
    if (gAngle) gAngle = 3*PI; // valeur impossible à atteindre par le capteur pour forcer l'affichage des modes
    if (gDirection) gDirection = F ("");
  #endif

  // On récupère l'entrée utilisateur
  byte lBouton = gEcran.readButtons ();

  // On détermine quel bouton a été appuyé
  if (lBouton && lBouton == BUTTON_UP) {
    gEtat = ETAT_MODE;
    gMode = MODE_STANDARD;
  }
  else if (lBouton && lBouton == BUTTON_DOWN) {
    gEtat = ETAT_MODE;
    gMode = MODE_LUDIQUE;
  }
} // procedureModeSelection ()

/**
 * Gestionnaire du mode standard.
 */
void procedureModeStandard ()
{
  float lAngle = obtenirAngle ();
  String lDirection = obtenirDirection (lAngle);
  afficherModeStandard (lAngle, lDirection);
} // procedureModeStandard ()

/**
 * Gestionnaire du mode ludique.
 */
void procedureModeLudique ()
{
  String lDirection = obtenirDirection (obtenirAngle ());
  byte lFleche = byte (obtenirFleche (lDirection));
  afficherModeLudique (lDirection, lFleche);
} // procedureModeLudique ()

/**
 * Fonction de test du capteur Arduino.
 */
void testCapteur ()
{
  Serial.println (String (gCapteur.readGyroX ()));
  Serial.println (String (gCapteur.readGyroY ()));
  Serial.println (String (gCapteur.readGyroZ ()));
  Serial.println (F (""));
} // testCapteur ()