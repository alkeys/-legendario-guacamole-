//
// Created by alex aviles moran  on 26/03/23.
//
#include <GL/gl.h>
#include <GL/glu.h>
#include <malloc.h>
#include <GL/freeglut_std.h>
#include "math.h"
#include "util.h"
int puntoXcentro;

/**
 *
 * @param x1 cordenada 1
 * @param y1 cordenada 1
 * @param x2 cordenada 2
 * @param y2 cordenada 2
 * @param puntosize tamano de punto
 * @param R color
 * @param G color
 * @param B color
 */
void dda(float x1, float y1, float x2, float y2,int puntosize, float R, float G, float B) {
    /**
     * algoritmo dda echo en c para lineas
     */
    float dx = x2 - x1;
    float dy = y2 - y1;
    float pasos, xIncrementos, yIncrementos, x = x1, y = y1;
    pasos = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
    xIncrementos = dx / pasos;
    yIncrementos = dy / pasos;
    glPointSize(puntosize);
    glBegin(GL_POINTS);
    glColor3f(R, G, B);
    for (float i = 0; i < pasos; i++) {
        glVertex2f(x, y);
        x += xIncrementos;
        y += yIncrementos;
    }
    glEnd();
}


/**
 *
 * @param x cordenada
 * @param y cordenada
 * @param puntosize tamano de punto
 * @param R color
 * @param G color
 * @param B color
 */
void puntosolo(int x,int y,int puntosize,float R, float G, float B){
    glColor3f(R,G,B);
    glPointSize(puntosize);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
}


void triangulflecha(int x,int y){
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(x-10,y);
    glVertex2f(x,y+15);
    glVertex2f(x+10,y);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(x-10,y);
    glVertex2f(x,y+15);
    glVertex2f(x+10,y);
    glEnd();
}



/**
 * @param pos aungolo de reta para el segundo petalo 1 determiando 60 grados
 * @param pos > 1  grados
 * @param anguloGrados en grados normales
 */
void crearpetalos(int x,int y,float tam,float anguloGrados ,int pos){
    float anguloResta,anguloNormal;
    anguloNormal=anguloGrados/(180/M_PI);//se cambia a radianes
     petalo(x,y,tam,-anguloNormal,1,0,1,0);
    if (pos==1){
        petalo(x,y,tam,anguloNormal-M_PI/3,1,0,1,0);
    } else{
        anguloResta= pos/(180/M_PI);
        petalo(x,y,tam,(anguloNormal-anguloResta),1,0,1,0);
    }

    ///funcion espejo par los petalos
    float centro=x-puntoXcentro;
    anguloNormal=90+anguloGrados/(180/M_PI);
    if (pos==1){
        petalo(puntoXcentro-centro,y,tam,-anguloNormal,1,0,1,0);
        petalo(puntoXcentro-centro,y,tam,-anguloNormal+M_PI/3,1,0,1,0);
    } else{
        anguloResta= (pos+65)/(180/M_PI);
        petalo(puntoXcentro-centro,y,tam,anguloNormal,1,0,1,0);
        petalo(puntoXcentro-centro,y,-tam,(anguloNormal+anguloResta),1,0,1,0);
    }

}

/*
 *       float x1,dx,dy,y1;
 *      dx=curva2* cos(angulo)+curva* sin(angulo);
 *      dy=curva* cos(angulo)+curva2* sin(angulo);
 * */
/**
 *
 * @param x cordenada
 * @param y cordenada
 * @param size tamano de petalo
 * @param angulo angulo en radianes
 * @param estado por defecto 1
 * @param R color
 * @param G color
 * @param B color
 */
void petalo(int x, int y,float  size,float angulo,int estado,float R, float G, float B){
    /***
     * para poder lograr rotar las elipce se utilizo el metodo para rotar el plano
     */
    float dx,dy,y1,a,b;
    float r=18;
    a=81;
    b=9;
    glColor3f(R,G,B);
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
        petalo(x,y,size,angulo,-1,R,G,B);
    }
}

/**
 *
 * @param x cordenada
 * @param y cordenada
 * @param orin orinetacion
 */
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

/**
 *
 * @param x cordenada
 * @param y cordenada
 * @param r radio interno
 * @param r2 radio extero
 * @param salto salto de iteracion
 * @param seg segmentos
 * @param R color
 * @param G color
 * @param B color
 */
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

/**
 *
 * @param x cordenada
 * @param y cordenada
 * @param size tamaño
 * @param seg segmentos de divicion
 */
void mediocirculo(int x,int y,int size,int seg){
    glPointSize(7);
    glBegin(GL_POINTS);
    glColor3f(0.11, 0.67, 0.24);
    float radio = size; // Radio del círculo
    puntoXcentro=x;
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

/**
 *
 * @param x cordenada
 * @param y cordenada
 * @param sizevert tamano de picel
 * @param pos pocicion de habertura tanto < 0 = habertura a la izquierda
 *          >0 habertura acia derecha
 * @param size tamano
 * @param caso dos posibles casos 0 y 1 0=habertura vertical 1=havertura horizontal
 * @param R color
 * @param G color
 * @param B color
 */
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

/**
 *
 * @param X cordenada
 * @param Y cordenada
 * @param ori orintacion
 * @param size tamano
 */
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
 * @param x cordenada x
 * @param y cordenada y
 * @param R rojo
 * @param G verde
 * @param B azul
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

/**
 *
 * @param x cordenada centro
 * @param y cordenada centro
 * @param r radio
 * @param R color
 * @param G color
 * @param B color
 */
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
 *
 * @param x cordenada origen
 * @param y cordenada origen
 * @param pos posicion de verticarl > 0 o orizontal < 0
 * @param cantCur cantidad de curvas
 * @param R color
 * @param G color
 * @param B color
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

/**
 *
 * @param x cordenada inicial
 * @param y cordenada inicial
 * @param x2 cordenada final
 * @param yz cordenada final
 * @param R color
 * @param G color
 * @param B color
 */
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

/**
 *
 * @param x vector de cordenadas en x
 * @param y vector de cordenadas en y
 * @param R color
 * @param G color
 * @param B color
 */
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