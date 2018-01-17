#include "bibliotheque.h"

void initialiserCapteur (NineAxesMotion &capteur)
{
  capteur.initSensor ();
  capteur.setOperationMode (OPERATION_MODE_NDOF);
  capteur.setUpdateMode (CAPTEUR_MODE);
}

void initialiserEcran (Adafruit_RGBLCDShield &ecran)
{
  ecran.begin (16, 2);
  ecran.noCursor ();
  ecran.display ();
}

