#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H


/* Librairies */

#include <NineAxesMotion.h>
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>


/* Macro constantes */

#define DUREE_PERIODE 500
#define MODE_CAPTEUR MANUAL


/* Prototypes */

// Acquisition
float obtenirAnglePitch (NineAxesMotion &capteur);
float obtenirAngleYawn (NineAxesMotion &capteur);
float obtenirAngleRoll (NineAxesMotion &capteur);

// Traitement
void initialiserCapteur (NineAxesMotion &capteur);
void initialiserEcran (Adafruit_RGBLCDShield &ecran);

// Affichage
void afficherTexteCentre (Adafruit_RGBLCDShield &ecran, const byte &ligne, const String &texte);


#endif
