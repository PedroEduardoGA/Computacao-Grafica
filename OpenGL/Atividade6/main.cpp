/*  
    Programa que desenha um cubo 3D e disponibiliza as seguintes movimentacoes: 
    - Setas diricionais: Rotaciona o cubo
    - W: Zoom in
    - s: Zoom out
    - A: Movimenta para esquerda
    - D: Movimenta para direita
*/
#include <windows.h>
#include "glut.h"

GLfloat anguloX = 0.0f;
GLfloat anguloY = 0.0f;
GLfloat zoom = 1.0f;
GLfloat X = 0.0f;
GLfloat Y = 0.0f;

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);//Preto
    glEnable(GL_DEPTH_TEST);
}

void desenhaCubo(){
    glColor3f(1.0,0.0,0.0);
    glBegin (GL_POLYGON);
        glVertex3f(-0.5,-0.5,0.5);
        glVertex3f(0.5,-0.5,0.5);
        glVertex3f(0.5,0.5,0.5);
        glVertex3f(-0.5,0.5,0.5);
    glEnd();
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
        glVertex3f(0.5,0.5,0.5);
        glVertex3f(0.5,-0.5,0.5);
        glVertex3f(0.5,-0.5,-0.5);
        glVertex3f(0.5,0.5,-0.5);
    glEnd ();
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
        glVertex3f(0.5,-0.5,0.5);
        glVertex3f(-0.5,-0.5,0.5);
        glVertex3f(-0.5,-0.5,-0.5);
        glVertex3f(0.5,-0.5,-0.5);
    glEnd();
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
        glVertex3f(-0.5,0.5,0.5);
        glVertex3f(0.5,0.5,0.5);
        glVertex3f(0.5,0.5,-0.5);
        glVertex3f(-0.5,0.5,-0.5);
    glEnd();
    glColor3f (0.0,1.0,1.0);
    glBegin (GL_POLYGON);
        glVertex3f(-0.5,-0.5,-0.5);
        glVertex3f(-0.5,0.5,-0.5);
        glVertex3f(0.5,0.5,-0.5);
        glVertex3f(0.5,-0.5,-0.5);
    glEnd();
    glColor3f(1.0,1.0,1.0);
    glBegin (GL_POLYGON);
        glVertex3f(-0.5,0.5,-0.5);
        glVertex3f(-0.5,-0.5,-0.5);
        glVertex3f(-0.5,-0.5,0.5);
        glVertex3f(-0.5,0.5,0.5);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 1.0f, 0.1f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);

    glRotatef(anguloX, 1.0f, 0.0f, 0.0f);
    glRotatef(anguloY, 0.0f, 1.0f, 0.0f);
    glScalef(zoom, zoom, zoom);
    glTranslatef(X, Y, 0.0f);

    desenhaCubo();// Desenha o quadrado 3D
    glFlush();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'w':
            zoom += 0.1f;//Zoom-in
            break;
        case 's':
            zoom -= 0.1f;//Zoom-out
            if (zoom < 0 )
                zoom = 0.1f;//Limitador de zoom
            break;
        case 'a':
            X -= 0.1f;//Move pra esquerda
            break;
        case 'd':
            X += 0.1f;//Move pra direita
            break;
    }
    glutPostRedisplay();
}

void specialKeys(int key, int x, int y)
{
    switch (key) {
        case GLUT_KEY_UP:
            anguloX -= 5.0f;//Rotaciona p/ cima
            break;
        case GLUT_KEY_DOWN:
            anguloX += 5.0f;//Rotaciona p/ baixo
            break;
        case GLUT_KEY_LEFT:
            anguloY -= 5.0f;//Rotaciona p/ esquerda
            break;
        case GLUT_KEY_RIGHT:
            anguloY += 5.0f;//Rotaciona p/ direita
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Atividade 6 by Pedro Garbossa");
    
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    init();
    glutMainLoop();

    return EXIT_SUCCESS;
}