#ifndef OUTILS_H
#define OUTILS_H

#include <Imagine/Images.h>
#include <Imagine/Graphics.h>
#include <iostream>
#include <cassert>
using namespace Imagine;
using namespace std;

typedef Image<byte> Img;


const int taille_case = 10 ;
const int largeur = 32 ;
const int hauteur = 32 ;
const int profondeur = 25 ;

class Vect{
    int x,y,z;
public :
    Vect() = default ;
    Vect(int a, int b, int c);
    Vect operator + (Vect a);
    Vect operator - (Vect a);
    Vect operator * (double a);
    Vect operator / (double a);
    int getx();
    int gety();
    int getz();
    void setx(int a);
    void sety(int a);
    void setz(int a);
};

void InitRandom();

int Random(int a, int b);

int clavier();

const Vect droite = Vect(1,0,0);
const Vect bas = Vect(0,1,0);
const Vect gauche = Vect(-1,0,0);
const Vect haut = Vect(0,-1,0);

#endif // OUTILS_H
