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
const int profondeur = 36 ;
const int distance_affichage = 9;
const int freq_obstacle = 10 ; //obstacle tous les x avancements
const int nbre_mvt_couche = 3 ;
const int pause = 100 ;


const int v_x = 2 ;
const int v_y = 2 ;
const int repetition=1 ;

const int attente = 200;

class Vect2{
    int x,y,z;
public :
    Vect2() = default ;
    Vect2(int a, int b);
    Vect2 operator + (Vect2 a);
    Vect2 operator - (Vect2 a);
    Vect2 operator * (double a);
    Vect2 operator / (double a);
    int getx();
    int gety();
    void setx(int a);
    void sety(int a);
};

void InitRandom();

int Random(int a, int b);

int clavier();

const Vect2 droite = Vect2(1,0)*v_x;
const Vect2 bas = Vect2(0,1)*v_y;
const Vect2 gauche = Vect2(-1,0)*v_x;
const Vect2 haut = Vect2(0,-1)*v_y;

#endif // OUTILS_H
