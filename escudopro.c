//
// Created by alex aviles moran on 16/03/23.
//
#include <GL/gl.h>
#include <GL/glu.h>
#include <malloc.h>
#include <GL/freeglut_std.h>
#include "escudopro.h"
#include "math.h"

void parabola(int x,int y,float sizevert,float pos,int size,int caso,float R, float G, float B);
void crearCirculo(int x, int y, int r, float R, float G, float B);
void triangulo(int x, int y, int x2, int yz, float R, float G, float B);
void rectangulo(int x[4], int y[4], float R, float G, float B);
void grafisin(int x, int y, int pos, float cantCur, float R, float G, float B);
void punto(int x, int y, int ir, int iy, float R, float G, float B);
void flechas(int X,int Y,int ori,int size);
void mountcrear(int x,int y,int l, float R, float G, float B);
void mediocirculo(int x,int y,int size,int seg);
void circuloconlineas(int x, int y, int r,int r2,int salto,int seg,float R, float G, float B);
void banderas(int x,int y,int orin);
void petalo(int x, int y,float size,float angulo,int estado);
void crearpetalos(int x,int y,float tama,float angulo ,int pos);
void laureles();

void configurar() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 600, 0, 600);
}
void iniciarGrafico() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.75, 0.76, 0.75, 1);

////triangulo

  triangulo(100, 198, 500, 505, 0, 0, 0);
   triangulo(105, 200, 495, 500, 1, 1, 0);
   triangulo(120, 209, 481, 472, 0, 0, 0);
   triangulo(125, 210, 475, 470, 0.88, 0.89, 0.89);
/////
//mar
    int x[4];     int y[4];
    x[0] = 125;    y[0] = 211;
    x[1] = 475;    y[1] = 211;
    x[2] = 432;    y[2] = 275;
    x[3] = 170;    y[3] = 275;
    rectangulo(x,y,0.1, 0.26, 0.98);
    grafisin(175,245,1,2,0,0,0);
    grafisin(155,240,1,8,1,1,1);
    grafisin(160,235,1,8,1,1,1);
    grafisin(150,232,1,2,1,1,1);
    grafisin(150,225,1,8,0,0,0);
    grafisin(150,220,1,8,1,1,1);
    //flechas de banderas
    flechas(360,410,1,80);
    flechas(430,300,1,80);
    flechas(240,410,-1,80);
    flechas(170,300,-1,80);
    flechas(298,500,0,80);
    ///laureles
    laureles();
    ///banderas
    banderas(417,380,1);
    banderas(182,380,-1);
    //gorro y circulo
    circuloconlineas(297,360,20,40,15,1,1,0,0);
    circuloconlineas(300,370,40,50,25,2,0,0,0);
    circuloconlineas(300,370,45,60,30,-2,0,0,0);
    crearCirculo(297,360,20,1,1,1);
    flechas(295,300,0,60);
    ///montañas
    mountcrear(390,240,50,0.2, 0.78, 0.29);
    mountcrear(355,235,60,0.2, 0.78, 0.29);
    mountcrear(320,230,70,0.2, 0.78, 0.29);
    mountcrear(285,225,80,0.2, 0.78, 0.29);
    mountcrear(251,220,90,0.2, 0.78, 0.29);

    //arcoires
    parabola(300,460,4,-0.5,8,0,1,0,0);
    parabola(300,455,4,-0.3,11,0,1, 0.63, 0.18);
    parabola(300,450,4,-0.3,14,0,1, 1, 0);
    parabola(300,445,4,-0.2,19,0,0.02, 0.69, 0.93);
    parabola(300,440,4,-0.2,19,0,0, 0.13, 1);
     glFlush();
}

