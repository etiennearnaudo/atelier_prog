#pragma once

#include <Imagine/Common.h>
#include <Imagine/Images.h>
#include <Imagine/Graphics.h>
#include <iostream>
#include <cassert>
using namespace Imagine;
using namespace std;

typedef Image<byte> Img;

//Affichage ambiant
const int taille_case = 10 ; //taille d'une case
const int largeur = 32 ; //largeur en nb de case
const int hauteur = 32 ; //hauteur en nb de case
const int profondeur = 39 ; //profondeur en nb de case du tunnel ATTENTION il faut que ce soit multiple de freqobstacle
const int distance_affichage = 10; //On n'affiche qu'une partie du tunnel
const int decallage = -5 ; //on décalle l'affichage de tant vers le haut pour donner l'impression de perspective
const int nb_star = 40 ; //Nobre d'étoiles dans le fond

//Gestion du gameplay
const int freq_obstacle = 13 ; //obstacle tous les x avancements
const int nbre_mvt_couche = 50 ; //On peut bouger tant de fois par tour
const int pause = 100 ; //on avance tous les tant

//Gestion du vaisseau
const int taille_vaisseau_x = 5 ; //taille vaisseau
const int taille_vaisseau_y = 2 ; //taille vaisseau
const int v_x = 1 ; //vitesse de déplacement horizontale
const int v_y = 1 ; //vitesse de déplacement verticale

void InitRandom();

int Random(int a, int b);

int clavier();

const FVector<int,2> droite = FVector<int,2>(1,0)*v_x;
const FVector<int,2> bas = FVector<int,2>(0,1)*v_y;
const FVector<int,2> gauche = FVector<int,2>(-1,0)*v_x;
const FVector<int,2> haut = FVector<int,2>(0,-1)*v_y;
