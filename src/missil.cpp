#include "../include/missil.hpp"

void Missil::desenha() {
    glPushMatrix();
        cilindro();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0, -(altura/2), 0.0);
        esfera();
    glPopMatrix();
}

void Missil::esfera(){

    GLfloat pilhas = 20;
    GLfloat fatias = 20;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,textura_esfera->get_textureID());

    glColor3f(0.8,0,0);
    glBegin(GL_TRIANGLE_STRIP);
    for (GLfloat i = 0; i < pilhas; ++i) {
        for (GLfloat j = 0; j <= fatias; ++j) {
            GLfloat phi = M_PI * static_cast<GLfloat>(i) / pilhas;
            GLfloat theta = 2.0f * M_PI * static_cast<GLfloat>(j) / fatias;

            GLfloat x = (raio) * sin(phi) * cos(theta);
            GLfloat y = (raio) * cos(phi);
            GLfloat z = (raio) * sin(phi) * sin(theta);

            GLfloat s = static_cast<GLfloat>(j) / fatias;
            GLfloat t = static_cast<GLfloat>(i) / pilhas;

            glTexCoord2f(s, t);
            glVertex3f(x, y, z);

            phi = M_PI * static_cast<GLfloat>(i + 1) / pilhas;

            x = (raio) * sin(phi) * cos(theta);
            y = (raio) * cos(phi);    
            z = (raio) * sin(phi) * sin(theta);

            s = static_cast<GLfloat>(j) / fatias;
            t = static_cast<GLfloat>(i + 1) / pilhas;

            glTexCoord2f(s, t);
            glVertex3f(x, y, z);
        }
    }
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void Missil::cilindro(){
    GLfloat segments = 20.0f;
    // Ativar mapeamento de textura
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textura_meio->get_textureID());

    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i <= segments; ++i) {
        float theta = 2.0f * M_PI * static_cast<float>(i) / segments;
        float x = raio * cos(theta);
        float z = raio * sin(theta);
        float s = static_cast<float>(i) / segments;

        // Mapeamento de textura para o lado superior do cilindro
        glTexCoord2f(s, 1.0f);
        glVertex3f(x, altura / 2.0f, z);

        // Mapeamento de textura para o lado inferior do cilindro
        glTexCoord2f(s, 0.0f);
        glVertex3f(x, -altura / 2.0f, z);
    }
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i <= segments; ++i) {
        float theta = 2.0f * M_PI * static_cast<float>(i) / segments;
        float x = raio * cos(theta);
        float z = raio * sin(theta);
        float s = static_cast<float>(i) / segments;

        // Mapeamento de textura para os vértices superiores
        glTexCoord2f(s, 1.0f);
        glVertex3f(x, altura / 2.0f, z);

        // Mapeamento de textura para os vértices inferiores
        glTexCoord2f(s, 0.0f);
        glVertex3f(x, -altura / 2.0f, z);
    }
    glEnd();

    // Desativar mapeamento de textura
    glDisable(GL_TEXTURE_2D);
}

Missil::Missil(GLfloat raio, GLfloat altura){
    this->raio = raio;
    this->altura = altura;
    const char* caminho = "fogo2.jpeg";
    textura_meio = new Textura(caminho);
    textura_esfera = new Textura("meteoro.png");
    glBindTexture(GL_TEXTURE_2D, textura_meio->get_textureID());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glBindTexture(GL_TEXTURE_2D, 0);  // Desvincular textura para evitar alterações acidentais
}

// In missil.cpp file

Missil::~Missil() {
    delete textura_meio;
    delete textura_esfera;
}
