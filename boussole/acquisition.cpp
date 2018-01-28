#include "bibliotheque.h"

/**
 * Cette fonction renvoi la valeur de l'angle magnétique
 */
float obtenirAngle ()
{
  float magX = gCapteur.readMagX ();
  float magY = gCapteur.readMagY ();
  return atan2 (magY, magX);
}

/**
 * Cette fonction renvoi la direction du nord.
 * @param pAngle
 */
String obtenirDirection (float pAngle)
{
  if ( (pAngle >= 0 && pAngle < PI/8) || (pAngle > -PI/8 && pAngle <= -0) )
    return "Sud";
  else if (pAngle >= PI/8 && pAngle < 3*PI/8)
    return "Sud-Ouest";
  else if (pAngle >= 3*PI/8 && pAngle < 5*PI/8)
    return "Ouest";
  else if (pAngle >= 5*PI/8 && pAngle < 7*PI/8)
    return "Nord-Ouest";
  else if (pAngle >= 7*PI/8 && pAngle < 9*PI/8)
    return "Nord";
  else if (pAngle >= -3*PI/8 && pAngle < -PI/8)
    return "Sud-Est";
  else if (pAngle >= -5*PI/8 && pAngle < -3*PI/8)
    return "Est";
  else if (pAngle >= -7*PI/8 && pAngle < -5*PI/8)
    return "Nord-Est";
  else
    return "Nord";
}

/**
 * Cette fonction renvoi la flèche à utiliser pour afficher la direction
 * @param pDirection
 */
byte obtenirFleche (String pDirection)
{
  if (pDirection == "Sud")
    return FLECHE_SUD;
  else if (pDirection == "Sud-Ouest")
    return FLECHE_SUD_EST;
  else if (pDirection == "Ouest")
    return FLECHE_EST;
  else if (pDirection == "Nord-Ouest")
    return FLECHE_NORD_EST;
  else if (pDirection == "Nord")
    return FLECHE_NORD;
  else if (pDirection == "Nord-Est")
    return FLECHE_NORD_OUEST;
  else if (pDirection == "Est")
    return FLECHE_OUEST;
  else
    return FLECHE_SUD_OUEST;
}
