#include "../include/torre.hpp"
#include "../include/chao.hpp"
#include "../include/lua.hpp"
#include "../include/espaco.hpp"
#include <GL/glut.h>
#include <cmath>
#include <glm/glm.hpp>
#include <SOIL/SOIL.h>
#include <cstdio>


// Variáveis para a posição da câmera
float cameraRadius = 5.0f;
float cameraTheta = M_PI / 2.0f;
float cameraPhi = 0.0f;

void desenha();
void reshape(int width, int height);
void keyboard(unsigned char key, int x, int y);
void updateCameraPosition();

Chao chao(10, 0.1);
Torre torre(0.5, 3);
Lua lua(1.0f);
Espaco espaco(15.0f,"../texturas/ceu.png");

/*void initLighting() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat light_position[] = {0.0f, 8.0f , 0.0f, 0.0f}; // Fonte de luz direcional
    GLfloat light_diffuse[] = {1.0f, 1.0f, 1.0f, 0.0f}; // Cor difusa da luz
    GLfloat light_specular[] = {1.0f, 1.0f, 1.0f, 0.0f}; // Cor especular da luz

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
}*/

/*void initMaterials() {
    // Defina as propriedades do material da torre
    GLfloat torre_diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f}; // Cor difusa (vermelha)
    GLfloat torre_specular[] = {1.0f, 1.0f, 1.0f, 1.0f}; // Cor especular (branca)
    GLfloat torre_shininess = 100.0f; // Brilho

    glMaterialfv(GL_FRONT, GL_DIFFUSE, torre_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, torre_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, torre_shininess);
}*/

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("so vamo");

    glutDisplayFunc(desenha);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glEnable(GL_DEPTH_TEST);

    //initLighting();   // Inicializa as configurações de luz
    //initMaterials();  // Inicializa as configurações de material

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
    chao.desenha();
    glPopMatrix();

    glPushMatrix();
    //glTranslated(0.0,-1.0,0.0);
    torre.desenha();
    glPopMatrix();

    glPushMatrix();
    //glColor3f(0.0, 1.0, 1.0);
    //glutWireCube(1.0);
    glPopMatrix();

    // desenha esfera
    glPushMatrix();
        glTranslated(5.0,torre.get_altura()+3,5.0);
        //glColor3f(0.0, 1.0, 1.0);
        glRotatef(180,1,0,0);
        //lua.desenha();
        //glutSolidSphere(1.0, 50, 50);
    glPopMatrix();

    glPushMatrix();
        //glTranslated(5.0,torre.get_altura()+3,5.0);
        //glColor3f(0.0, 1.0, 1.0);
        glRotatef(180,1,0,0);
        espaco.desenha();
        //glutSolidSphere(1.0, 50, 50);
    glPopMatrix();

    glutSwapBuffers();
}

void updateCameraPosition() {
    float x = cameraRadius * sin(cameraTheta) * cos(cameraPhi);
    float y = cameraRadius * cos(cameraTheta);
    float z = cameraRadius * sin(cameraTheta) * sin(cameraPhi);
    gluLookAt(x, y, z, 0, torre.get_altura(), 0, 0, 1, 0);
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
