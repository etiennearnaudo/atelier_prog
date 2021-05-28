#include "circuit.h"

pixel::pixel(){
    x=0;
    y=0;
}

pixel::pixel(int x0, int y0,int z0){
    x=x0;
    y=y0;
    z=z0;
}

pixel::~pixel(){}

int pixel::getx(){
    return x;
}

int pixel::gety(){
    return y;
}

int pixel::getz(){
    return z;
}

void pixel::setx(int x0){
    x=x0;
}

void pixel::sety(int y0){
    y=y0;
}

void pixel::setz(int z0){
    z=z0;
}

int pixel::indice(int W,int H){
    return(x+y*W+W*H*z);
}

circuit::circuit(int w, int h, int d){
    width = w;
    heigth = h;
    depth = d;
    pixel p;
    for (int k=0;k<depth;k++){
        p.setz(k);
        for (int i=0;i<width;i++){
            p.setx(i);
            for (int j=1;j<heigth-1;j++){
                p.sety(j);
                tunnel[p.indice(width,heigth)] = 0;
            }
            p.sety(0);
            tunnel[p.indice(width,heigth)] = 1;
            p.sety(heigth-1);
            tunnel[p.indice(width,heigth)] = 1;
        }
        for (int i=1;i<heigth-1;i++){
            p.sety(i);
            for (int j=1;j<width-1;j++){
                p.setx(j);
                tunnel[p.indice(width,heigth)] = 0;
            }
            p.setx(0);
            tunnel[p.indice(width,heigth)] = 1;
            p.setx(width-1);
            tunnel[p.indice(width,heigth)] = 1;
        }
    }
    openWindow(width*taille_case,heigth*taille_case);
}

circuit::~circuit(){}

void circuit::setPixel(pixel p,int value){
    cout <<"taille_circuit = "<<width*heigth*depth<<endl;
    cout << p.indice(width,heigth) << endl;
    int m=0;
    cout <<"m = "<< m << endl;
    m=tunnel[p.indice(width,heigth)];
    cout << m << endl;
    cout << tunnel[p.indice(width,heigth)] << endl;
    tunnel[p.indice(width,heigth)] = value;
    cout << "fait    " << tunnel[p.indice(width,heigth)] <<endl;
}

void circuit::affiche(int z,int size,int dec_x,int dec_y){
    pixel p;
    p.setz(z);
    int compteur=0;
    for (int i=0;i<width;i++) for (int j=0;j<heigth;j++) {
        p.setx(i);
        p.sety(j);
        if(tunnel[p.indice(width,heigth)]==2) compteur+=1;
        if(tunnel[p.indice(width,heigth)]==1) fillRect(p.getx()*size+dec_x,p.gety()*size+dec_y,size,size,BLACK);
        else if(tunnel[p.indice(width,heigth)]==2) fillRect(p.getx()*size+dec_x,p.gety()*size+dec_y,size,size,BLUE);
    }
    cout <<"compteur = "<< compteur<< endl;
}

void circuit::affiche(int z){
    fillRect(0,0,width*taille_case,heigth*taille_case,WHITE);
    affiche(z,taille_case,0,0);
    affiche(z+1,taille_case-1,1*(width/2),1*((heigth/2)+3));
    affiche(z+2,taille_case-2,2*(width/2),2*((heigth/2)+3));
    affiche(z+3,taille_case-3,3*(width/2),3*((heigth/2)+3));
    affiche(z+4,taille_case-4,4*(width/2),4*((heigth/2)+3));
    affiche(z+5,taille_case-5,5*(width/2),5*((heigth/2)+3));
}

int circuit::getPixel(pixel p){
    return tunnel[p.indice(width,heigth)];
}

obstacle::obstacle(int w,int h,int z){
    int n=Random(2,2);
    pixel pix(0,0,z);
    if (n==0){
        taille = ((w/2)-1)*(h-2);
        ob = new pixel[taille];
        for (int i=1;i<w/2;i++) for (int j=1;j<h-1;j++) {
            pix.setx(i);
            pix.sety(j);
            ob[i+((w/2)-1)*j]=pix;
        }
    }
    if (n==1){
        taille = (w-2)*((h/2)-1);
        ob = new pixel[taille];
        for (int i=1;i<w-1;i++) for (int j=1;j<h/2;j++) {
            pix.setx(i);
            pix.sety(j);
            ob[i+(w-2)*j]=pix;
       }
    }
    if(n==2){
        taille = 3*(w-2);
        ob = new pixel[taille];
        for (int i=0;i<w-2;i++) for (int j=0;j<3;j++){
            pix.setx(i+1);
            pix.sety((h/2)+j);
            ob[i+(w-2)*j]=pix;
        }
    }
    cout <<"obstacle = "<< n << endl;
    principal = pixel(0,0,0);
}

obstacle::~obstacle(){
    delete[] ob;
}


void obstacle::insert(circuit &c){
    cout << taille <<endl;
    pixel pix;
    for (int i=0;i<taille;i++) {
        pix=ob[i];
        cout << 12 << endl;
        cout << pix.indice(largeur,hauteur) << endl;
        cout << largeur*hauteur*profondeur << endl;
        c.setPixel(pix,2);
        cout << pix.getx() <<"   "<<pix.gety()<<"   "<<pix.getz()<< endl;
   }
}

int obstacle::gettaille(){
    return taille;
}












