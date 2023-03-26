//
// Created by alex aviles moran on 16/03/23.
//
#include <GL/gl.h>
#include <GL/glu.h>
#include "ventanaInicial.h"
#include "util.h"
#include "math.h"

void configurar() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 600, 0, 600);
}

void iniciarGrafico() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.75, 0.76, 0.75, 1);


    ///bandera
    banderasabajo();
    crearbanderas();
    banderaPrincipal();
    //triangulo
    trianguloPrincipal();
    //mar
    mar();
    ///laureles
    laureles();
    //flechas de banderas
    flechascrer();
    //gorro y circulo
    gorroCirculo();
    ///montañas
    montanas();
    //arcoires
    arcoiris();
    //chonga
    //Carnet x= 343  y= 543
     //carnetDibujo(343,543);
    chonga();




    glFlush();
}


void frutos(int x, int y, int x2, int y2, int verHo) {
    int x3 = x - 300;
    int x4 = 300 - x3;
    x3 = x2 - 300;
    int x5 = 300 - x3;
    if(verHo==0){
        dda(x, y, x2, y2, 2, 0, 1, 0);
        crearCirculo(x2, y2, 5, 1, 0, 0);
        dda(x4, y, x5, y2, 2, 0, 1, 0);
        crearCirculo(x5, y2, 5, 1, 0, 0);
    }

    if (verHo > 0) {
        dda(x, y, x2, y2, 2, 0, 1, 0);
        crearCirculo(x2, y2, 5, 1, 0, 0);
        dda(x, y, x2 + 20, y2 - 35, 2, 0, 1, 0);
        crearCirculo(x2 + 20, y2 - 35, 5, 1, 0, 0);
        dda(x4, y, x5, y2, 2, 0, 1, 0);
        crearCirculo(x5, y2, 5, 1, 0, 0);
        dda(x4, y, x5 - 20, y2 - 35, 2, 0, 1, 0);
        crearCirculo(x5 - 20, y2 - 35, 5, 1, 0, 0);
    } else if(verHo<0){
        dda(x, y, x2, y2, 2, 0, 1, 0);
        crearCirculo(x2, y2, 5, 1, 0, 0);
        dda(x, y, x2 + 40, y2, 2, 0, 1, 0);
        crearCirculo(x2 + 40, y2, 5, 1, 0, 0);

        dda(x4, y, x5, y2, 2, 0, 1, 0);
        crearCirculo(x5, y2, 5, 1, 0, 0);
        dda(x4, y, x5 - 40, y2 , 2, 0, 1, 0);
        crearCirculo(x5-40, y2, 5, 1, 0, 0);
    }
}


void banderasabajo() {
    //x= 194  y= 158
    parabola(205, 165, 15, 0.5, 80, 0, 1, 1, 1);
    parabola(205, 150, 15, 0.5, 90, 0, 0, 0, 1);
    parabola(400, 165, 15, 0.5, 80, 0, 1, 1, 1);
    parabola(400, 150, 15, 0.5, 90, 0, 0, 0, 1);
}


void chonga() {
    int a = 0;
    for (int i = -1; i < 2; i += 2) {
        petalo(300, 75, 4.5, i * 2 * M_PI / 9, 1, 0, 0, 1);
        petalo(300, 75, 3.6, i * 2 * M_PI / 9, 1, 0.75, 0.76, 0.75);
        petalo(300, 75, 4.5, i * 3 * M_PI / 4, 1, 0, 0, 1);
        petalo(300, 75, 3.6, i * 3 * M_PI / 4, 1, 0.75, 0.76, 0.75);
    }
    //x= 302  y= 186
    petalo(302,190,4,M_PI/4,1,0,0,1);
    petalo(302,190,-4,-M_PI/4,1,0,0,1);
}


