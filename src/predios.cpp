#include "../include/predios.hpp"

void Predios::desenha(){
    if(colisao == true) glColor3f(1,0,0);
    else glColor3f(1,1,1);
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

GLfloat Predios::get_largura(){
    return largura;
}

void Predios::set_colisao(bool colisao){
    this->colisao = colisao;
}
void Predios::calcula_normal(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3) {
    float nx, ny, nz;

    // Calculate the normal vector
    nx = (y2-y1)*(z3-z1) - (z2-z1)*(y3-y1);
    ny = (z2-z1)*(x3-x1) - (x2-x1)*(z3-z1);
    nz = (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1);

    // Calculate the length of the normal vector
    float length = sqrt(nx * nx + ny * ny + nz * nz);

    // Normalize the normal vector
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
