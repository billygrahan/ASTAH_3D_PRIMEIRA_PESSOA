#include "../include/torre.hpp"
#include "../include/chao.hpp"
#include "../include/lua.hpp"
#include "../include/espaco.hpp"
#include "../include/missil.hpp"
#include "../include/tiro.hpp"
#include <GL/glut.h>
#include <cmath>
#include <glm/glm.hpp>
#include <SOIL/SOIL.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include <random>

using namespace std;

int cont_tiros = 0;
int *cont_tiros_aux = &cont_tiros;

// Variaveis para posição do missel
GLfloat x_cam = 0;
GLfloat y_cam = 0;
GLfloat z_cam = 0;

// Variaveis para posição do missel
GLfloat x_missil = 0;
GLfloat y_missil = 0;
GLfloat z_missil = 0;

// Variáveis para a posição da câmera
GLfloat cameraRadius = 15.0f;
GLfloat cameraTheta = M_PI / 2.0f;
GLfloat cameraPhi = 0.0f;

void desenha();
void reshape(int width, int height);
void keyboard(unsigned char key, int x, int y);
void updateCameraPosition();
void carrega_objetos();
void updateMissilPosition();
void timerFunc(int value);

Chao *chao = nullptr;
Torre *torre = nullptr;
Lua *lua = nullptr;
Espaco *espaco = nullptr;
Missil *missil = nullptr;
// vector<Tiro*> tiro;

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("so vamo");

    carrega_objetos();

    glutDisplayFunc(desenha);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glEnable(GL_DEPTH_TEST);

    glutTimerFunc(0, timerFunc, 0);  // Adicionada a chamada da função de temporizador
    
    glutMainLoop();

    return 0;
}

void desenha() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    updateCameraPosition();

    glPushMatrix();
        //glTranslated(5.0,torre.get_altura()+3,5.0);
        //glColor3f(0.0, 1.0, 1.0);
        glRotatef(180,1,0,0);
        espaco->desenha();
        //glutSolidSphere(1.0, 50, 50);
    glPopMatrix();

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
        glTranslated(10.0,torre->get_altura()+3,10.0);
        //glColor3f(0.0, 1.0, 1.0);
        glRotatef(180,1,0,0);
        lua->desenha();
        //glutSolidSphere(1.0, 50, 50);
    glPopMatrix();

    glPushMatrix();
        glTranslated(x_missil,y_missil,z_missil);
        missil->desenha();
    glPopMatrix();

    glPushMatrix();
        // for(int i = 0;i<4;i++){
        //     tiro[i]->desenha();
        // }
    glPopMatrix();

    glutSwapBuffers();
}

void updateCameraPosition() {
    x_cam = cameraRadius * sin(cameraTheta) * cos(cameraPhi);
    y_cam = cameraRadius * cos(cameraTheta);
    z_cam = cameraRadius * sin(cameraTheta) * sin(cameraPhi);
    gluLookAt(x_cam, y_cam, z_cam, 0, torre->get_altura(), 0, 0, 1, 0);
    //gluLookAt(0, torre->get_altura() + 0.3, 0, x_cam, y_cam, z_cam, 0, 1, 0);
}

GLfloat gerarNumeroAleatoriofloat(GLfloat minn, GLfloat maxx) {
    // Objeto do motor de números aleatórios
    static random_device rd;
    static default_random_engine gerador(rd());

    // Distribuição uniforme de GLfloats entre 0 e 15
    static uniform_real_distribution<GLfloat> distribuicao(minn, maxx);

    // Gerando e retornando um número aleatório float
    return distribuicao(gerador);
}

void updateMissilPosition(){
    if(y_missil <= 0.0){
        y_missil = 13;
        x_missil = gerarNumeroAleatoriofloat(-10,10);
        z_missil = gerarNumeroAleatoriofloat(-10,10);
    }
    else{
        y_missil -= 0.05f;
    }
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)width / (float)height, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y){
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
        // case 'l':
            // if(cont_tiros < 4){
            //     tiro[cont_tiros]->set_disparo(true);
            //     cont_tiros += 1;
            // }
            // break;
    }
    // Limitar os ângulos de câmera para evitar inversões
    if (cameraTheta < 0.1f) cameraTheta = 0.1f;
    if (cameraTheta > M_PI - 0.1f) cameraTheta = M_PI - 0.1f;

    glutPostRedisplay();
}

void timerFunc(int value) {
    // for(int i = 0;i<4;i++){
    //     tiro[i]->updateTiroPosition(&x_cam,&y_cam,&z_cam,cont_tiros_aux);
    // }
    updateMissilPosition();
    glutPostRedisplay();
    glutTimerFunc(1000 / 30, timerFunc, 0);
}

void carrega_objetos(){
    chao = new Chao(10, 0.1);
    torre = new Torre(0.5, 3);
    lua = new Lua(1.0f);
    espaco = new Espaco(40.0f);
    missil = new Missil(0.3f,2.0f);
    // for(int i = 0;i<4;i++){
    //     tiro.push_back(new Tiro(0.05f));
    // }
}
