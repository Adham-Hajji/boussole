#include "bibliotheque.h"

/*
 * Cette fonction initialise les composants de la carte Arduino
 * @param capteur L'objet représentant le capteur
 * @param ecran L'objet représentant l'écran LCD
 */
void initialiserArduino (NineAxesMotion &capteur, Adafruit_RGBLCDShield &ecran)
{
  Serial.begin (115200);
  I2C.begin ();
  
  capteur.initSensor ();
  capteur.setOperationMode (OPERATION_MODE_NDOF);
  capteur.setUpdateMode (MODE_CAPTEUR);
  
  ecran.begin (16, 2);
  ecran.noCursor ();
  ecran.display ();
}

/*
 * Cette fonction initialise les caractères personnalisées (flèches indiquant les touches ainsi que les directions)
 * @param ecran L'objet représentant l'écran LCD
 */
void initialiserCaracteres (Adafruit_RGBLCDShield &ecran)
{
  byte fleches [4][8] =
  {
    {B00100, B01110, B11111, B00100, B00100, B00100, B00000, B00000}, // flèche nord
    {B00000, B00100, B01100, B11111, B01100, B00100, B00000, B00000}, // flèche ouest
    {B00000, B00100, B00110, B11111, B00110, B00100, B00000, B00000}, // flèche est
    {B00000, B00000, B00100, B00100, B00100, B11111, B01110, B00100}  // flèche sud
    {}, //flèche du haut-g
  };

  ecran.createChar (FLECHE_NORD, fleches[0]);
  ecran.createChar (FLECHE_OUEST, fleches[1]);
  ecran.createChar (FLECHE_EST, fleches[2]);
  ecran.createChar (FLECHE_SUD, fleches[3]);
}

String determinerDirectionPitch (float anglePitch)
{
  if ( (anglePitch >= 0 && anglePitch < PI/8) || (anglePitch > -PI/8 && anglePitch <= -0) )
    return "Sud";
  else if (anglePitch >= PI/8 && anglePitch < 3*PI/8)
    return "Sud-Ouest";
  else if (anglePitch >= 3*PI/8 && anglePitch < 5*PI/8)
    return "Ouest";
  else if (anglePitch >= 5*PI/8 && anglePitch < 7*PI/8)
    return "Nord-Ouest";
  else if (anglePitch >= 7*PI/8 && anglePitch <= 9*PI/8)
    return "Nord";
  else if (anglePitch > -3*PI/8 && anglePitch <= -PI/8)
    return "Sud-Est";
  else if (anglePitch > -5*PI/8 && anglePitch <= -3*PI/8)
    return "Est";
  else if (anglePitch > -7*PI/8 && anglePitch <= -5*PI/8)
    return "Nord-Est";
  else
    return "Nord";
}

