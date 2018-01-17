#include "bibliotheque.h"

/**
 * Cette fonction affiche du texte centrée sur l'écran ecran
 * @param ecran L'objet représentant l'écran ecran
 * @param ligne Le numéro de la ligne sur laquelle écrire le texte
 * @param texte Texte à écrire
 */
void afficherTexteCentre (Adafruit_RGBLCDShield& ecran, const byte& ligne, const String& texte)
{
  uint8_t texteLongueur = texte.length ();
  ecran.setCursor (16 / 2 - texteLongueur / 2, ligne);
  ecran.print (texte);
}
