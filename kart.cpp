#include "kart.h"
#include "affichage.h"


//vaisseau::vaisseau(){
//    cout << 5 << endl;
//    taille=Vect2(taille_vaisseau_x,taille_vaisseau_y);
//    cout << 6 << endl;
//    pos=Vect2(int(hauteur/2)-int(taille.getx()/2),int(largeur/2)-int(taille.gety()/2));
//    cout << 7 << endl;
//    vit=Vect2(v_x,v_y);
//    int w_v=get_taille().getx()*taille_case, h_v=get_taille().gety()*taille_case;
//    cout << 8 << endl;
//    assert(loadAlphaColorImage(srcPath("Xwing_white.png"), rgba_vaisseau, w_v, h_v)); // Stop si l'image n'est pas chargee
//    cout << 9 << endl;
//    setMaskFromColor(rgba_vaisseau,w_v,h_v,WHITE);
//    cout << 10 << endl;
//}

//vaisseau::~vaisseau(){
//    delete[] rgba_vaisseau;
//}


vaisseau::vaisseau(){
    taille=Vect2(taille_vaisseau_x,taille_vaisseau_y);
    pos=Vect2(int(hauteur/2)-int(taille.getx()/2),int(largeur/2)-int(taille.gety()/2));
    vit=Vect2(v_x,v_y);
    int w_v=get_taille().getx()*taille_case, h_v=get_taille().gety()*taille_case;
    assert(loadColorImage(srcPath("Xwing_white.png"), r,g,b,a, w_v, h_v)); // Stop si l'image n'est pas chargee
    cout << 9 << endl;
    setMaskFromColor(r,g,b,a,w_v,h_v,WHITE);
    cout << 10 << endl;
}

vaisseau::~vaisseau(){
    delete[] r;
    delete[] g;
    delete[] b;
    delete[] a;
}







Vect2 vaisseau::getP(){
    return pos;
}

Vect2 vaisseau::getV(){
    return vit;
}

//void vaisseau::affiche(Color C){
///// Version carrés :
////    fillRect(getP().getx()*taille_case,getP().gety()*taille_case,get_taille().getx()*taille_case,get_taille().gety()*taille_case,C);

///// Avec image bmp :
//    int  w_v=get_taille().getx()*taille_case, h_v=get_taille().gety()*taille_case;
//    putAlphaColorImage(taille_case*getP().getx(),taille_case*getP().gety(),rgba_vaisseau,w_v,h_v); //On affiche le vaisseau
//}


void vaisseau::affiche(Color C){
/// Version carrés :
//    fillRect(getP().getx()*taille_case,getP().gety()*taille_case,get_taille().getx()*taille_case,get_taille().gety()*taille_case,C);

/// Avec image bmp :
    int  w_v=get_taille().getx()*taille_case, h_v=get_taille().gety()*taille_case;
    putColorImage(taille_case*getP().getx(),taille_case*getP().gety(),r,g,b,a,w_v,h_v);
}





void vaisseau::bouge(circuit &c, Vect2 &Vect_decallage, int decallage){
//    Vect2 Vect_decallage(0,decallage);
    int key=clavier();
    //key_droite:16777236
    if(key==16777236 && (getP().getx()+taille.getx()-1 + v_x<largeur)){
        Vect_decallage=Vect_decallage+Vect2(-1*decallage/3,0);
        pos=pos+droite;
    }
    //key_gauche:16777234
    if(key==16777234 && (getP().getx()-v_x>=0)){
        Vect_decallage=Vect_decallage+Vect2(decallage/3,0);
        pos=pos+gauche;
    }
    //key_haut:16777235
    if(key==16777235 && (getP().gety()-v_y>=0)){
        Vect_decallage=Vect_decallage+Vect2(0,decallage/3);
        pos=pos+haut;
    }
    //key_bas:16777237
    if(key==16777237 && (getP().gety()+taille.gety()+ v_x<hauteur)){
        Vect_decallage=Vect_decallage+Vect2(0,-1*decallage/3);
        pos=pos+bas;
    }

    c.affiche(Vect_decallage);
    affiche(PURPLE);
}

Vect2 vaisseau::get_taille(){
    return taille;
}



