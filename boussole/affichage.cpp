#include "bibliotheque.h"

/**
 * Cette fonction affiche du texte centrée sur l'écran

 * @param pLigne Le numéro de la ligne sur laquelle écrire le texte
 * @param pTexte Texte à écrire
 */
void afficherTexteCentre (const byte &pLigne, const String &pTexte)
{
  byte lTexteLongueur = pTexte.length ();
  clearLine (pLigne);
  gEcran.setCursor (16 / 2 - lTexteLongueur / 2, pLigne);
  gEcran.print (pTexte);
}

/**
 * Cette fonction efface une ligne de l'écran
 * @param pLigne Le numéro de la ligne dans laquelle supprimer le texte
 */
void clearLine (const byte &pLigne)
{
  gEcran.setCursor (0, pLigne);
  gEcran.print ("                ");
}

/**
 * Cette fonction affiche un écran de démarrage avec du texte
 */
void afficherDemarrage ()
{
  gEcran.clear ();
  afficherTexteCentre (0, "Boussole");
  afficherTexteCentre (1, "Projet Arduino");
  delay (3000);
  gEcran.clear ();
  afficherTexteCentre (0, "Demarrage...");
  delay (1000);
  gEcran.clear ();
}

/**
 * Cette fonction affiche un menu pour sélectionner un mode
 */
void afficherMenu ()
{
  gEcran.clear ();
  gEcran.setCursor (0, 0);
  gEcran.write (byte (FLECHE_NORD));
  gEcran.print (" Mode standard");
  gEcran.setCursor (0, 1);
  gEcran.write (byte (FLECHE_SUD));
  gEcran.print (" Mode ludique");
}

/**
 * Cette fonction affiche le mode standard de la boussole sur l'écran
 * @param pAngle
 * @param pDirection
 */
void afficherModeStandard (const float &pAngle, const String &pDirection)
{
  afficherTexteCentre (0, String (int (pAngle*180/PI)) + " deg");
  afficherTexteCentre (1, pDirection);
}

/**
 * Cette fonction affiche le mode ludique sur l'écran
 * @param pDirection
 * @param pFleche
 */
void afficherModeLudique (const String &pDirection, const byte &pFleche)
{
  clearLine (1);
  afficherTexteCentre (0, pDirection);
  gEcran.setCursor (0, 0);
  gEcran.write (pFleche);
}