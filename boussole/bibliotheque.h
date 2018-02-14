#ifndef __BIBLIOTHEQUE_H__
#define __BIBLIOTHEQUE_H__

//------------------------------------------------------------------------------------//

/* Macro constantes */

// Paramètres
#define DUREE_PERIODE 20
#define MODE_CAPTEUR MANUAL    // mode d'actualisation : manuel ou automatique
#define CONFIGURATION STANDARD // configuration du programme : standard ou test
#define UNITE_ANGLE DEGRE      // unité d'affichage : en degrés ou en radians

// Flèches
#define FLECHE_NORD 0
#define FLECHE_SUD 1
#define FLECHE_OUEST 2
#define FLECHE_EST 3
#define FLECHE_NORD_OUEST 4
#define FLECHE_NORD_EST 5
#define FLECHE_SUD_OUEST 6
#define FLECHE_SUD_EST 7

// Modes
#define MODE_SELECTION 0
#define MODE_STANDARD 1
#define MODE_LUDIQUE 2

// États du programme
#define ETAT_INITIALISATION 0
#define ETAT_SELECTION 1
#define ETAT_MODE 2

//------------------------------------------------------------------------------------//

/* Librairies */

#include <NineAxesMotion.h>
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <avr/pgmspace.h>

//------------------------------------------------------------------------------------//

/* Variables globales */

// Variables d'état

extern float gAngle;
extern String gDirection;
extern uint8_t gEtat;
extern uint8_t gMode;

// Composants

extern NineAxesMotion gCapteur;
extern Adafruit_RGBLCDShield gEcran;

// Flèches directionnelles

static const uint8_t PROGMEM gFleches [8][8] = {
  {B00100, B01110, B11111, B00100, B00100, B00100, B00000, B00000}, // flèche nord
  {B00000, B00000, B00100, B00100, B00100, B11111, B01110, B00100}, // flèche sud
  {B00000, B00100, B01100, B11111, B01100, B00100, B00000, B00000}, // flèche ouest
  {B00000, B00100, B00110, B11111, B00110, B00100, B00000, B00000}, // flèche est
  {B11100, B11000, B10100, B00010, B00001, B00000, B00000, B00000}, // flèche du nord-ouest
  {B00111, B00011, B00101, B01000, B10000, B00000, B00000, B00000}, // flèche du nord-est
  {B00000, B00000, B00000, B00001, B00010, B10100, B11000, B11100}, // flèche du sud-ouest
  {B00000, B00000, B00000, B10000, B01000, B00101, B00011, B00111}  // flèche du sud-est
};

//------------------------------------------------------------------------------------//

/* Prototypes */

// Acquisition
float obtenirAngle ();
String obtenirDirection (float pAngle);
uint8_t obtenirFleche (String pDirection);

// Traitement
void initialiserArduino ();
void initialiserCaracteres ();
void actualiserCapteur ();
void procedureModeSelection ();
void procedureModeStandard ();
void procedureModeLudique ();

// Affichage
void afficherTexteCentre (const uint8_t &pLigne, const String &pTexte);
void clearLine (const uint8_t &pLigne);
void afficherDemarrage ();
void afficherMenu ();
void afficherModeStandard (const float &pAngle, const String &pDirection);
void afficherModeLudique (const String &pDirection, const uint8_t &pFleche);

#endif