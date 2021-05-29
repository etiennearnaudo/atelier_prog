#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "circuit.h"
#include "kart.h"
#include "outils.h"

const int freq_obstacle =10 ; //obstacle tous les x avancements

void generateSpace(circuit c1) ; //Crée un circuit contenant des obstacels générés aléatoirement

void avance(circuit c1) ; //Permet d'avancer d'une case

void animate(circuit c1, circuit c2, vaisseau v) ; //Gère le jeu

void title();

#endif // AFFICHAGE_H
