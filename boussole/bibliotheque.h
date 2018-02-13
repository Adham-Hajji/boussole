#ifndef __BIBLIOTHEQUE_H__
#define __BIBLIOTHEQUE_H__

//------------------------------------------------------------------------------------//

/* Macro constantes */

// Paramètres
#define DUREE_PERIODE 100
#define MODE_CAPTEUR MANUAL // auto, manual
#define CONFIGURATION TEST  // standard, performance, test
#define UNITE_ANGLE RADIAN  // degre, radian

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

/* Interface des variables globales */

// Variables d'état

extern float gAngle;
extern String gDirection;
extern byte gEtat;
extern byte gMode;

// Composants

extern NineAxesMotion gCapteur;
extern Adafruit_RGBLCDShield gEcran;

//------------------------------------------------------------------------------------//

// Affichage
void afficherTexteCentre (const byte &pLigne, const String &pTexte);
void clearLine (const byte &pLigne);

void afficherDemarrage ();
void afficherMenu ();
void afficherModeStandard (const float &pAngle, const String &pDirection);
void afficherModeLudique (const String &pDirection, const byte &pFleche);

#endif