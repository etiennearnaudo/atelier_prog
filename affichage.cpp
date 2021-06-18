#include "affichage.h"

bool crash(circuit &c, vaisseau &v, int couche){
    bool test = false ;
    for(int i=0;i<v.get_taille().x();i++){
        for(int j=0;j<v.get_taille().y();j++) {
            FVector<int,3> p(v.getP().x()+i,v.getP().y()+j,couche);
            test = test + (c.getPixel(p) == 2);
        }
    }
    return(test);
}

void affiche_fond(FVector<int,2> Vect_decallage){
    int width=largeur;
    int heigth=hauteur;
    fillRect(0,0,width*taille_case,heigth*taille_case,BLACK);

    //Affichage des étoiles
    for(int k=0;k<nb_star;k++){
        int x=Random(0,largeur*taille_case);
        int y=Random(0,hauteur*taille_case);
        int r=Random(1,2);
        fillCircle(x,y,r,WHITE);
    }
    //Affichage de la tranchée
    for(int n=distance_affichage;n>0;n--){
        int size = taille_case-(distance_affichage-n);
        int dec_x = (distance_affichage-n)*((width/2)-Vect_decallage.x());
        int dec_y = (distance_affichage-n)*((heigth/2)-Vect_decallage.y());
//        fillRect(dec_x,dec_y,(width)*size,size,WHITE); //haut
        fillRect(dec_x,dec_y,size,(heigth)*size,Color(50+20*n,50+20*n,50+20*n)); //gauche
        fillRect((width-1)*size+dec_x,dec_y,size,(heigth)*size,Color(50+20*n,50+20*n,50+20*n)); //droite
        fillRect(dec_x,(heigth-1)*size+dec_y,(width)*size,size,Color(50+20*n,50+20*n,50+20*n)); //bas
    }
}

void partie(){
    FVector<int,2> Vect_decallage(0,decallage);
    circuit c(largeur,hauteur,profondeur);
    vaisseau v;
    int compteur=0;
    int couche = 0;
    bool encours=true;

    do{
        c.reinit_couche((couche+distance_affichage)%profondeur);
        for(int k=0;k<distance_affichage-1;k++){
            c.obstacles[k].set_type(c.obstacles[k+1].type);
            c.obstacles[k].setPrincipal(c.obstacles[k+1].getPrincipal());
        }
        if (((couche+distance_affichage)%freq_obstacle)==0){ //Si on doit afficher un obstacle
            obstacle ob(largeur,hauteur,(couche+distance_affichage)%profondeur);
            c.obstacles[distance_affichage-1].set_type(ob.type);
            c.obstacles[distance_affichage-1].setPrincipal(ob.getPrincipal());
            ob.insert(c);
        }
        else{
            c.obstacles[distance_affichage-1].set_type(0);
        }

        for (int j=0;j<nbre_mvt_couche;j++){
            if (encours){
                v.bouge(c, Vect_decallage, decallage);
                if (crash(c,v,couche)){
                encours=false;
                }
            }
        }

        couche=(couche+1)%profondeur;
        milliSleep(pause);
        compteur+=1;
    }
    while(encours);
}

void title(){
    for(int n=distance_affichage;n>0;n--){
        FVector<int,2> Vect_decallage(0,decallage);
        affiche_fond(Vect_decallage);
        int size = taille_case-(distance_affichage-n);
        int dec_x = (distance_affichage-n)*(largeur/2);
//        int dec_y = (distance_affichage-n)*((hauteur/2)-decallage);
        fillRect(dec_x, (int(hauteur/2))*taille_case-2.5*size, taille_case*largeur-2*dec_x, 2.5*size,BLACK);
        drawString(dec_x,(int(hauteur/2))*taille_case,"XTREME SPACESHIP",YELLOW,2.1*size);
        if(n==distance_affichage) click();
        milliSleep(pause);
    }
    milliSleep(500);
    fillRect(0,(int(hauteur/2))*taille_case-1.9*taille_case, taille_case*largeur, 1.6*taille_case, BLACK);
    drawString(0,(int(hauteur/2))*taille_case,"ESQUIVEZ LES OBSTACLES",WHITE,1.6*taille_case);
    milliSleep(1500);
}

//key_entrée 16777220
//key_echape 16777216
void ecran_fin(bool &new_game){
    fillRect(0, (int(hauteur/2))*taille_case-4*taille_case, taille_case*largeur, 4*taille_case,BLACK);
    drawString(0,(int(hauteur/2))*taille_case,"GAME OVER",WHITE,3.5*taille_case);
    bool pause = true;
    int key;
    while(pause) {
        key=clavier();
        pause= not (key==16777220 or key==16777216);
        if(key==16777216){
            new_game = not new_game;
        }
    }
}

void jeu(){
    openWindow(largeur*taille_case,hauteur*taille_case);
    bool nvlle_partie=true;
    title();
    while(nvlle_partie){
        partie();
        ecran_fin(nvlle_partie);
    }
    endGraphics();
}
