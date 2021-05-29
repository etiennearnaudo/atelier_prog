#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "circuit.h"
#include "kart.h"
#include "outils.h"

void title(); //Affiche un écran titre, jusqu'aà avoir une ac(tion du joueur

void partie(); //Gère une partie,

void ecran_fin(bool &en_cours); //Modifie en_cours en false si on ne recommence une partie

void jeu();

#endif // AFFICHAGE_H
