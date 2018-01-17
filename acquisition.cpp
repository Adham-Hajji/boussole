#include "bibliotheque.h"

float obtenirAnglePitch (NineAxesMotion &capteur) // (x, y)
{
  float magX = capteur.readMagX ();
  float magY = capteur.readMagY ();
  return atan2 (magY, magX);
}

float obtenirAngleYawn (NineAxesMotion &capteur) // (x, z)
{
 float magX = capteur.readMagX ();
 float magZ = capteur.readMagZ ();
 return atan2 (magZ, magX);
}

float obtenirAngleRoll (NineAxesMotion &capteur) // (y, z)
{
  float magY = capteur.readMagY ();
  float magZ = capteur.readMagZ ();
  return atan2 (magZ, magY);
}

