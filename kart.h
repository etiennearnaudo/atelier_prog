#ifndef KART_H
#define KART_H

#include "circuit.h"

class vaisseau{
    Vect2 pos,vit;
    Vect2 taille; //dimensions du vaisseau
    byte* rgba_vaisseau; //Image du vaisseau

public:
    vaisseau();
    ~vaisseau();
    Vect2 getP();
    Vect2 getV();
    Vect2 get_taille();
    void affiche(Color c);
    void bouge(circuit &c, Vect2 &Vect_decallage, int decallage);

};

#endif // KART_H
