#include "kart.h"
#include "affichage.h"


vaisseau::vaisseau(){
    taille=FVector<int,2>(taille_vaisseau_x,taille_vaisseau_y);
    pos=FVector<int,2>(int(hauteur/2)-int(taille.x()/2),int(largeur/2)-int(taille.y()/2));
    vit=FVector<int,2>(v_x,v_y);
    int w_v=get_taille().x()*taille_case, h_v=get_taille().y()*taille_case;
    assert(loadAlphaColorImage(srcPath("Xwing_white.png"), rgba_vaisseau, w_v, h_v)); // Stop si l'image n'est pas chargee
    setMaskFromColor(rgba_vaisseau,w_v,h_v,WHITE);
}

FVector<int,2> vaisseau::getP(){
    return pos;
}

FVector<int,2> vaisseau::getV(){
    return vit;
}

void vaisseau::affiche(){
/// Avec image bmp :
    int  w_v=get_taille().x()*taille_case, h_v=get_taille().y()*taille_case;
    putAlphaColorImage(taille_case*getP().x(),taille_case*getP().y(),rgba_vaisseau,w_v,h_v); //On affiche le vaisseau
}

void vaisseau::bouge(circuit &c, FVector<int,2> &Vect_decallage, int decallage){
    int key=clavier();
    //key_droite:16777236
    if(key==16777236 && (getP().x()+taille.x()-1 + v_x<largeur)){
        Vect_decallage=Vect_decallage+FVector<int,2>(-1*decallage/3,0);
        pos=pos+droite;
    }
    //key_gauche:16777234
    if(key==16777234 && (getP().x()-v_x>=0)){
        Vect_decallage=Vect_decallage+FVector<int,2>(decallage/3,0);
        pos=pos+gauche;
    }
    //key_haut:16777235
    if(key==16777235 && (getP().y()-v_y>=0)){
        Vect_decallage=Vect_decallage+FVector<int,2>(0,decallage/3);
        pos=pos+haut;
    }
    //key_bas:16777237
    if(key==16777237 && (getP().y()+taille.y()+ v_x<hauteur)){
        Vect_decallage=Vect_decallage+FVector<int,2>(0,-1*decallage/3);
        pos=pos+bas;
    }

//    for(int freq=0; freq<freq_avance;freq++){
//        c.affiche(Vect_decallage, freq);
//        affiche();
//    }

    c.affiche(Vect_decallage);
    affiche();
}

FVector<int,2> vaisseau::get_taille(){
    return taille;
}



