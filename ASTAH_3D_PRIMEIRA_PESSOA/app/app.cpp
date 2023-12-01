#include "../include/torre.hpp"
#include "../include/chao.hpp"
#include "../include/lua.hpp"
#include "../include/espaco.hpp"
#include <GL/glut.h>
#include <cmath>
#include <glm/glm.hpp>
#include <SOIL/SOIL.h>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;


// Variáveis para a posição da câmera
float cameraRadius = 5.0f;
float cameraTheta = M_PI / 2.0f;
float cameraPhi = 0.0f;

void desenha();
void reshape(int width, int height);
void keyboard(unsigned char key, int x, int y);
void updateCameraPosition();
void carrega_objetos();

Chao *chao = nullptr;
Torre *torre = nullptr;
Lua *lua = nullptr;
Espaco *espaco = nullptr;

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("so vamo");

    carrega_objetos();

    glutDisplayFunc(desenha);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return 0;
}

void desenha() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    updateCameraPosition();

    glPushMatrix();
    //glTranslated(0.0,-1.0,0.0);
    chao->desenha();
    glPopMatrix();

    glPushMatrix();
    //glTranslated(0.0,-1.0,0.0);
    torre->desenha();
    glPopMatrix();

    // desenha esfera
    glPushMatrix();
        glTranslated(5.0,torre->get_altura()+3,5.0);
        //glColor3f(0.0, 1.0, 1.0);
        glRotatef(180,1,0,0);
        lua->desenha();
        //glutSolidSphere(1.0, 50, 50);
    glPopMatrix();

    glPushMatrix();
        //glTranslated(5.0,torre.get_altura()+3,5.0);
        //glColor3f(0.0, 1.0, 1.0);
        glRotatef(180,1,0,0);
        espaco->desenha();
        //glutSolidSphere(1.0, 50, 50);
    glPopMatrix();

    glutSwapBuffers();
}

void updateCameraPosition() {
    float x = cameraRadius * sin(cameraTheta) * cos(cameraPhi);
    float y = cameraRadius * cos(cameraTheta);
    float z = cameraRadius * sin(cameraTheta) * sin(cameraPhi);
    gluLookAt(x, y, z, 0, torre->get_altura(), 0, 0, 1, 0);
    //gluLookAt(0, torre.get_altura() + 0.3, 0, x, y, z, 0, 1, 0);
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)width / (float)height, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    // Controles da câmera usando as teclas WASD
    switch (key) {
        case 'w':
            cameraTheta -= 0.1f;
            break;
        case 's':
            cameraTheta += 0.1f;
            break;
        case 'a':
            cameraPhi -= 0.1f;
            break;
        case 'd':
            cameraPhi += 0.1f;
            break;
        case 'e':
            cameraRadius += 0.1f;
            break;
        case 'q':
            cameraRadius -= 0.1f;
            break;
    }
    // Limitar os ângulos de câmera para evitar inversões
    if (cameraTheta < 0.1f) cameraTheta = 0.1f;
    if (cameraTheta > M_PI - 0.1f) cameraTheta = M_PI - 0.1f;

    glutPostRedisplay();
}

void carrega_objetos(){
    chao = new Chao(10, 0.1);
    torre = new Torre(0.5, 3);
    lua = new Lua(1.0f);
    espaco = new Espaco(20.0f);
}
