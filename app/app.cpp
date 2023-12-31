#include "../include/torre.hpp"
#include "../include/chao.hpp"
#include "../include/lua.hpp"
#include "../include/espaco.hpp"
#include "../include/missil.hpp"
#include "../include/predios.hpp"
#include "../include/iluminacao.hpp"
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <cmath>
#include <glm/glm.hpp>
#include <SOIL/SOIL.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include <random>

using namespace std;

// Variáveis para armazenar a última posição do mouse
int lastX = -1;
int lastY = -1;
bool cursorLocked = false;

// Variaveis para posição do missel
GLfloat x_cam = 0;
GLfloat y_cam = 0;
GLfloat z_cam = 0;

// Variáveis para a posição da câmera
GLfloat cameraRadius = 45.0f;
GLfloat cameraTheta = M_PI / 2.0f;
GLfloat cameraPhi = 0.0f;

void desenha();
void reshape(int width, int height);
void keyboard(unsigned char key, int x, int y);
void updateCameraPosition();
void carrega_objetos();
void timerFunc(int value);
void mouseMotion(int x, int y);
void mouseButton(int button, int state, int x, int y);
void desenha_predios();
void desenha_misseis();
void colisao_predios();


Chao *chao = nullptr;
Torre *torre = nullptr;
Lua *lua = nullptr;
Espaco *espaco = nullptr;
Missil *missil[3];
Predios *predios[6];
Iluminacao *iluminacao = nullptr;



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("ASTAH 3D");

    carrega_objetos();

    glutDisplayFunc(desenha);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    // glutMotionFunc(mouseMotion);
    // glutMouseFunc(mouseButton);


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
        iluminacao->ativa();
        torre->desenha();
        iluminacao->desativa();
    glPopMatrix();

    iluminacao->ativa();
    desenha_predios();
    iluminacao->desativa();

    // desenha esfera
    glPushMatrix();
        glTranslated(20.0,20,20.0);
        //glColor3f(0.0, 1.0, 1.0);
        glRotatef(180,1,0,0);
        lua->desenha();
        //glutSolidSphere(1.0, 50, 50);
    glPopMatrix();

    desenha_misseis();

    glutSwapBuffers();
}

void mouseMotion(int x, int y) {
    if (cursorLocked) {
        int deltaX = x - lastX;
        int deltaY = y - lastY;

        // Atualiza a orientação da câmera com base nos movimentos do mouse
        cameraTheta += 0.005f * static_cast<float>(deltaY);
        cameraPhi += 0.005f * static_cast<float>(deltaX);

        // Mantém os ângulos dentro de limites razoáveis
        if (cameraTheta < 0.1f) cameraTheta = 0.1f;
        if (cameraTheta > M_PI - 0.1f) cameraTheta = M_PI - 0.1f;

        // Atualiza a posição do cursor anterior
        lastX = x;
        lastY = y;

        // Redesenha a cena
        glutPostRedisplay();
    }
}

void mouseButton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Trava/desatrava o cursor ao clicar no botão esquerdo do mouse
        cursorLocked = !cursorLocked;

        // Se o cursor for travado, esconde o cursor
        if (cursorLocked) {
            glutSetCursor(GLUT_CURSOR_NONE);
        } else {
            glutSetCursor(GLUT_CURSOR_INHERIT);
        }
    }

    // Atualiza a posição do cursor anterior
    lastX = x;
    lastY = y;
}

void colisao_predios(GLfloat x_missil, GLfloat y_missil, GLfloat z_missil){
    GLfloat dist = ((chao->get_raio())/3);

    if(dist+predios[0]->get_largura() >= x_missil    &&    dist-predios[0]->get_largura() <= x_missil   &&    predios[0]->get_altura() >= y_missil    &&   dist+predios[0]->get_largura() >= z_missil    &&    dist-predios[0]->get_largura() <= z_missil)
    {
        predios[0]->set_colisao(true);
    }
    if(-dist+predios[0]->get_largura() >= x_missil    &&    -dist-predios[0]->get_largura() <= x_missil   &&    predios[0]->get_altura() >= y_missil    &&   dist+predios[0]->get_largura() >= z_missil    &&    dist-predios[0]->get_largura() <= z_missil)
    {
        predios[1]->set_colisao(true);
    }
    if(0+predios[0]->get_largura() >= x_missil    &&    0-predios[0]->get_largura() <= x_missil   &&    predios[0]->get_altura() >= y_missil    &&   dist+predios[0]->get_largura() >= z_missil    &&    dist-predios[0]->get_largura() <= z_missil)
    {
        predios[2]->set_colisao(true);
    }
    if(0+predios[0]->get_largura() >= x_missil    &&    0-predios[0]->get_largura() <= x_missil   &&    predios[0]->get_altura() >= y_missil    &&   -dist+predios[0]->get_largura() >= z_missil    &&    -dist-predios[0]->get_largura() <= z_missil)
    {
        predios[3]->set_colisao(true);
    }
    if(dist+predios[0]->get_largura() >= x_missil    &&    dist-predios[0]->get_largura() <= x_missil   &&    predios[0]->get_altura() >= y_missil    &&   -dist+predios[0]->get_largura() >= z_missil    &&    -dist-predios[0]->get_largura() <= z_missil)
    {
        predios[4]->set_colisao(true);
    }
    if(-dist+predios[0]->get_largura() >= x_missil    &&    -dist-predios[0]->get_largura() <= x_missil   &&    predios[0]->get_altura() >= y_missil    &&   -dist+predios[0]->get_largura() >= z_missil    &&    -dist-predios[0]->get_largura() <= z_missil)
    {
        predios[5]->set_colisao(true);
    }
}

