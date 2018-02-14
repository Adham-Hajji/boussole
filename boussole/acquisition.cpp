#include "bibliotheque.h"

/**
 * Cette fonction renvoi la valeur de l'angle magnétique.
 * @return Valeur en radians de l'angle magnétique.
 */
float obtenirAngle ()
{
  return atan2 (gCapteur.readMagX (), gCapteur.readMagY ());
} // obtenirAngle ()

/**
 * Cette fonction renvoi la direction du nord.
 * @param pAngle L'angle entre la direction de la boussole et le pôle nord.
 * @return Le nom du point cardinal.
 */
String obtenirDirection (float pAngle)
{
  if ( (pAngle >= 0 && pAngle < PI/8) || (pAngle > -PI/8 && pAngle <= -0) )
    return F ("Sud");
  else if (pAngle >= PI/8 && pAngle < 3*PI/8)
    return F ("Sud-Ouest");
  else if (pAngle >= 3*PI/8 && pAngle < 5*PI/8)
    return F ("Ouest");
  else if (pAngle >= 5*PI/8 && pAngle < 7*PI/8)
    return F ("Nord-Ouest");
  else if (pAngle >= 7*PI/8 && pAngle < 9*PI/8)
    return F ("Nord");
  else if (pAngle >= -3*PI/8 && pAngle < -PI/8)
    return F ("Sud-Est");
  else if (pAngle >= -5*PI/8 && pAngle < -3*PI/8)
    return F ("Est");
  else if (pAngle >= -7*PI/8 && pAngle < -5*PI/8)
    return F ("Nord-Est");
  else
    return F ("Nord");
} // obtenirDirection (.)

/**
 * Cette fonction renvoi la flèche à utiliser pour afficher la direction.
 * @param pDirection Le nom du point cardinal.
 * @return Le byte représentant la flèche de direction à afficher.
 */
uint8_t obtenirFleche (String pDirection)
{
  if (pDirection == F ("Sud"))
    return FLECHE_SUD;
  else if (pDirection == F ("Sud-Ouest"))
    return FLECHE_SUD_EST;
  else if (pDirection == F ("Ouest"))
    return FLECHE_EST;
  else if (pDirection == F ("Nord-Ouest"))
    return FLECHE_NORD_EST;
  else if (pDirection == F ("Nord"))
    return FLECHE_NORD;
  else if (pDirection == F ("Nord-Est"))
    return FLECHE_NORD_OUEST;
  else if (pDirection == F ("Est"))
    return FLECHE_OUEST;
  else
    return FLECHE_SUD_OUEST;
} // obtenirFleche (.)
