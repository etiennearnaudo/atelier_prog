#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "outils.h"

class pixel{
    int x,y,z;
public:
    pixel();
    pixel(int x0,int y0,int z0);
    int getx();
    int gety();
    int getz();
    void setx(int a);
    void sety(int a);
    void setz(int a);
    int indice(int W,int H);
};

class circuit{
    int* tunnel;
    int width, heigth, depth;
public:
    circuit(int w, int h, int d);
    void setPixel(pixel p,int value);
    void affiche(int z,int size,int dec_vert,int dec_hor);
    void affiche(int z);
    int getTunnel(pixel p);
};

class obstacle{
    pixel* ob;
    pixel principal;
    int taille;
public:
    obstacle(int w,int h,int z);
    void insert(circuit c);
    int gettaille();
};


#endif // CIRCUIT_H
