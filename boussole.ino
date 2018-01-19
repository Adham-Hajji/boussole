#include "bibliotheque.h"

/* Variables */

NineAxesMotion capteur;                                // objet associé au capteur
Adafruit_RGBLCDShield ecran = Adafruit_RGBLCDShield (); // objet associé à l'écran ecran
float angleActuel,                                    // variable stockant l'angle actuel de la boussole
      anglePrecedent;                                 // variable stockant l'angle précédent de la boussole
String directionActuelle,                             // variable stockant la direction actuelle de la boussole
       directionPrecedente;                           // variable stockant la direction précédente de la boussole


/* Configuration du programme */

void setup ()
{
  initialiserArduino (capteur, ecran);
  initialiserCaracteres (ecran);
  afficherDemarrage (ecran);
  afficherMenu (ecran);
}


/* Boucle principale */

void loop ()
{

}
