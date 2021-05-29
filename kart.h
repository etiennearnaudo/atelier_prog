#ifndef KART_H
#define KART_H

#include "circuit.h"

class vaisseau{
    Vect2 pos,vit;

public:
    vaisseau();
    Vect2 getP();
    Vect2 getV();
    void affiche(Color c);
    void bouge(circuit c);

};

#endif // KART_H
