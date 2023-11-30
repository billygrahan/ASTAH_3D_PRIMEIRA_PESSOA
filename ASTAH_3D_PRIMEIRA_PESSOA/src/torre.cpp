#include "../include/torre.hpp"
#include <GL/glut.h>
#include <cmath>
#include <string>

void predio_principal(double largura, double altura);
//void bandeiras(double largura, double altura, const string& caminho);

void Torre::desenha(){
    //desenha predio principal
    predio_principal(largura, altura);

    // desenha predios auxiliares
    glPushMatrix();
        glTranslated(largura,0.0,largura);
        predio_principal(largura/2, altura/2);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-largura,0.0,largura);
        predio_principal(largura/2, altura/2);
    glPopMatrix();
    glPushMatrix();
        glTranslated(largura,0.0,-largura);
        predio_principal(largura/2, altura/2);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-largura,0.0,-largura);
        predio_principal(largura/2, altura/2);
    glPopMatrix();

    // desenha as bandeiras
    glPushMatrix();
        glTranslated(largura, altura, largura);
        //bandeiras(largura, altura, "../texturas/astah.png");
    glPopMatrix();

}

void predio_principal(double largura, double altura){
    glBegin(GL_TRIANGLE_STRIP);

        // lado z+
        glColor3f(1.0, 0.0, 1.0); 
        glVertex3f(largura, 0.0, largura);
        glVertex3f(-largura, 0.0, largura);

        glColor3f(0.0, 0.0, 0.0); 
        glVertex3f(largura, altura, largura);
        glVertex3f(-largura, altura, largura);

        // lado x+
        glColor3f(1.0, 0.0, 1.0); 
        glVertex3f(largura, 0.0, largura);
        glVertex3f(largura, 0.0, -largura);

        glColor3f(0.0, 0.0, 0.0); 
        glVertex3f(largura, altura, largura);
        glVertex3f(largura, altura, -largura);

        // lado z-
        glColor3f(1.0, 0.0, 1.0); 
        glVertex3f(largura, 0.0, -largura);
        glVertex3f(-largura, 0.0, -largura);

        glColor3f(0.0, 0.0, 0.0); 
        glVertex3f(largura, altura, -largura);
        glVertex3f(-largura, altura, -largura);

        // lado x-
        glColor3f(1.0, 0.0, 1.0); 
        glVertex3f(-largura, 0.0, -largura);
        glVertex3f(-largura, 0.0, largura);

        glColor3f(0.0, 0.0, 0.0); 
        glVertex3f(-largura, altura, -largura);
        glVertex3f(-largura, altura, largura);

        //tampa
        glColor3f(0.0, 0.0, 0.0); 
        glVertex3f(largura, altura, largura);
        glVertex3f(-largura, altura, largura);
        glVertex3f(largura, altura, -largura);
        glVertex3f(-largura, altura, -largura);


    glEnd();

    glBegin(GL_LINES);

        glColor3f(1.0, 1.0, 1.0);

        //alturas
        glVertex3f(largura, 0.0, largura);
        glVertex3f(largura, altura, largura);
        
        glVertex3f(-largura, 0.0, largura);
        glVertex3f(-largura, altura, largura);

        glVertex3f(-largura, 0.0, -largura);
        glVertex3f(-largura, altura, -largura);

        glVertex3f(largura, 0.0, -largura);
        glVertex3f(largura, altura, -largura);

        //larguras
            //bases
        glVertex3f(largura, 0.0, largura);
        glVertex3f(-largura, 0.0, largura);

        glVertex3f(-largura, 0.0, largura);
        glVertex3f(-largura, 0.0, -largura);

        glVertex3f(-largura, 0.0, -largura);
        glVertex3f(largura, 0.0, -largura);

        glVertex3f(largura, 0.0, -largura);
        glVertex3f(largura, 0.0, largura);

            //topos
        glVertex3f(largura, altura, largura);
        glVertex3f(-largura, altura, largura);

        glVertex3f(-largura, altura, largura);
        glVertex3f(-largura, altura, -largura);

        glVertex3f(-largura, altura, -largura);
        glVertex3f(largura, altura, -largura);

        glVertex3f(largura, altura, -largura);
        glVertex3f(largura, altura, largura);
    glEnd();
}



/*void bandeiras(double Largura, double altura, const string& caminho){
    glBegin(GL_LINES);
        glVertex3f(0.0,0.0,0.0);
        glVertex3f(0.0,Largura,0.0);
    glEnd();

    Textura bandeira(caminho.c_str());

    GLfloat largura = static_cast<GLfloat>(Largura);

    GLfloat vertices[]{
    0.0,0.0,0.0,
    largura/2,0.0,0.0,
    0.0,largura/3,0.0,
    largura/2,largura/3,0.0
    };

    GLfloat ver_text[]{
        0,0,
        1,0,
        0,1,
        1,1
    };
        // Ativar o mapeamento de textura
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, bandeira.get_textureID());

    glPushMatrix();
    glTranslated(0.0,(2*largura)/3,0.0);
    //glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLE_STRIP);
        for (int i = 0; i < 4; i++) {
            glTexCoord2fv(ver_text + i * 2);
            glVertex3fv(vertices + i * 3);
        }
    glEnd();
    glPopMatrix();

    bandeira.~Textura();
}*/

Torre::Torre(double largura, double altura){
    this->largura = largura;
    this->altura = altura;
}

double Torre::get_altura(){
    return altura;
}