void laureles() {
    //laureles
    mediocirculo(300, 350, 275, 4);

    crearpetalos(368, 83, 4, 75, 1);//75 grados
    crearpetalos(368, 83, 4, 60, 1);//60 grados
    crearpetalos(368, 83, 4, 45, 1);//45 grados

    crearpetalos(463, 132, 3.5, 75, 1);//75 grados
    crearpetalos(463, 132, 3.5, 45, 1);// 45 grados

    crearpetalos(535, 209, 3.5, 100, 150);//110 grados y resta 150 grados segundo petalo
    crearpetalos(535, 209, 3.5, 115, 150);//120 grados y resta 150 grados segundo petalo
    //x= 566  y= 283
    crearpetalos(566, 283, 3, 110, 180);//110 grados y resta 180 grados segundo petalo
    crearpetalos(566, 283, 3, 125, 180);//125 grados y resta 180 grados segundo petalo
    //x= 573  y= 368
    crearpetalos(573, 368, 3, 120, 195);//120 grados y resta 195 grados segundo petalo
    crearpetalos(573, 368, 3, 135, 195);//135 grados y resta 195 grados segundo petalo
    //x= 557  y= 447
    crearpetalos(557, 447, 3, 130, 200);//120 grados y resta 195 grados segundo petalo
    crearpetalos(557, 447, 3, 145, 200);//135 grados y resta 195 grados segundo petalo
    //x= 515  y= 522
    crearpetalos(515, 522, 3, 150, 230);//120 grados y resta 195 grados segundo petalo
    crearpetalos(515, 522, 3, 180, 230);//135 grados y resta 195 grados segundo petalo
//x= 441  y= 114 x= 440  y= 137
//x= 518  y= 186 x= 512  y= 205
//x= 563  y= 267 x= 545  y= 276
//x= 575  y= 350 x= 558  y= 362
//x= 565  y= 427 x= 543  y= 436
//x= 529  y= 501 x= 509  y= 506
//x= 495  y= 546 x= 480  y= 565
    frutos(441, 114, 440, 137, 1);
    frutos(518, 186, 512, 205, 1);
    frutos(563, 267, 545, 276, -1);
    frutos(575, 350, 558, 362, -1);
    frutos(565, 427, 543, 436, -1);
    frutos(529, 501, 509, 506, -1);
    frutos(495,546,480,565,0);

}

void mar() {
    int x[4];
    int y[4];
    x[0] = 125;
    y[0] = 211;
    x[1] = 475;
    y[1] = 211;
    x[2] = 432;
    y[2] = 275;
    x[3] = 170;
    y[3] = 275;
    rectangulo(x, y, 0.1, 0.26, 0.98);
    grafisin(175, 245, 1, 2, 0, 0, 0);
    grafisin(155, 240, 1, 8, 1, 1, 1);
    grafisin(160, 235, 1, 8, 1, 1, 1);
    grafisin(150, 232, 1, 2, 1, 1, 1);
    grafisin(150, 225, 1, 8, 0, 0, 0);
    grafisin(150, 220, 1, 8, 1, 1, 1);
}

void trianguloPrincipal() {
    triangulo(100, 198, 500, 505, 0, 0, 0);
    triangulo(105, 200, 495, 500, 1, 1, 0);
    triangulo(120, 209, 481, 472, 0, 0, 0);
    triangulo(125, 210, 475, 470, 0.88, 0.89, 0.89);
}

void flechascrer() {
    flechas(360, 410, 1, 80);
    flechas(430, 300, 1, 80);
    flechas(240, 410, -1, 80);
    flechas(170, 300, -1, 80);
    // flechas(298, 500, 0, 80);
}

void crearbanderas() {
    banderas(417, 380, 1);
    banderas(182, 380, -1);

}

void banderaPrincipal() {
    flechas(298, 500, 0, 80);
    parabola(301, 515, 15, -0.1, 50, 1, 0, 0, 1);
    //x= 274  y= 516
    parabola(266, 515, 15, 0.5, 57, 1, 0, 0, 1);
    parabola(295, 516, 25, -0.3, 29, 1, 0, 0, 1);
    triangulflecha(295, 579);
    //x= 277  y= 516
    puntosolo(277, 516, 25, 0, 0, 1);
    //x= 293  y= 509
    parabola(280, 509, 10, 0.3, 60, 1, 1, 1, 1);

}

