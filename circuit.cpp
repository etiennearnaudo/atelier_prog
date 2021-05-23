#include "circuit.h"
#include "outils.h"

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
    return(y*W+x+W*H*z);
}

circuit::circuit(int w, int h, int d){
    tunnel = new int[w*h*d];
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

circuit::~circuit(){
    delete[] tunnel;
}

void circuit::setPixel(pixel p,int value){
    tunnel[p.indice(width,heigth)] = value;
}

void circuit::affiche(int z,int size,int dec_x,int dec_y){
    pixel p;
    p.setz(z);
     for (int i=0;i<width;i++) for (int j=0;j<heigth;j++) {
         p.setx(i);
         p.sety(j);
         if(tunnel[p.indice(width,heigth)]==1) fillRect(p.getx()*size+dec_x,p.gety()*size+dec_y,size,size,BLACK);
         else if(tunnel[p.indice(width,heigth)]==2) fillRect(p.getx()*size+dec_x,p.gety()*size+dec_y,size,size,BLUE);
     }
}

void circuit::affiche(int z){
    fillRect(0,0,width*taille_case,heigth*taille_case,WHITE);
    affiche(z,taille_case,0,0);
    affiche(z+1,taille_case-1,1*(width/2),1*((heigth/2)-3));
    affiche(z+2,taille_case-2,2*(width/2),2*((heigth/2)-3));
    affiche(z+3,taille_case-3,3*(width/2),3*((heigth/2)-3));
    affiche(z+4,taille_case-4,4*(width/2),4*((heigth/2)-3));
    affiche(z+5,taille_case-5,5*(width/2),5*((heigth/2)-3));
}

int circuit::getPixel(pixel p){
    return tunnel[p.indice(width,heigth)];
}

obstacle::obstacle(int w,int h,int z){
    int n=Random(0,1);
    pixel pix(0,0,z);
    if (n==0){
        taille = (w/2)+(w/2)*(h-2);
        ob = new pixel[taille];
        for (int i=1;i<w/2;i++) for (int j=1;j<h-1;j++) {
            pix.setx(i);
            pix.sety(j);
            ob[i+(w/2)*j]=pix;
        }
    }
    if (n==1){
        taille = (w-1)+w*(h/2-1);
        ob = new pixel[taille];
        for (int i=1;i<w-1;i++) for (int j=1;j<h/2;j++) {
            pix.setx(i);
            pix.sety(j);
            ob[i+w*j]=pix;
       }
    }
    principal = pixel(0,0,0);
}

obstacle::~obstacle(){
    delete[] ob;
}


void obstacle::insert(circuit c){
    for (int i=0;i<taille;i++) c.setPixel(ob[i],2);
}

int obstacle::gettaille(){
    return taille;
}












