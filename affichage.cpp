#include "affichage.h"

bool crash(circuit &c, vaisseau &v, int couche){
    bool test = false ;
    for(int i=0;i<v.get_taille().getx();i++){
        for(int j=0;j<v.get_taille().gety();j++) {
            pixel p(v.getP().getx()+i,v.getP().gety()+j,couche);
            test= test + (c.getPixel(p) == 2);
        }
    }
    return(test);
}

void affiche_fond(int decallage){
    int width=largeur;
    int heigth=hauteur;
    fillRect(0,0,width*taille_case,heigth*taille_case,BLACK);

    for(int k=0;k<nb_star;k++){
        int x=Random(0,largeur*taille_case);
        int y=Random(0,hauteur*taille_case);
        int r=Random(1,2);
        fillCircle(x,y,r,WHITE);
    }

    for(int n=distance_affichage;n>0;n--){
        int size = taille_case-(distance_affichage-n);
        int dec_x = (distance_affichage-n)*(width/2);
        int dec_y = (distance_affichage-n)*((heigth/2)-decallage);

//        fillRect(dec_x,dec_y,(width)*size,size,WHITE); //haut
//        fillRect(dec_x,dec_y,size,(heigth)*size,WHITE); //gauche
//        fillRect((width-1)*size+dec_x,dec_y,size,(heigth)*size,WHITE); //droite
        fillRect(dec_x,(heigth-1)*size+dec_y,(width)*size,size,WHITE); //bas
    }
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
        if (((couche+distance_affichage)%profondeur)%freq_obstacle==0){ //Si on doit afficher un obstacle
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
        milliSleep(pause);
    }
    click();
}

void title(){
    for(int n=distance_affichage;n>0;n--){
        affiche_fond(decallage);
        int size = taille_case-(distance_affichage-n);
        int dec_x = (distance_affichage-n)*(largeur/2);
//        int dec_y = (distance_affichage-n)*((hauteur/2)-decallage);
        drawString(dec_x,(int(hauteur/2))*taille_case,"XTREME SPACESHIP",WHITE,2.1*size);
        if(n==distance_affichage) click();
        milliSleep(pause);
    }
    milliSleep(500);
}

void jeu(){
    openWindow(largeur*taille_case,hauteur*taille_case);
    title();
    bool nvlle_partie=true;
    while(nvlle_partie){
        partie();
    }
    endGraphics();
}
