#include "../include/torre.hpp"

void Torre::desenha(){
    glColor3f(1.0, 1.0, 1.0);
    //desenha predio principal
    glPushMatrix();
        glTranslated(0.0,altura,0.0);
        predio_principal();
    glPopMatrix();

    // desenha predios auxiliares
    glPushMatrix();
        glTranslated(largura,0.0,largura);
        predio_principal();
    glPopMatrix();
    glPushMatrix();
        glTranslated(-largura,0.0,largura);
        predio_principal();
    glPopMatrix();
    glPushMatrix();
        glTranslated(largura,0.0,-largura);
        predio_principal();
    glPopMatrix();
    glPushMatrix();
        glTranslated(-largura,0.0,-largura);
        predio_principal();
    glPopMatrix();

    // desenha as bandeiras
    glPushMatrix();
        glTranslated(largura - 0.01, altura*2 - 0.25, largura - 0.01);
        //glRotatef(45,1,-1,-1);
        bandeiras(textura_bandeira_br->get_textureID());
    glPopMatrix();

    glPushMatrix();
        glTranslated(-(largura - 0.01), altura*2 - 0.25, -(largura - 0.01));
        glRotatef(180,0,1,0);
        //glRotatef(45,1,-1,-1);
        bandeiras(textura_bandeira_jap->get_textureID());
    glPopMatrix();

}

void Torre::predio_principal(){
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
    glBindTexture(GL_TEXTURE_2D, textura_torre->get_textureID());

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
    glBindTexture(GL_TEXTURE_2D, textura_torre_topo->get_textureID());

    glBegin(GL_QUADS);
        //tampa
        calcula_normal(largura, altura, largura, -largura, altura, largura, -largura, altura, -largura);
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



void Torre::bandeiras(GLint text){
    glLineWidth(3.0f);
    glColor3f(1.0, 1.0, 1.0); 
    glBegin(GL_LINES);
        glVertex3f(0.0,0.0,0.0);
        glVertex3f(0.0,largura,0.0);
    glEnd();

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
    glBindTexture(GL_TEXTURE_2D, text);

    glPushMatrix();
    glTranslated(0.0,(2*largura)/3,0.0);
    //glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLE_STRIP);
        for (int i = 0; i < 4; i++) {
            glTexCoord2fv(ver_text + i * 2);
            glVertex3fv(vertices + i * 3);
        }
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

Torre::Torre(GLfloat largura, GLfloat altura){
    this->largura = largura;
    this->altura = altura;
    textura_bandeira_br = new Textura("bandeirabr.png");
    textura_bandeira_jap = new Textura("bandeirajap.png");
    textura_torre = new Textura("predio.png");
    textura_torre_topo = new Textura("prediotopo.png");
}

GLfloat Torre::get_altura(){
    return altura;
}

// In torre.cpp file

void Torre::calcula_normal(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3) {
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

Torre::~Torre() {
    delete textura_bandeira_br;
    delete textura_torre;
    delete textura_torre_topo;
    delete textura_bandeira_jap;
}
