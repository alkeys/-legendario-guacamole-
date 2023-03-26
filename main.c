#include <stdio.h>
#include <GL/glut.h>
#include "escudopro.h"
int main(int argc,char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(450,200);
    glutInitWindowSize(600,600);
    glutCreateWindow("Escudo");
    configurar();
    glutMouseFunc(mouseEvent);
    glutDisplayFunc(iniciarGrafico);

    glutMainLoop();
    return 0;
}
