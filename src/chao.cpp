#include "../include/chao.hpp"

Chao::Chao(GLfloat largura, GLfloat especura) {
    this->raio = largura;
    this->especura = especura;
    textura_chao = new Textura("grama.png");

    glBindTexture(GL_TEXTURE_2D, textura_chao->get_textureID());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glBindTexture(GL_TEXTURE_2D, 0);  // Desvincular textura para evitar alterações acidentais

    textura_pista = new Textura("estrada.png");
    glBindTexture(GL_TEXTURE_2D, textura_pista->get_textureID());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_MIRRORED_REPEAT);
    glBindTexture(GL_TEXTURE_2D, 0); 
}

void Chao::desenha() {
    glPushMatrix();
        grama();
    glPopMatrix();

    for(GLfloat i = -3 ; i <= 3 ; i++){
    glPopMatrix();
        if(i < 1 && i > -1) i++;
        glPushMatrix();
        glTranslatef(i*(raio/8),0.3,0);
        arvore_1();
    glPopMatrix();
    }
    
    glPushMatrix();
        glTranslatef(0,-0.1,(raio/2)/3);
        pista();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,-0.1,-(raio/2)/3);
        pista();
    glPopMatrix();
}

void Chao::arvore_1() {
    glColor3f(0.5, 0.2, 0.0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
        glVertex3f(0,0,0);
        glVertex3f(0,-0.3,0);
    glEnd();

    glColor3f(0.0, 0.8, 0.0);
    GLfloat raio_cone = 0.2;
    GLfloat altura_cone = 0.6;
    GLfloat numSegmentos = 20;
    glBegin(GL_TRIANGLE_FAN);

    glVertex3f(0.0, 0.0, 0.0); // Vértice no topo do cone

    for (GLfloat i = 0; i <= numSegmentos; ++i) {
        GLfloat theta = (2.0 * M_PI * i) / numSegmentos;
        GLfloat x = raio_cone * cos(theta);
        GLfloat z = raio_cone * sin(theta);
        glVertex3f(x, 0.0, z); // Vértices na base do cone
    }

    glEnd();

    // Conectar a base ao topo do cone
    glBegin(GL_TRIANGLE_FAN);

    glVertex3f(0.0, altura_cone, 0.0); // Vértice no topo do cone

    for (GLfloat i = 0; i <= numSegmentos; ++i) {
        GLfloat theta = (2.0 * M_PI * i) / numSegmentos;
        GLfloat x = raio_cone * cos(theta);
        GLfloat z = raio_cone * sin(theta);
        glVertex3f(x, 0.0, z); // Vértices na base do cone
    }

    glEnd();
}

void Chao::pista(){
    // Aplica a cor cinz
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,textura_pista->get_textureID());
    glColor3f(1.0, 1.0, 1.0);
    // Parte de cima
    glBegin(GL_QUADS);
    glTexCoord2f(1.0*6, 0.0);
    glVertex3f(-raio / 2, especura, raio / (2 * 16.0 / 3.0));

    glTexCoord2f(1.0*6, 1.0);
    glVertex3f(-raio / 2, especura, -raio / (2 * 16.0 / 3.0));

    glTexCoord2f(0.0*6, 1.0);
    glVertex3f(raio / 2, especura, -raio / (2 * 16.0 / 3.0));

    glTexCoord2f(0.0*6, 0.0);
    glVertex3f(raio / 2, especura, raio / (2 * 16.0 / 3.0));

    glDisable(GL_TEXTURE_2D);

    glEnd();

    glColor3f(0.5, 0.5, 0.5);
    // Parte de baixo
    glBegin(GL_QUADS);
    glVertex3f(-raio / 2, 0.0, -raio / (2 * 16.0 / 3.0));
    glVertex3f(raio / 2, 0.0, -raio / (2 * 16.0 / 3.0));
    glVertex3f(raio / 2, 0.0, raio / (2 * 16.0 / 3.0));
    glVertex3f(-raio / 2, 0.0, raio / (2 * 16.0 / 3.0));
    glEnd();

    // Parte lateral
    glBegin(GL_QUAD_STRIP);
    glVertex3f(-raio / 2, 0.0, -raio / (2 * 16.0 / 3.0));
    glVertex3f(-raio / 2, especura, -raio / (2 * 16.0 / 3.0));
    glVertex3f(raio / 2, 0.0, -raio / (2 * 16.0 / 3.0));
    glVertex3f(raio / 2, especura, -raio / (2 * 16.0 / 3.0));
    glVertex3f(raio / 2, 0.0, raio / (2 * 16.0 / 3.0));
    glVertex3f(raio / 2, especura, raio / (2 * 16.0 / 3.0));
    glVertex3f(-raio / 2, 0.0, raio / (2 * 16.0 / 3.0));
    glVertex3f(-raio / 2, especura, raio / (2 * 16.0 / 3.0));
    glVertex3f(-raio / 2, 0.0, -raio / (2 * 16.0 / 3.0));
    glVertex3f(-raio / 2, especura, -raio / (2 * 16.0 / 3.0));
    glEnd();
}