void laureles(){
    //laureles
    mediocirculo(300,350,275,4);
    crearpetalos(368,83,4,75,1);//75 grados
    crearpetalos(368,83,4,60,1);//60 grados
    crearpetalos(368,83,4,45,1);//45 grados

    crearpetalos(463,132,3.5,75,1);//75 grados
    crearpetalos(463,132,3.5,45,1);// 45 grados

    crearpetalos(535,209,3.5,100,150);//110 grados y resta 150 grados segundo petalo
    crearpetalos(535,209,3.5,115,150);//120 grados y resta 150 grados segundo petalo
    //x= 566  y= 283
    crearpetalos(566,283,3,110,180);//110 grados y resta 180 grados segundo petalo
    crearpetalos(566,283,3,125,180);//125 grados y resta 180 grados segundo petalo
    //x= 573  y= 368
    crearpetalos(573,368,3,120,195);//120 grados y resta 195 grados segundo petalo
    crearpetalos(573,368,3,135,195);//135 grados y resta 195 grados segundo petalo
    //x= 557  y= 447
    crearpetalos(557,447,3,130,200);//120 grados y resta 195 grados segundo petalo
    crearpetalos(557,447,3,145,200);//135 grados y resta 195 grados segundo petalo
    //x= 515  y= 522
    crearpetalos(515,522,3,150,230);//120 grados y resta 195 grados segundo petalo
    crearpetalos(515,522,3,180,230);//135 grados y resta 195 grados segundo petalo
}

/**
 * @param pos aungolo de reta para el segundo petalo 1 determiando 60 grados
 * @param pos>1 grados
 */
void crearpetalos(int x,int y,float tam,float anguloGrados ,int pos){
    float anguloResta,anguloNormal;
    anguloNormal=anguloGrados/(180/M_PI);
    petalo(x,y,tam,-anguloNormal,1);
    if (pos==1){
        petalo(x,y,tam,anguloNormal-M_PI/3,1);
    } else{
        anguloResta= pos/(180/M_PI);
        petalo(x,y,tam,(anguloNormal-anguloResta),1);
    }
}

/*
 *       float x1,dx,dy,y1;
 *      dx=curva2* cos(angulo)+curva* sin(angulo);
 *      dy=curva* cos(angulo)+curva2* sin(angulo);
 * */
/**
 * @param estado por defecto 1
 */
