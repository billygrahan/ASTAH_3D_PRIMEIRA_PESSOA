#include "../include/predios.hpp"

void Predios::desenha(){

    // desenha predios auxiliares
    glPushMatrix();
        glTranslated(pos,0.0,pos);
        predio_principal();
    glPopMatrix();
    glPushMatrix();
        glTranslated(-pos,0.0,pos);
        predio_principal();
    glPopMatrix();
    glPushMatrix();
        glTranslated(0.0,0.0,pos);
        predio_principal();
    glPopMatrix();
    glPushMatrix();
        glTranslated(0.0,0.0,-pos);
        predio_principal();
    glPopMatrix();
    glPushMatrix();
        glTranslated(pos,0.0,-pos);
        predio_principal();
    glPopMatrix();
    glPushMatrix();
        glTranslated(-pos,0.0,-pos);
        predio_principal();
    glPopMatrix();

}

void Predios::predio_principal(){

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textura_predios->get_textureID());

    glBegin(GL_QUADS);
        
        // lado z+ 
        glTexCoord2f(0.0, 0.0);
        glVertex3f(largura, 0.0, largura);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(-largura, 0.0, largura);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(-largura, altura, largura);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(largura, altura, largura);

        // lado x+ 
        glTexCoord2f(0.0, 0.0);
        glVertex3f(largura, 0.0, largura);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(largura, 0.0, -largura);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(largura, altura, -largura);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(largura, altura, largura);

        // lado z- 
        glTexCoord2f(0.0, 0.0);
        glVertex3f(largura, 0.0, -largura);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(-largura, 0.0, -largura);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(-largura, altura, -largura);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(largura, altura, -largura);

        // lado x- 
        glTexCoord2f(0.0, 0.0);
        glVertex3f(-largura, 0.0, -largura);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(-largura, 0.0, largura);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(-largura, altura, largura);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(-largura, altura, -largura);


    glEnd();

    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textura_predios_topo->get_textureID());

    glBegin(GL_QUADS);
        //tampa
        glTexCoord2f(0.0*4.0, 0.0*4.0);
        glVertex3f(largura, altura, largura);
        glTexCoord2f(1.0*4.0, 0.0*4.0);
        glVertex3f(-largura, altura, largura);
        glTexCoord2f(1.0*4.0, 1.0*4.0);
        glVertex3f(-largura, altura, -largura);
        glTexCoord2f(0.0*4.0, 1.0*4.0);
        glVertex3f(largura, altura, -largura);
    glEnd();

    glDisable(GL_TEXTURE_2D);

    // glDisable(GL_LIGHTING);
    // glDisable(GL_LIGHT0);
}

Predios::Predios(GLfloat largura, GLfloat altura, GLfloat pos){
    this->largura = largura;
    this->altura = altura;
    this->pos = pos;
    this->colisao = false;
    textura_predios = new Textura("predio1.png");
    textura_predios_topo = new Textura("prediotopo1.png");

    glBindTexture(GL_TEXTURE_2D, textura_predios_topo->get_textureID());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glBindTexture(GL_TEXTURE_2D, 0);  // Desvincular textura para evitar alterações acidentais

}

GLfloat Predios::get_altura(){
    return altura;
}

// In Predios.cpp file

Predios::~Predios() {
    delete textura_predios;
    delete textura_predios_topo;
}
