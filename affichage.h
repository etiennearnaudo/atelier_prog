#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "circuit.h"
#include "kart.h"
#include "outils.h"


void title();

void jeu();

void partie();

void ecran_fin(bool &encours);

bool crash(circuit &c,vaisseau &v);


#endif // AFFICHAGE_H