void petalo(int x, int y,float  size,float angulo,int estado){
    /***
     * para poder lograr rotar las elipce se utilizo el metodo para rotar el plano
     */
    float dx,dy,y1,a,b;
    float r=18;
    a=81;
    b=9;
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for (float i = 0; i <= r; i+=0.01) {
        y1= estado*sqrt(b -((pow((i-9),2))*b)/a);
        dx=i* cos(angulo)+y1* sin(angulo);//rotar plano
        dy=-i*sin(angulo)+y1*cos(angulo);//rotar plano

        if (estado<0){
            glVertex2f(x+dx*size,y+dy*size);
        } else{
            glVertex2f(x+dx*size,y+dy*size);
        }
    }
    glEnd();
    //sobreado
    glColor3f(0,0,0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(x,y);
    for (float i = 0; i <= r; i++) {
        y1= estado*sqrt(b -((pow((i-9),2))*b)/a);
        dx=i* cos(angulo)+y1* sin(angulo);
        dy=-i*sin(angulo)+y1*cos(angulo);

        if (estado<0){
            glVertex2f(x+dx*size,y+dy*size);
        } else{
            glVertex2f(x+dx*size,y+dy*size);
        }
    }
    glEnd();
    if(estado<0){
        return;
    } else{
     petalo(x,y,size,angulo,-1);
    }
}

void banderas(int x,int y,int orin){
    //x= 470  y= 124 x= 432  y= 298 x= 367  y= 197
    //417,380,1,50
    parabola(x+53*orin,398,9,-0.1*orin,68,1,0,0,1);
    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
    glVertex2f(x+49*orin,478);
    glVertex2f(x+48*orin,326);
    glVertex2f(x+15*orin,300);
    glVertex2f(x-53*orin,403);
    glEnd();
    //parte blanca arriba
    //417,380,1,50
    //x= 424  y= 155 x= 431  y= 299 x= 395  y= 242 x= 397  y= 174
   glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(x+7*orin,445);
    glVertex2f(x+14*orin,301);
    glVertex2f(x-22*orin,358);
    glVertex2f(x-20*orin,426);
    glEnd();
    parabola(x+15*orin,378,5,-0.1*orin,65,1,1,1,1);
    parabola(x+7*orin,390,16,0,30,1,1,1,1);
   //banderas de abajo
    glColor3f(0,0,1);
     glBegin(GL_POLYGON);
     //417,380,1,50
     //x= 539  y= 231 x= 498  y= 401 x= 438  y= 308
    glVertex2f(x+122*orin,369);
    glVertex2f(x+81*orin,199);
    glVertex2f(x+21*orin,294);
    glEnd();
    ////417,380,1,50
    ///x= 493  y= 269 /x= 495  y= 398 /x= 462  y= 347 /x= 468  y= 286
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(x+76*orin,334);
    glVertex2f(x+76*orin,202);
    glVertex2f(x+45*orin,250);
    glVertex2f(x+48*orin,317);
    glEnd();
    parabola(x+80*orin,269,5,-0.1*orin,50,1,1,1,1);
    parabola(x+75*orin,269,5,0,53,1,1,1,1);
    ///x= 468  y= 289 x= 461  y= 346 x= 465  y= 313
    parabola(x+50*orin,285,4,-0.1*orin,26,1,1,1,1);

}

void mouseEvent(int boton, int estado, int x, int y) {
    if (boton == GLUT_LEFT_BUTTON && estado == GLUT_DOWN) {
        printf("x= %i  y= %i ",x,(600-y));
        glFlush();
    }

}

void circuloconlineas(int x, int y, int r,int r2,int salto, int seg,float R, float G, float B){
    //formula x2+y2=r2
    //y=sqrt(r2-x2)
    double margenRadio, x2, y2,x3,y3;
    glColor3f(R,G,B);
    glBegin(GL_LINES);
    for (float i = 0; i < 365; i+=salto) {
        float angulo =  i * (M_PI / (180*seg));
        x2 =r * cos(angulo);
        y2 =r * sin( angulo);
        x3 = r2 * cos( angulo);
        y3 =r2 * sin( angulo);
        glVertex2f(x+x2,y+y2);
        glVertex2f(x+x3,y+y3);
    }
    glEnd();
}

void mediocirculo(int x,int y,int size,int seg){
    glPointSize(7);
    glBegin(GL_POINTS);
    glColor3f(0.11, 0.67, 0.24);
    float radio = size; // Radio del círculo
    int num_segmentos =365; // Número de segmentos para aproximar el círculo
    for(int i=0; i<=num_segmentos; i++) {
        float angulo = i * (M_PI / (num_segmentos*seg)); // Ángulo del segmento actual
        float fx = radio * cos(angulo); // Coordenada x del vértice actual
        float fy = radio * sin(angulo); // Coordenada y del vértice actual
        glVertex2f(x+fx, y+fy);
        glVertex2f(x-fx, y+fy);
        glVertex2f(x+fx, y-fy);
        glVertex2f(x-fx, y-fy);
        glVertex2f(x+fy, y-fx);
        glVertex2f(x-fy, y-fx);
    }
    glEnd();
}

void parabola(int x,int y,float sizevert,float pos,int size,int caso,float R, float G, float B){
    glPointSize(sizevert);
    glBegin(GL_POINTS);
    glColor3f(R,G,B);
    switch (caso) {
        case 0:
            for(float x1=-size; x1<=size; x1+=0.01) {
                float y1 = pos*x1*x1/size;
                glVertex2f(x+x1, y+y1);
            }
            break;
        case 1:
            for(float x1=-size; x1<=size; x1+=0.1) {
                float y1 = pos*x1*x1/size;
                glVertex2f(x+y1, y+x1);
            }

            break;
    }
    glEnd();
}

void flechas(int X,int Y,int ori,int size){
        int x[4];     int y[4];
        if(ori>0){
            //x= 463  y= 105 x= 475  y= 123 x= 483  y= 103 flecha
            //360 410
            x[0] = X;        y[0] = Y;
            x[1] = X+110;    y[1] = Y+size;
            x[2] = X+110;    y[2] = Y+size-10;
            x[3] = X;        y[3] = Y-10;
            rectangulo(x,y,1,1,0);
        } else if (ori<0){
            x[0] = X;        y[0] = Y;
            x[1] = X-110;    y[1] = Y+size;
            x[2] = X-110;    y[2] = Y+size-10;
            x[3] = X;        y[3] = Y-10;
            rectangulo(x,y,1,1,0);
        }
        if(ori==0){
        x[0] = X;      y[0] = Y;
        x[1] = X;      y[1] = Y+size;
        x[2] = X+5;    y[2] = Y+size;
        x[3] = X+5;    y[3] = Y;
        rectangulo(x,y,1,1,0);
        }
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(X+104*ori,Y+79);
    glVertex2f(X+130*ori,Y+89);
    glVertex2f(X+116*ori,Y+65);
    glEnd();


}

/**
 * @param l tamaño de la montaña
 */
void mountcrear(int x,int y,int l, float R, float G, float B){
    /**
     * funcion de campana de gauss
     *e^-x^2
     * se modifico con algunos argumento para asi poder agrandar la campana
     */
    float y2=0;
    int h=(l*35)/100;
    glBegin(GL_POLYGON);
    glColor3f(R,G,B);
    glVertex2f(x-l,y+h);
    for (float i = -l; i < l; i+=1) {
        y2= l*exp(-pow(i/l,2));
        glVertex2f(x+i,y+y2);
    }
    glVertex2f(x+l,y+h);
    glEnd();
    /*
     * borde negro para diferenciar la campana
     */
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex2f(x-l,y+h);
    for (float i = -l; i < l; i+=1) {
        y2= l*exp(-pow(i/l,2));
        glVertex2f(x+i,y+y2);
    }
    glVertex2f(x+l,y+h);
    glEnd();
}

void crearCirculo(int x, int y, int r, float R, float G, float B) {
    //formula x2+y2=r2
    //y=sqrt(r2-x2)
    double margenRadio, x2, y2;
    float abancePixel = 0.01;
    for (float i = 0; i < 365; i+=0.1) {
        float angulo =  i * (M_PI / (180/4));
        x2 =r * cos(angulo);
        y2 =r * sin( angulo);
        punto(x, y, x2, y2, R, G, B);
    }
}

void punto(int x, int y, int ir, int iy, float R, float G, float B) {
    glBegin(GL_POLYGON);
    glColor3f(R, G, B);
    glVertex2f(x + ir, y + iy);
    glVertex2f(x - ir, y + iy);
    glVertex2f(x - ir, y - iy);
    glVertex2f(x + ir, y - iy);
    glEnd();
}
/**
 * @param pos posicion de verticarl > 0 o orizontal < 0
 * @param cantLineas
 */
void grafisin(int x, int y, int pos, float cantCur, float R, float G, float B) {
    int xAux = x;
    double curva;
    double curva2;
    glBegin(GL_LINE_STRIP);
    glColor3f(R,G,B);
    for (float x1 = -1.0f; x1 < cantCur * 6; x1 += 0.9) {
        curva = y + sin(2 * M_PI * x + x1) *4 ;
        curva2 = x + x1 * 6 ;
        if (pos < 0) {
           glVertex2f(curva,curva2);
            //crearCirculo(curva, curva2, 5, R, G, B);
        } else {
            glVertex2f(curva2,curva);
          // crearCirculo(curva2, curva, 4, R, G, B);
        }
    }
    glEnd();
}

void triangulo(int x, int y, int x2, int yz, float R, float G, float B) {
    /**
     * la funci se aumente por 50 por cada l
     */
    glColor3f(R, G, B);
    glBegin(GL_TRIANGLES);
    glVertex2f(x, y);
    glVertex2f((x + x2) / 2, yz);
    glVertex2f(x2, y);
    glEnd();
    glColor3f(R, G, B);

}

void rectangulo(int x[4], int y[4], float R, float G, float B) {
/* pos
 * 0  x1  y1
 * 1  x2  y2
 * 2  x2  y3
 * 3  x3  y4
 */
    glColor3f(R, G, B);
    glBegin(GL_POLYGON);
    glVertex2f(x[0], y[0]);
    glVertex2f(x[1], y[1]);
    glVertex2f(x[2], y[2]);
    glVertex2f(x[3], y[3]);
    glEnd();
    glColor3f(0, 0, 0);
    //bordes
    glBegin(GL_LINES);
    glVertex2f(x[0], y[0]);
    glVertex2f(x[1], y[1]);
    glVertex2f(x[2], y[2]);
    glVertex2f(x[3], y[3]);
    glEnd();
}