#include "bibliotheque.h"


/* Variables */

NineAxesMotion capteur;                                 // objet associé au capteur
Adafruit_RGBLCDShield ecran = Adafruit_RGBLCDShield (); // objet associé à l'écran ecran
float anglePrecedent;                                   // variable stockant l'angle précédent de la boussole
String directionPrecedente;                             // variable stockant la direction précédente de la boussole


/* Configuration du programme */

void setup ()
{
  initialiserArduino (capteur, ecran);
  initialiserCaracteres (ecran);
  afficherDemarrage (ecran);
  afficherMenu (ecran);
  delay (1000);
  ecran.clear ();
}


/* Boucle principale */

void loop ()
{
  if (millis () % DUREE_PERIODE == 0)
  {
    #if MODE_CAPTEUR == MANUAL
      actualiserCapteur (capteur);
    #endif

    float vAngle = obtenirAngle (capteur);
    afficherModeLudique (ecran, determinerDirection (vAngle));
  }
}
