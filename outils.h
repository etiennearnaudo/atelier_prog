#ifndef OUTILS_H
#define OUTILS_H

#include <Imagine/Images.h>
#include <Imagine/Graphics.h>
#include <iostream>
#include <cassert>
using namespace Imagine;
using namespace std;

typedef Image<byte> Img;


const int taille_case = 10 ; //taille d'une case
const int largeur = 32 ; //largeur en nb de case
const int hauteur = 32 ; //hauteur en nb de case
const int profondeur = 40 ; //profondeur en nb de case du tunnel
const int distance_affichage = 9; //On n'affiche qu'une partie du tunnel
const int freq_obstacle = 10 ; //obstacle tous les x avancements
const int nbre_mvt_couche = 3 ; //On peut bouger tant de fois par tour
const int decallage = 3 ; //on décalle l'affichage de tant vers le haut pour donner l'impression de perspective

const int pause = 20 ; //on avance tous les tant

const int taille_vaisseau_x = 5 ; //taille vaisseau
const int taille_vaisseau_y = 2 ; //taille vaisseau
const int v_x = 2 ; //vitesse de déplacement horizontale
const int v_y = 2 ; //vitesse de déplacement verticale
const int repetition=1 ;

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
