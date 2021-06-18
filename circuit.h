#pragma once

#include "outils.h"

class circuit;

class obstacle{
    FVector<int,3> principal; //pixel en haut à gauche
    int taille;
//    byte* rgba_tie; //Image du méchant


    obstacle(const obstacle&);
    void operator=(const obstacle&);

public:
    int type;
    FVector<int,3> ob[hauteur*largeur];

    obstacle(){}
    obstacle(int w,int h,int z);
//    ~obstacle();
    FVector<int,3> getPrincipal();
    void setPrincipal(FVector<int,3> p);
    void insert(circuit &c);
    void affiche(int couche, FVector<int,2> Vect_decallage);
    int gettaille();
    int get_type();
    void set_type(int Type);
};

class circuit{
    int tunnel[largeur*hauteur*profondeur];
    int width, heigth, depth;

    public:
    obstacle obstacles[distance_affichage]; //Liste des types d'obstacles à afficher dans la zone d'affichage

    circuit(int w, int h, int d);
    void reinit_couche(int z);
    void setPixel(FVector<int,3> &p,int value);
    void affiche(FVector<int,2> Vect_decallage);
    int getPixel(FVector<int,3> &p);
    void insert(obstacle &ob, int couche);
};
