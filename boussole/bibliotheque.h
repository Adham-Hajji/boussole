#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

//------------------------------------------------------------------------------------//

/* Librairies */

#include <NineAxesMotion.h>
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>

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

/* Macro constantes */

// Paramètres
#define DUREE_PERIODE 100
#define MODE_CAPTEUR MANUAL

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

/* Prototypes */

// Acquisition
float obtenirAngle ();
String obtenirDirection (float pAngle);
byte obtenirFleche (String pDirection);

// Traitement
void initialiserArduino ();
void initialiserCaracteres ();
void actualiserCapteur ();

void procedureModeSelection ();
void procedureModeStandard ();
void procedureModeLudique ();

// Affichage
void afficherTexteCentre (const byte &pLigne, const String &pTexte);
void clearLine (const byte &pLigne);

void afficherDemarrage ();
void afficherMenu ();
void afficherModeStandard (const float &pAngle, const String &pDirection);
void afficherModeLudique (const String &pDirection, const byte &pFleche);

#endif