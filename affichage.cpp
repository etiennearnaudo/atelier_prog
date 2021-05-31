#include "affichage.h"

bool crash(circuit &c, vaisseau &v,int couche){
    bool test = false ;
    for(int i=0;i<v.get_taille().getx();i++){
        for(int j=0;j<v.get_taille().gety();j++) {
            pixel p(v.getP().getx()+i,v.getP().gety()+j,couche);
            test= test + (c.getPixel(p) == 2);
        }
    }
    return(test);
}

void partie(){
    circuit c(largeur,hauteur,profondeur);
    vaisseau v;
    int couche = 0;
    bool encours=true;
    while(encours){
        c.reinit_couche((couche+distance_affichage)%profondeur);
        for(int k=0;k<distance_affichage-1;k++){
            c.obstacles[k].set_type(c.obstacles[k+1].get_type());
        }
        if (((couche+distance_affichage)%profondeur)%freq_obstacle==0){
            obstacle ob(largeur,hauteur,(couche+distance_affichage)%profondeur);
            c.obstacles[distance_affichage-1].set_type(ob.get_type());
            ob.insert(c);
        }
        else{
            c.obstacles[distance_affichage-1].set_type(0);
        }
        for (int k=0;k<nbre_mvt_couche;k++) if (encours){
            v.bouge(c,decallage);
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
