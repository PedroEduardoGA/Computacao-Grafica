/*  
    Programa que desenha um triângulo na tela e interpreta ações do teclado: 
    - W e S (aumenta e diminui escala do objeto respectivamente)
    - A e D (rotaciona objeto para esquerda e para direita respectivamente)
    - Setas direcionais (translada o objeto na direção da tecla pressionada)
*/
#include <Windows.h>
#include "glut.h"

// Variáveis globais para as coordenadas X e Y, para a escala e angulo de rotação do triângulo
GLfloat Obj_x = 0.0f;
GLfloat Obj_y = 0.0f;
GLfloat Obj_scaleX = 1.0f;
GLfloat Obj_scaleY = 1.0f;
GLfloat Obj_angle = 0.0f;

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);//Define a cor de fundo como branco
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glTranslatef(Obj_x, Obj_y, 0.0f);//Translada o triângulo
    glRotatef(Obj_angle, 0.0f, 0.0f, 1.0f);//Rotação do triângulo
    glScalef(Obj_scaleX, Obj_scaleY, 1.0f);//Escala o triângulo
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);//cor vermelha
    glVertex2f(-0.25, -0.25);
    glVertex2f(0.25, -0.25);
    glVertex2f(0.0, 0.25);
    glEnd();
    glPopMatrix();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27://ESC
            exit(0);
            break;
        case 87:
        case 119://ASCII das Teclas w e W
            Obj_scaleX += 0.1f;
            Obj_scaleY += 0.1f;
            break;
        case 83:
        case 115://ASCII das Teclas s e S
            Obj_scaleX -= 0.1f;
            Obj_scaleY -= 0.1f;
            break;
        case 65:
        case 97://ASCII das Teclas a e A
            Obj_angle += 5.0f;
            break;
        case 68:
        case 100://ASCII das Teclas d e D
            Obj_angle -= 5.0f;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

void specialKeys(int key, int x, int y)
{
    switch (key) {
        case GLUT_KEY_UP:
            Obj_y += 0.1f;
            break;
        case GLUT_KEY_DOWN:
            Obj_y -= 0.1f;
            break;
        case GLUT_KEY_LEFT:
            Obj_x -= 0.1f;
            break;
        case GLUT_KEY_RIGHT:
            Obj_x += 0.1f;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Atividade 4 by Pedro Garbossa");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);//Função para teclas especiais
    glutMainLoop();

    return 0;
}
