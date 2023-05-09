/*  
    Programa que divide a tela em 4 viewports e realiza diferentes ações em cada uma com uso do Ortho2D: 
    - 1ª Tela (Superior esquerda: Triangulo estático)
    - 2ª Tela (Superior direita: Triângulo se move na horizontal)
    - 3ª Tela (Inferior esquerda: Triangulo se move na vertical)
    - 4ª Tela (Inferior ddireita: Efeito de zoom in e zoom out no triângulo)
*/
#include <windows.h>
#include <iostream>
#include <math.h>
#include "glut.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void myInit(void);
void myDisplay(void);
void idleFunc();

GLfloat k = -100.0f;
GLfloat k_step = 1.0f;
GLfloat zoom = 3.0f;
boolean zoomOut = false;

// g++ -o Ativ5 -Wall main.cpp -mwindows glut32.lib -lopengl32 -lglu32
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(150, 150);
    glutCreateWindow("Atividade 5 by Pedro Garbossa");
    
    myInit();
    
    glutDisplayFunc(myDisplay);
    glutIdleFunc(idleFunc);

    glutMainLoop();
}


void myInit(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
}


void drawObject(){
    glBegin(GL_TRIANGLES);
        glVertex2i(0, 50);
        glVertex2i(50, -50);
        glVertex2i(-50, -50);
    glEnd();
}

void drawOutline(){
    glBegin(GL_LINE_LOOP);
        glVertex2f(-100, 100);
        glVertex2f(100, 100);
        glVertex2f(100, -100);
        glVertex2f(-100, -100);
    glEnd();
}

void idleFunc(){
    if(k > 100 || k < -300)
        k_step = -k_step;
    
    k += k_step;

    if(zoomOut)
        zoom+=0.5f;
    else
        zoom-=0.5f;

    if(zoom > 3.0f)
        zoomOut = false;
    
    if(zoom < -3.0f)
        zoomOut = true;

    glutPostRedisplay();
       
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT); //desenha o fundo (limpa a janela)
    
    glMatrixMode(GL_PROJECTION);
    
    //1a janela
    glLoadIdentity();
    gluOrtho2D(-100.0f, 100.0f, -100.0f, 100.0f);
    glViewport(0, 300, 300, 300);
    glColor3f(1.0f, 0.0f, 0.0f);
    drawObject();
    
    //2a janela
    //movimentar a janela de recorte em x (movimentar camera)
    glLoadIdentity();
    gluOrtho2D(k, k+200.0f, -100.0f, 100.0f);
    glViewport (300, 300, 300, 300);
    glColor3f (0.0f, 1.0f, 0.0f);
    drawObject();

    //3a janela
    glLoadIdentity();
    gluOrtho2D(-100, 100, k, k+200);
    glViewport (0, 0, 300, 300);
    glColor3f (0.0f, 0.0f, 1.0f);
    drawObject();

    //4a janela
    //fazendo a janela ser menor do que é a figura vai ficar grande (zoom-in)
    //fazendo a janela ficar maior do que é, a figura vai ficar menor (zoom-out)
    glLoadIdentity();
    gluOrtho2D(-100.0f*zoom, 100.0f*zoom, -100.0f*zoom, 100.0f*zoom);
    glViewport (300, 0, 300, 300);
    glColor3f (0.0f, 0.0f, 0.0f);
    drawObject();

    glutSwapBuffers(); 
}