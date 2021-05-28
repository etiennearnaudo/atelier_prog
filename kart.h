#ifndef KART_H
#define KART_H

#include "circuit.h"

class vaisseau{
    Vect pos,vit;

public:
    vaisseau();
    Vect getP();
    Vect getV();
    void insert(circuit c, int valeur);
    void bouge(circuit c);

};

#endif // KART_H