void Chao::grama(){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textura_chao->get_textureID());

    // Parte de cima
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-raio / 2.0, 0.0, -raio / 2.0);

    glTexCoord2f(8.0, 0.0);  // Repetir 8 vezes na direção T (vertical)
    glVertex3f(raio / 2.0, 0.0, -raio / 2.0);

    glTexCoord2f(8.0, 8.0);  // Repetir 8 vezes nas direções S e T
    glVertex3f(raio / 2.0, 0.0, raio / 2.0);

    glTexCoord2f(0.0, 8.0);  // Repetir 8 vezes na direção S (horizontal)
    glVertex3f(-raio / 2.0, 0.0, raio / 2.0);
    glEnd();

    // Lado direito
    glBegin(GL_QUADS);
    glVertex3f(raio / 2.0, 0.0, -raio / 2.0);
    glVertex3f(raio / 2.0, 0.0, raio / 2.0);
    glVertex3f(raio / 2.0, -especura, raio / 2.0);
    glVertex3f(raio / 2.0, -especura, -raio / 2.0);
    glEnd();

    // Lado esquerdo
    glBegin(GL_QUADS);
    glVertex3f(-raio / 2.0, 0.0, raio / 2.0);
    glVertex3f(-raio / 2.0, 0.0, -raio / 2.0);
    glVertex3f(-raio / 2.0, -especura, -raio / 2.0);
    glVertex3f(-raio / 2.0, -especura, raio / 2.0);
    glEnd();

    // Parte de baixo
    glBegin(GL_QUADS);
    glVertex3f(-raio / 2.0, -especura, -raio / 2.0);
    glVertex3f(raio / 2.0, -especura, -raio / 2.0);
    glVertex3f(raio / 2.0, -especura, raio / 2.0);
    glVertex3f(-raio / 2.0, -especura, raio / 2.0);
    glEnd();

    // Parte frontal
    glBegin(GL_QUADS);
    glVertex3f(-raio / 2.0, 0.0, raio / 2.0);  // Vértice inferior esquerdo
    glVertex3f(raio / 2.0, 0.0, raio / 2.0);   // Vértice inferior direito
    glVertex3f(raio / 2.0, -especura, raio / 2.0);  // Vértice superior direito
    glVertex3f(-raio / 2.0, -especura, raio / 2.0); // Vértice superior esquerdo
    glEnd();

    // Parte traseira
    glBegin(GL_QUADS);
    glVertex3f(raio / 2.0, 0.0, -raio / 2.0);  // Vértice inferior direito
    glVertex3f(-raio / 2.0, 0.0, -raio / 2.0); // Vértice inferior esquerdo
    glVertex3f(-raio / 2.0, -especura, -raio / 2.0); // Vértice superior esquerdo
    glVertex3f(raio / 2.0, -especura, -raio / 2.0);  // Vértice superior direito
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

GLfloat Chao::get_raio(){
    return raio;

}
// In chao.cpp file

Chao::~Chao() {
    delete textura_chao;
}
