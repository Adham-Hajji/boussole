#include "bibliotheque.h"

float obtenirAnglePitch (NineAxesMotion &capteur) // (x, y)
{
  float magX = capteur.readMagX ();
  float magY = capteur.readMagY ();
  return atan2 (magY, magX);
}

float obtenirAngleYawn (NineAxesMotion &capteur) // (x, y, z)
{
 float magX = capteur.readMagX ();
 float magY = capteur.readMagY ();
 float magZ = capteur.readMagZ ();
 return atan2 (magZ, magX);
}