void gorroCirculo() {
    circuloconlineas(297, 360, 20, 40, 15, 1, 1, 0, 0);
    circuloconlineas(300, 370, 40, 50, 25, 2, 0, 0, 0);
    circuloconlineas(300, 370, 45, 60, 30, -2, 0, 0, 0);
    crearCirculo(297, 360, 20, 1, 1, 1);
    flechas(295, 300, 0, 60);
    //x= 297  y= 359
    mountcrear(297,355,20,1,0,0);
}

void montanas() {
    mountcrear(390, 240, 50, 0.2, 0.78, 0.29);
    mountcrear(355, 235, 60, 0.2, 0.78, 0.29);
    mountcrear(320, 230, 70, 0.2, 0.78, 0.29);
    mountcrear(285, 225, 80, 0.2, 0.78, 0.29);
    mountcrear(251, 220, 90, 0.2, 0.78, 0.29);
}

void arcoiris() {
    parabola(300, 460, 4, -0.5, 8, 0, 1, 0, 0);
    parabola(300, 455, 4, -0.3, 11, 0, 1, 0.63, 0.18);
    parabola(300, 450, 4, -0.3, 14, 0, 1, 1, 0);
    parabola(300, 445, 4, -0.2, 19, 0, 0.02, 0.69, 0.93);
    parabola(300, 440, 4, -0.2, 19, 0, 0, 0.13, 1);
}


void carnetDibujo(float x, float y) {
    //la altura sera de 15pix max
    //leta A
    int tama = 3;
    dda(x, y, x + 5, y + 15, tama, 0, 0, 0);
    dda(x + 5, y + 15, x + 10, y, tama, 0, 0, 0);
    dda(x + 2.5, y + 7.5, x + 8.5, y + 7, tama, 0, 0, 0);
    //
    //letra m
    x += 15;
    dda(x, y, x + 5, y + 15, tama, 0, 0, 0);
    dda(x + 5, y + 15, x + 10, y + 7, tama, 0, 0, 0);
    dda(x + 10, y + 7, x + 15, y + 15, tama, 0, 0, 0);
    dda(x + 15, y + 15, x + 20, y, tama, 0, 0, 0);
    //
    //uno
    x += 30;
    dda(x, y, x, y + 15, tama, 0, 0, 0);
    dda(x - 5, y, x + 5, y, tama, 0, 0, 0);
    dda(x - 5, y + 7, x, y + 15, tama, 0, 0, 0);
    //
    //ocho
    x += 10;
    dda(x, y, x, y + 15, tama, 0, 0, 0);
    dda(x, y + 15, x + 10, y + 15, tama, 0, 0, 0);
    dda(x, y, x + 10, y, tama, 0, 0, 0);
    dda(x, y + 7, x + 10, y + 7, tama, 0, 0, 0);
    dda(x + 10, y, x + 10, y + 15, tama, 0, 0, 0);
    //
    //cero
    x += 15;
    dda(x, y, x, y + 15, tama, 0, 0, 0);
    dda(x, y + 15, x + 10, y + 15, tama, 0, 0, 0);
    dda(x, y, x + 10, y, tama, 0, 0, 0);
    dda(x + 10, y, x + 10, y + 15, tama, 0, 0, 0);
    //
    //cero
    x += 15;
    dda(x, y, x, y + 15, tama, 0, 0, 0);
    dda(x, y + 15, x + 10, y + 15, tama, 0, 0, 0);
    dda(x, y, x + 10, y, tama, 0, 0, 0);
    dda(x + 10, y, x + 10, y + 15, tama, 0, 0, 0);
    //
    //siete
    x += 20;
    dda(x, y, x, y + 15, tama, 0, 0, 0);
    dda(x - 5, y + 12, x, y + 15, tama, 0, 0, 0);
    dda(x - 5, y + 7, x + 5, y + 7, tama, 0, 0, 0);
    //
}