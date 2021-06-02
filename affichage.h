#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "circuit.h"
#include "kart.h"
#include "outils.h"


void title(); //Gère l'écran titre

void jeu(); //Fonction qui contient la gestion du jeu avec les parties etc

void partie(); //Une partie, jusqu'à ce que le joueur meurt.

void ecran_fin(bool &new_game); //Ecran de fin de partie

void affiche_fond(Vect2 Vect_decallage); //Gère l'écran de fin, si le joueur veut ou non recommencer une partie

bool crash(circuit &c,vaisseau &v); //Regarde si le vaisseau est dans un obstacle


#endif // AFFICHAGE_H
