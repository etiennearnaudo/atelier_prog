#include "affichage.h"

void jeu(){
    title();
    bool nvlle_partie=true;
    int key;
    while(nvlle_partie){
        partie();
        key=clavier();
        if (key==16777216) nvlle_partie=false;
    }
}

void partie(){
    circuit c(largeur,hauteur,profondeur);
    vaisseau v;
    int couche = 0;
    bool encours=true;
    while(encours){
        //c.affiche(couche%freq_obstacle);
        //v.affiche(PURPLE);
        c.reinit_couche((couche+distance_affichage)%profondeur);
        if ((couche+distance_affichage)%freq_obstacle==0){
            obstacle ob(largeur,hauteur,(couche+distance_affichage)%profondeur);
            ob.insert(c);
        }
        for (int k=0;k<nbre_mvt_couche;k++) if (encours){
            v.bouge(c);
            if (crash(c,v)) encours=false;
        }
        couche++;
        milliSleep(3*pause);
    }
}


bool crash(circuit c,vaisseau v){

}

void title(){


}
