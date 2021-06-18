#include "circuit.h"
#include "affichage.h"

int indice(FVector<int,3> p, int w, int h){
    return (p.x()+p.y()*w+w*h*p.z());
}

circuit::circuit(int w, int h, int d){
    width = w;
    heigth = h;
    depth = d;
    for(int n=0;n<distance_affichage;n++){
        obstacles[n].set_type(0);
    }

    for (int k=0;k<depth;k++){
        for (int i=0;i<width;i++){
            for (int j=0;j<heigth;j++){
                FVector<int,3> p(i,j,k);
                tunnel[indice(p, w, h)] = 0;
            }
        }
    }
}

void circuit::setPixel(FVector<int,3> &p,int value){
    tunnel[indice(p,width,heigth)] = value;
}

void circuit::affiche(FVector<int,2> Vect_decallage){
    affiche_fond(Vect_decallage);
    for(int i=distance_affichage-1;i>=0;i--){
        obstacles[i].affiche(i, Vect_decallage);
    }
}

int circuit::getPixel(FVector<int,3> &p){
    return tunnel[indice(p, width, heigth)];
}

void circuit::reinit_couche(int z){
    FVector<int,3> p;
    for (int i=0;i<width;i++){
        for (int j=0;j<heigth;j++){
            FVector<int,3> p(i,j,z);
            tunnel[indice(p, width, heigth)] = 0;
        }
    }
}

obstacle::obstacle(int w,int h,int z){
    int n=Random(1,3);
//    FVector<int,3> pix(0,0,z);

    //Barre verticale
    if (n==1){
        principal=FVector<int,3>(Random(0,(w/2)-1),0,0);
        type=1;
        taille = ((w/2)-1)*(h-2);
        for (int i=0;i<w/2-1;i++) for (int j=0;j<h-2;j++) {
            FVector<int,3> pix(i+1+principal.x(),j+1+principal.y(),z);
            ob[i+w*j]=pix;
        }

    }

    //Barre vecrticale
    if (n==2){
        principal=FVector<int,3>(0,Random(0,(h/2)-1),0);
        type=2;
        taille = (w-2)*((h/2)-1);
        for (int i=0;i<w-2;i++) for (int j=0;j<h/2-1;j++) {
            FVector<int,3> pix(i+1+principal.x(),j+1+principal.y(),z);
            ob[i+w*j]=pix;
       }

    }

    //Barre horizontle fine
    if(n==3){
        principal=FVector<int,3>(0,Random(0,h-4),0);
        type=3;
        taille = 3*(w-2);
        for (int i=0;i<w-2;i++) for (int j=0;j<3;j++){
            FVector<int,3> pix(i+1+principal.x(),j+1+principal.y(),z);
            ob[i+w*j]=pix;
        }

    }

//    if(n==4){
//        int w_t=40, h_t=30;
//        assert(loadColorImage(srcPath("Tie_white.png"), rgba_tie, w_t, h_t)); // Stop si l'image n'est pas chargee
////        setMaskFromColor(rgba_tie,w_t,h_t,WHITE);
//        type=4;
//        taille=12;
////        int x_t=Random(0,w-4);
////        int y_t=Random(0,h-3);
//        int x_t=0;
//        int y_t=0;
//        for (int i=0;i<4;i++) for (int j=0;j<3;j++){
//            pix.setx(x_t+i);
//            pix.sety(y_t+j);
//            ob[i+(w-2)*j]=pix;
//        }

//        principal=pixel(x_t,y_t,0);

//    }

}

void obstacle::insert(circuit &c){
    FVector<int,3> pix;
    for (int i=0;i<taille;i++) {
        pix=ob[i];
        c.setPixel(pix,2);
   }
}

void obstacle::affiche(int couche, FVector<int,2> Vect_decallage){
    int n=(distance_affichage-couche);
    int w=largeur;
    int h=hauteur;
    int size = taille_case-(distance_affichage-n);
    int dec_x = (distance_affichage-n)*((w/2)-principal.x()-Vect_decallage.x());
    int dec_y = (distance_affichage-n)*((h/2)-principal.y()-Vect_decallage.y());

    if (type==1){
        fillRect(dec_x+principal.x()*taille_case,dec_y+principal.y()*taille_case,(int(w/2))*size,(h)*size,Color(180+7*couche,0,0));
    }

    if (type==2){
        fillRect(dec_x+principal.x()*taille_case,dec_y+principal.y()*taille_case,(w)*size,(int(h/2))*size,Color(180+7*couche,0,0));
    }

    if(type==3){
        int largeur_bande = 3 ;
        fillRect(dec_x+principal.x()*taille_case,principal.y()*taille_case+dec_y,(w)*size,largeur_bande*size,Color(180+7*couche,0,0));
    }

//    if(type==4){
//        int w_t=40;
//        int h_t=30;
//        putAlphaColorImage(principal.getx()*taille_case+dec_x,principal.gety()*taille_case+dec_y,rgba_tie,w_t,h_t); //On affiche le vaisseau ennemi
//    }
}

FVector<int,3> obstacle::getPrincipal(){
    return principal;
}

void obstacle::setPrincipal(FVector<int,3> p){
    principal=p;
}

int obstacle::gettaille(){
    return taille;
}

int obstacle::get_type(){
    return type;
}

void obstacle::set_type(int Type){
    type=Type;
}

void circuit::insert(obstacle &ob, int couche){
    for (int i=0;i<ob.gettaille();i++) {
        FVector<int,3> pix(ob.ob[i].x(),ob.ob[i].y(),couche);
        setPixel(pix,2);
   }
}
