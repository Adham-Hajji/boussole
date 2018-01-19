#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H


/* Librairies */

#include <NineAxesMotion.h>
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>


/* Macro constantes */

#define DUREE_PERIODE 500
#define MODE_CAPTEUR MANUAL

// Flèches
#define FLECHE_HAUTE 0
#define FLECHE_BASSE 3
#define FLECHE_GAUCHE 1
#define FLECHE_DROITE 2


/* Prototypes */

// Acquisition
float obtenirAnglePitch (NineAxesMotion &capteur);
float obtenirAngleYawn (NineAxesMotion &capteur);
float obtenirAngleRoll (NineAxesMotion &capteur);

// Traitement
void initialiserArduino (NineAxesMotion &capteur, Adafruit_RGBLCDShield &ecran);
void initialiserCaracteres (Adafruit_RGBLCDShield &ecran);
String determinerDirectionPitch (float anglePitch);

// Affichage
void afficherTexteCentre (Adafruit_RGBLCDShield &ecran, const byte &ligne, const String &texte);
void afficherDemarrage (Adafruit_RGBLCDShield &ecran);
void afficherMenu (Adafruit_RGBLCDShield &ecran);
void afficherModeStandard (Adafruit_RGBLCDShield &ecran);


#endif
