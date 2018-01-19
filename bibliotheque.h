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
#define FLECHE_NORD 0
#define FLECHE_SUD 1
#define FLECHE_OUEST 2
#define FLECHE_EST 3
#define FLECHE_NORD_OUEST 4
#define FLECHE_NORD_EST 5
#define FLECHE_SUD_OUEST 6
#define FLECHE_SUD_EST 7


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
