#include "../include/predios.hpp"

void Predios::desenha(){
    glPushMatrix();
        predio_principal();
    glPopMatrix();
}

void Predios::predio_principal(){

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textura_predios->get_textureID());

    glBegin(GL_QUADS);
        
        // lado z+ 
        calcula_normal(largura, 0.0, largura, -largura, 0.0, largura, -largura, altura, largura);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(largura, 0.0, largura);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(-largura, 0.0, largura);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(-largura, altura, largura);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(largura, altura, largura);

        // lado x+ 
        calcula_normal(largura, 0.0, largura, largura, 0.0, -largura, largura, altura, -largura);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(largura, 0.0, largura);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(largura, 0.0, -largura);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(largura, altura, -largura);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(largura, altura, largura);

        // lado z- 
        calcula_normal(largura, 0.0, -largura, -largura, 0.0, -largura, -largura, altura, -largura);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(largura, 0.0, -largura);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(-largura, 0.0, -largura);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(-largura, altura, -largura);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(largura, altura, -largura);

        // lado x- 
        calcula_normal(-largura, 0.0, largura, -largura, 0.0, -largura, -largura, altura, -largura);
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
        calcula_normal(largura, altura, largura, -largura, altura, largura, -largura, altura, -largura);
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
}

Predios::Predios(GLfloat largura, GLfloat altura){
    this->largura = largura;
    this->altura = altura;
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

void Predios::calcula_normal(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3) {
    float v1x, v1y, v1z, v2x, v2y, v2z, nx, ny, nz;

    // Calculate vectors
    v1x = x2 - x1;
    v1y = y2 - y1;
    v1z = z2 - z1;

    v2x = x3 - x1;
    v2y = y3 - y1;
    v2z = z3 - z1;

    // Calculate cross product
    nx = v1y * v2z - v1z * v2y;
    ny = v1z * v2x - v1x * v2z;
    nz = v1x * v2y - v1y * v2x;

    // Normalize the normal vector
    float length = sqrt(nx * nx + ny * ny + nz * nz);
    nx /= length;
    ny /= length;
    nz /= length;

    glNormal3f(nx, ny, nz);
}

// In Predios.cpp file

Predios::~Predios() {
    delete textura_predios;
    delete textura_predios_topo;
}
