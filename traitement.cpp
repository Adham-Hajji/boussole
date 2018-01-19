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
  byte fleches [8][8] =
  {
    {B00100, B01110, B11111, B00100, B00100, B00100, B00000, B00000}, // flèche nord
    {B00000, B00100, B01100, B11111, B01100, B00100, B00000, B00000}, // flèche ouest
    {B00000, B00100, B00110, B11111, B00110, B00100, B00000, B00000}, // flèche est
    {B00000, B00000, B00100, B00100, B00100, B11111, B01110, B00100}, // flèche sud
    {B11100, B11000, B10100, B00010, B00001, B00000, B00000, B00000}, // flèche du nord-ouest
    {B00111, B00011, B00101, B01000, B10000, B00000, B00000, B00000}, // flèche du nord-est
    {B00000, B00000, B00000, B00001, B00010, B10100, B11000, B11100}, // flèche du sud-ouest
    {B00000, B00000, B00000, B10000, B01000, B00101, B00011, B00111}  // flèche du sud-est
  };

  ecran.createChar (FLECHE_NORD, fleches[0]);
  ecran.createChar (FLECHE_OUEST, fleches[1]);
  ecran.createChar (FLECHE_EST, fleches[2]);
  ecran.createChar (FLECHE_SUD, fleches[3]);
  ecran.createChar (FLECHE_NORD_OUEST, fleches[4]);
  ecran.createChar (FLECHE_NORD_EST, fleches[5]);
  ecran.createChar (FLECHE_SUD_OUEST, fleches[6]);
  ecran.createChar (FLECHE_SUD_EST, fleches[7]);
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


byte directionFleche (String determinetrDirectionPitch)
{
  if (determinetrDirectionPitch == "Sud")
  {
    return FLECHE_SUD.
  }
  else if (determinetrDirectionPitch == "Sud-Ouest")
  {
    return FLECHE_SUD_OUEST;
  }
  else if (determinetrDirectionPitch == "Ouest")
  {
    return FLECHE_OUEST;
  }
  else if (determinetrDirectionPitch == "Nord-Ouest")
  {
    return FLECHE_NORD_OUEST;
  }
  else if (determinetrDirectionPitch == "Nord")
  {
    return FLECHE_NORD;
  }
  else if (determinetrDirectionPitch == "Nord-Est")
  {
    return FLECHE_NORD_EST;
  }
  else if (determinetrDirectionPitch == "Est")
  {
    return FLECHE_EST;
  }
  esle
  {
    return FLECHE_SUD_EST;
  }
}
