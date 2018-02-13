#include "bibliotheque.h"

/**
 * Cette fonction affiche du texte centrée sur l'écran.
 * @param pLigne Le numéro de la ligne sur laquelle écrire le texte
 * @param pTexte Texte à écrire
 */
void afficherTexteCentre (const byte &pLigne, const String &pTexte)
{
  byte lTexteLongueur = pTexte.length ();
  clearLine (pLigne);
  gEcran.setCursor (16 / 2 - lTexteLongueur / 2, pLigne);
  gEcran.print (pTexte);
} // afficherTexteCentre (.)

/**
 * Cette fonction efface une ligne de l'écran.
 * @param pLigne Le numéro de la ligne dans laquelle supprimer le texte
 */
void clearLine (const byte &pLigne)
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
 * @param pAngle
 * @param pDirection
 */
void afficherModeStandard (const float &pAngle, const String &pDirection)
{
  #if CONFIGURATION == PERFORMANCE
    if (gAngle != pAngle) {
      gAngle = pAngle;

      #if UNITE_ANGLE == DEGRE
        afficherTexteCentre (0, String (pAngle) + F (" deg"));
      #elif UNITE_ANGLE == RADIAN
        afficherTexteCentre (0, String (int (pAngle*180/PI)) + F (" deg"));
      #endif
    }
    if (!gDirection.equals (pDirection)) {
      gDirection = pDirection;
      afficherTexteCentre (1, pDirection);
    }
  #elif CONFIGURATION == STANDARD
    gAngle = pAngle;
    gDirection = pDirection;

    #if UNITE_ANGLE == DEGRE
      afficherTexteCentre (0, String (pAngle) + F (" deg"));
    #elif UNITE_ANGLE == RADIAN
      afficherTexteCentre (0, String (int (pAngle*180/PI)) + F (" deg"));
    #endif
    
    afficherTexteCentre (1, pDirection);
  #endif
} // afficherModeStandard (.)

/**
 * Cette fonction affiche le mode ludique de la boussole sur l'écran.
 * @param pDirection
 * @param pFleche
 */
void afficherModeLudique (const String &pDirection, const byte &pFleche)
{
  #if CONFIGURATION == PERFORMANCE
    if (!gDirection.equals (pDirection)) {
      gDirection = pDirection;
      clearLine (1);
      afficherTexteCentre (0, pDirection);
      gEcran.setCursor (0, 0);
      gEcran.write (pFleche);
    }
  #elif CONFIGURATION == STANDARD
    gDirection = pDirection;
    clearLine (1);
    afficherTexteCentre (0, pDirection);
    gEcran.setCursor (0, 0);
    gEcran.write (pFleche);
  #endif
} // afficherModeLudique (.)