#include "bibliotheque.h"

float obtenirAngle (NineAxesMotion &capteur)
{
  float magX = capteur.readMagX ();
  float magY = capteur.readMagY ();
  return atan2 (magY, magX);
}