void desenha_predios(){
    //desenha predios auxiliares
    glPushMatrix();
        glTranslated((chao->get_raio())/3,0.0,(chao->get_raio())/3);
        predios[0]->desenha();
    glPopMatrix();
    glPushMatrix();
        glTranslated(-(chao->get_raio())/3,0.0,(chao->get_raio())/3);
        predios[1]->desenha();
    glPopMatrix();
    glPushMatrix();
        glTranslated(0.0,0.0,(chao->get_raio())/3);
        predios[2]->desenha();
    glPopMatrix();
    glPushMatrix();
        glTranslated(0.0,0.0,-(chao->get_raio())/3);
        predios[3]->desenha();
    glPopMatrix();
    glPushMatrix();
        glTranslated((chao->get_raio())/3,0.0,-(chao->get_raio())/3);
        predios[4]->desenha();
    glPopMatrix();
    glPushMatrix();
        glTranslated(-(chao->get_raio())/3,0.0,-(chao->get_raio())/3);
        predios[5]->desenha();
    glPopMatrix();
}

void desenha_misseis(){
    for(int i = 0; i < 3 ;i++){
        glPushMatrix();
            glTranslatef(missil[i]->get_x(), missil[i]->get_y(), missil[i]->get_z());
            missil[i]->desenha();
        glPopMatrix();
    }
}


void updateCameraPosition() {
    x_cam = cameraRadius * sin(cameraTheta) * cos(cameraPhi);
    y_cam = cameraRadius * cos(cameraTheta);
    z_cam = cameraRadius * sin(cameraTheta) * sin(cameraPhi);
    gluLookAt(x_cam, y_cam, z_cam, 0, torre->get_altura()*2, 0, 0, 1, 0);
    //gluLookAt(0, (torre->get_altura()*2) + 0.7, 0, x_cam, y_cam, z_cam, 0, 1, 0);
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
            cameraTheta -= 0.07f;
            break;
        case 's':
            cameraTheta += 0.07f;
            break;
        case 'a':
            cameraPhi -= 0.07f;
            break;
        case 'd':
            cameraPhi += 0.07f;
            break;
        case 'e':
            cameraRadius += 0.1f;
            break;
        case 'q':
            cameraRadius -= 0.1f;
            break;
        case 27: // 27 é o código ASCII para a tecla "Esc"
            exit(0); // Encerra o programa
            break;
        case 'i':
            iluminacao->mover_frente();
            break;
        case 'k':
            iluminacao->mover_tras();
            break;
        case 'j':
            iluminacao->mover_esquerda();
            break;
        case 'l':
            iluminacao->mover_direita();
            break;
        case 'u':
            iluminacao->mover_cima();
            break;
        case 'o':
            iluminacao->mover_baixo();
            break;
        case 'f':
        case 'F':
            glutFullScreenToggle();
            break;
    }
    // Limitar os ângulos de câmera para evitar inversões
    if (cameraTheta < 0.1f) cameraTheta = 0.1f;
    if (cameraTheta > M_PI - 0.1f) cameraTheta = M_PI - 0.1f;

    glutPostRedisplay();
}

void timerFunc(int value) {
    for(int i = 0; i < 3 ;i++){
        colisao_predios(missil[i]->get_x(), missil[i]->get_y(), missil[i]->get_z());
        missil[i]->updateMissilPosition();
    }
    glutPostRedisplay();
    glutTimerFunc(1000 / 30, timerFunc, 0);
}

void carrega_objetos(){
    chao = new Chao(22.0, 0.2);
    torre = new Torre(0.45, 3);
    lua = new Lua(7.0f);
    espaco = new Espaco(50.0f);
    for(int i = 0; i < 3 ;i++){
        missil[i] = new Missil(0.3f,2.0f,0.07f);
    }
    for(int i = 0; i < 6 ;i++){
        predios[i] = new Predios(1.3, 3.5);
    }
    iluminacao = new Iluminacao();
}
