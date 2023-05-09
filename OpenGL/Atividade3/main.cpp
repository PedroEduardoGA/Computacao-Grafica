/*  
    Programa que oferece uma tela para ser desenhada, tem integração com o mouse: 
    - Botão esquerdo: Desenha traçado
    - Botão direito: Abre menu (possui 2 submenus: Cor e Grossura do traçado)
*/
#include <windows.h>
#include "glut.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

enum Color { RED, GREEN, YELLOW };

Color currentColor = RED;
float pointSize = 4.0;

void drawPoint(GLint x, GLint y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void setDrawingColor(Color color) {
    switch (color) {
        case RED:
            glColor3f(1.0, 0.0, 0.0);
            break;
        case GREEN:
            glColor3f(0.0, 1.0, 0.0);
            break;
        case YELLOW:
            glColor3f(1.0, 1.0, 0.0);
            break;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void mouseFunc(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        setDrawingColor(currentColor);
        glPointSize(pointSize);
    }
}

void motionFunc(int x, int y) {
    y = 480 - y;
    drawPoint(x, y);
    glutSwapBuffers();
}

void menuFunc(int value) {
    if (value >= 0 && value <= 2) {
        currentColor = static_cast<Color>(value);
    } else {
        switch (value) {
            case 4:
            pointSize = 4.0;
            break;
        case 8:
            pointSize = 8.0;
            break;
        case 10:
            pointSize = 10.0;
            break;
        }
    }
}

void keyboardFunc(unsigned char key, int x, int y) {
    if (key == 'd' || key == 'D') {
        display();
    }
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Atividade 3 by Pedro Garbossa");
    
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouseFunc);
    glutMotionFunc(motionFunc);
    glutKeyboardFunc(keyboardFunc);

    int colorMenu = glutCreateMenu(menuFunc);
    glutAddMenuEntry("Vermelho", RED);
    glutAddMenuEntry("Verde", GREEN);
    glutAddMenuEntry("Aramelo", YELLOW);

    int pointSizeMenu = glutCreateMenu(menuFunc);
    glutAddMenuEntry("Pequeno", 4);
    glutAddMenuEntry("Medio", 8);
    glutAddMenuEntry("Grande", 10);

    int mainMenu = glutCreateMenu(menuFunc);
    glutAddSubMenu("Cor", colorMenu);
    glutAddSubMenu("Tracado", pointSizeMenu);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}