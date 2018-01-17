#include "bibliotheque.h"

void initialiserArduino ()
{
  Serial.begin (115200);
  I2C.begin ();
}

void initialiserCapteur (NineAxesMotion &capteur)
{
  capteur.initSensor ();
  capteur.setOperationMode (OPERATION_MODE_NDOF);
  capteur.setUpdateMode (MODE_CAPTEUR);
}

void initialiserEcran (Adafruit_RGBLCDShield &ecran)
{
  ecran.begin (16, 2);
  ecran.noCursor ();
  ecran.display ();
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

