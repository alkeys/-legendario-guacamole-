//
// Created by alex aviles moran  on 26/03/23.
//
#ifndef ESCUDOPRO_UTIL_H
#define ESCUDOPRO_UTIL_H

#endif //ESCUDOPRO_UTIL_H

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
void petalo(int x, int y,float size,float angulo,int estado,float R, float G, float B);
void crearpetalos(int x,int y,float tama,float angulo ,int pos);
void triangulflecha(int x,int y);
void puntosolo(int x,int y,int puntosize,float R, float G, float B);
void dda(float x1, float y1, float x2, float y2,int puntosize, float R, float G, float B);