#include "../include/predios.hpp"

void Predios::desenha(){

    // desenha predios auxiliares
    // glPushAttrib(GL_CURRENT_BIT | GL_ENABLE_BIT | GL_LIGHTING_BIT | GL_TEXTURE_BIT);
    //     glPushMatrix();
    //     glEnable(GL_LIGHTING);
    //     glEnable(GL_LIGHT1);
    //     GLfloat light_position[] = {10.0, 10.0, 10.0, 1.0};
    //     GLfloat light_ambient[] = {0.0, 0.0, 0.0, 1.0};
    //     GLfloat light_diffuse[] = {1.5f, 1.5f, 1.5f, 1.0f}; 
    //     GLfloat light_specular[] = {2.0f, 2.0f, 2.0f, 1.0f};
    //     GLfloat att_constant = 0.2;
    //     GLfloat att_linear = 0.0;
    //     GLfloat att_quadratic = 0.0;
    //     GLfloat spot_direction[] = {0.0, 0.0, 0.0};
    //     GLfloat spot_exponent = 0.0;
    //     GLfloat spot_cutoff = 180.0;

    //     glLightfv(GL_LIGHT1, GL_POSITION, light_position);
    //     glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
    //     glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    //     glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
    //     glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, att_constant);
    //     glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, att_linear);
    //     glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, att_quadratic);
    //     glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
    //     glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, spot_exponent);
    //     glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, spot_cutoff);
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
    // glPopAttrib();
}

void Predios::predio_principal(){
    // glEnable(GL_LIGHTING);
    // glEnable(GL_LIGHT0);

    // // Configuração da luz
    // glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    // glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
    // glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
    // glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

    // // Configuração do material
    // glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbiente);
    // glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDifuso);
    // glMaterialfv(GL_FRONT, GL_SPECULAR, materialEspecular);
    // glMaterialf(GL_FRONT, GL_SHININESS, brilhoMaterial);

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
        glTexCoord2f(0.0, 0.0);
        glVertex3f(largura, altura, largura);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(-largura, altura, largura);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(-largura, altura, -largura);
        glTexCoord2f(0.0, 1.0);
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
    textura_predios = new Textura("predio1.png");
    textura_predios_topo = new Textura("ceu.png");
}

GLfloat Predios::get_altura(){
    return altura;
}

// In Predios.cpp file

Predios::~Predios() {
    delete textura_predios;
    delete textura_predios_topo;
}
