#include "affichage.h"

bool crash(circuit &c, vaisseau &v,int couche){
    bool test = false ;
    pixel p1(v.getP().getx(),v.getP().gety(),couche);
    pixel p2(v.getP().getx()+1,v.getP().gety(),couche);
    test= test + (c.getPixel(p1) == 2) + (c.getPixel(p2) == 2);
    return(test);
}

void partie(){
    circuit c(largeur,hauteur,profondeur);
    vaisseau v;
    int couche = 0;
    bool encours=true;
    while(encours){
        c.reinit_couche((couche+distance_affichage)%profondeur);
        if (((couche+distance_affichage)%profondeur)%freq_obstacle==0){
            obstacle ob(largeur,hauteur,(couche+distance_affichage)%profondeur);
            ob.insert(c);
        }
        for (int k=0;k<nbre_mvt_couche;k++) if (encours){
            v.bouge(c,couche);
            if (crash(c,v,couche)) encours=false;
        }
        couche=(couche+1)%profondeur;
        milliSleep(3*pause);
    }
    click();
}

void title(){


}

void jeu(){
    openWindow(largeur*taille_case,hauteur*taille_case);
//    title();
    bool nvlle_partie=true;
    int key;
    while(nvlle_partie){
        partie();
        key=clavier();
        if (key==16777216) nvlle_partie=false;
    }
}
