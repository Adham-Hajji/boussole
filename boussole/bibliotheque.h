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