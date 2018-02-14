#include "bibliotheque.h"

/**
 * Cette fonction affiche du texte centrée sur l'écran.
 * @param pLigne Le numéro de la ligne sur laquelle écrire le texte.
 * @param pTexte Le texte à afficher.
 */
void afficherTexteCentre (const uint8_t &pLigne, const String &pTexte)
{
  uint8_t vTexteLongueur = pTexte.length ();
  clearLine (pLigne);
  gEcran.setCursor (16 / 2 - vTexteLongueur / 2, pLigne);
  gEcran.print (pTexte);
} // afficherTexteCentre (.)

/**
 * Cette fonction efface une ligne de l'écran.
 * @param pLigne Le numéro de la ligne dans laquelle supprimer le texte.
 */
void clearLine (const uint8_t &pLigne)
{
  gEcran.setCursor (0, pLigne);
  gEcran.print (F ("                "));
} // clearLine (.)

/**
 * Cette fonction affiche un écran de démarrage avec du texte.
 */
void afficherDemarrage ()
{
  gEcran.clear ();
  afficherTexteCentre (0, F ("Boussole"));
  afficherTexteCentre (1, F ("Projet Arduino"));
  delay (3000);
  gEcran.clear ();
} // afficherDemarrage ()

/**
 * Cette fonction affiche un menu pour sélectionner un mode.
 */
void afficherMenu ()
{
  gEcran.clear ();
  gEcran.setCursor (0, 0);
  gEcran.write (byte (FLECHE_NORD));
  gEcran.print (F (" Mode standard"));
  gEcran.setCursor (0, 1);
  gEcran.write (byte (FLECHE_SUD));
  gEcran.print (F (" Mode ludique"));
} // afficherMenu ()

/**
 * Cette fonction affiche le mode standard de la boussole sur l'écran.
 * @param pAngle L'angle entre la direction de la boussole et le pôle nord.
 * @param pDirection Le nom du point cardinal.
 */
void afficherModeStandard (const float &pAngle, const String &pDirection)
{
  if (gAngle != pAngle) {
    gAngle = pAngle;
    #if UNITE_ANGLE == DEGRE
      afficherTexteCentre (0, String (int (pAngle*180/PI)) + F (" deg"));
    #elif UNITE_ANGLE == RADIAN
      afficherTexteCentre (0, String (pAngle) + F (" rad"));
    #endif
  }
  if (!gDirection.equals (pDirection)) {
    gDirection = pDirection;
    afficherTexteCentre (1, pDirection);
  }
} // afficherModeStandard (.)

/**
 * Cette fonction affiche le mode ludique de la boussole sur l'écran.
 * @param pDirection Le nom du point cardinal.
 * @param pFleche Le byte représentant la flèche de direction à afficher.
 */
void afficherModeLudique (const String &pDirection, const uint8_t &pFleche)
{
  if (!gDirection.equals (pDirection)) {
    gDirection = pDirection;
    clearLine (1);
    afficherTexteCentre (0, pDirection);
    gEcran.setCursor (0, 0);
    gEcran.write (pFleche);
  }
} // afficherModeLudique (.)