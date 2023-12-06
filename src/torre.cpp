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
        bandeiras();
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
    glBindTexture(GL_TEXTURE_2D, textura_torre_topo->get_textureID());

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



void Torre::bandeiras(){
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
    glBindTexture(GL_TEXTURE_2D, textura_bandeira->get_textureID());

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
    textura_bandeira = new Textura("bandeira_br.png");
    textura_torre = new Textura("predio.png");
    textura_torre_topo = new Textura("ceu.png");
}

GLfloat Torre::get_altura(){
    return altura;
}

// In torre.cpp file

Torre::~Torre() {
    delete textura_bandeira;
    delete textura_torre;
    delete textura_torre_topo;
}
