#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "outils.h"

class pixel{
    int x,y,z;
public:
    pixel();
    ~pixel();
    pixel(int x0,int y0,int z0);
    int getx();
    int gety();
    int getz();
    void setx(int a);
    void sety(int a);
    void setz(int a);
    int indice(int W,int H);
};

class circuit;

class obstacle{
    int type;
    pixel* ob;
    pixel principal; //pixel en haut à gauche
    int taille;
public:
    obstacle()=default;
    obstacle(int w,int h,int z);
    ~obstacle();
    void insert(circuit &c);
    void affiche(int couche, Vect2 Vect_decallage);
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
    void setPixel(pixel p,int value);
    void affiche(Vect2 Vect_decallage);
    int getPixel(pixel p);
};

#endif // CIRCUIT_H
