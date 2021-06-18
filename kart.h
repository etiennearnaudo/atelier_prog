#pragma once

#include "circuit.h"

class vaisseau{
    FVector<int,2> pos,vit; //Posiition du coin en haut à gauche
    FVector<int,2> taille; //Dimensions du vaisseau
    byte* rgba_vaisseau; //Image du vaisseau


    vaisseau(const vaisseau&);
    void operator=(const vaisseau&);

public:
    vaisseau();
//    ~vaisseau();
    FVector<int,2> getP();
    FVector<int,2> getV();
    FVector<int,2> get_taille();
    void affiche();
    void bouge(circuit &c, FVector<int,2> &Vect_decallage, int decallage);

};
