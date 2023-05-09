/*  
    Programa simples que faz o desenho de uma casa: 
    - Casa quadrada, com telhado trianguloar, com uma porta, uma janela e uma chaminé
*/
#include <windows.h>
#include <math.h>
#include "glut.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void myInit(void);
void myDisplay(void);

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(150, 150);
    glutCreateWindow("Atividade da Casa by Pedro Garbossa");
    
    myInit();
    glutDisplayFunc(myDisplay);

    glutMainLoop();
}


void myInit(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
}

void desenhaCasa()
{
    //Desenho da casa
    glColor3f(1.0, 1.0, 0.0); //cor amarela para casa
    glBegin(GL_QUADS);
        glVertex2f(-0.3f, -0.3f);
        glVertex2f(0.3f, -0.3f);
        glVertex2f(0.3f, 0.3f);
        glVertex2f(-0.3f, 0.3f);
    glEnd();

    //Desenho da chaminé
    glColor3f(0.7f, 0.1f, 0.1f);//cor vermelha para a chaminé
    glBegin(GL_QUADS);
        glVertex2f(-0.3f, 0.3f);
        glVertex2f(-0.2f, 0.3f);
        glVertex2f(-0.2f, 0.6f);
        glVertex2f(-0.3f, 0.6f);
    glEnd();

    //Desenho da porta
    glColor3f (0.0f, 1.0f, 1.0f);//cor azul para a porta e a janela
    glBegin(GL_QUADS);
        glVertex2f(-0.08f, -0.3f);
        glVertex2f(0.08f, -0.3f);
        glVertex2f(0.08f, 0.02f);
        glVertex2f(-0.08f, 0.02f);
    glEnd();

    //Desenho da janela
    glBegin(GL_QUADS);
        glVertex2f(0.15f, -0.1f);
        glVertex2f(0.25f, -0.1f);
        glVertex2f(0.25f, 0.1f);
        glVertex2f(0.15f, 0.1f);
    glEnd();

    //Desenho do telhado
    glColor3f(0.7f, 0.4f, 0.1f);//Cor marrom para telhado
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, 0.25f);
        glVertex2f(0.5f, 0.25f);
        glVertex2f(0.0f, 0.6f);
    glEnd();
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -1.0f);
    desenhaCasa();

    glutSwapBuffers();
}