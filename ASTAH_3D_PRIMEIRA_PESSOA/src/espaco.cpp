#include "../include/espaco.hpp"

void Espaco::desenha(){
    GLfloat pilhas = 40;
    GLfloat fatias = 40;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textura_ceu->get_textureID());

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLE_STRIP);
    for (GLfloat i = 0; i < pilhas; ++i) {
        for (GLfloat j = 0; j <= fatias; ++j) {
            GLfloat phi = M_PI * static_cast<GLfloat>(i) / pilhas;
            GLfloat theta = 2.0f * M_PI * static_cast<GLfloat>(j) / fatias;

            GLfloat x = raio * sin(phi) * cos(theta);
            GLfloat y = raio * cos(phi);
            GLfloat z = raio * sin(phi) * sin(theta);

            GLfloat s = static_cast<GLfloat>(j) / fatias;
            GLfloat t = static_cast<GLfloat>(i) / pilhas;

            glTexCoord2f(s, t);
            glVertex3f(x, y, z);

            phi = M_PI * static_cast<GLfloat>(i + 1) / pilhas;

            x = raio * sin(phi) * cos(theta);
            y = raio * cos(phi);    
            z = raio * sin(phi) * sin(theta);

            s = static_cast<GLfloat>(j) / fatias;
            t = static_cast<GLfloat>(i + 1) / pilhas;

            glTexCoord2f(s, t);
            glVertex3f(x, y, z);
        }
    }
    glEnd();

    glDisable(GL_TEXTURE_2D);
    //esfera.~Textura();
}

Espaco::Espaco(GLfloat novo_raio){
    raio = novo_raio;
    char* caminho = "ceu.png";
    textura_ceu = new Textura(caminho);
    // Carregar a textura
    // this->textureID = SOIL_load_OGL_texture(
    // "../texturas/ceu.png",  // Substitua com o caminho para sua textura
    // SOIL_LOAD_AUTO,
    // SOIL_CREATE_NEW_ID,
    // SOIL_FLAG_INVERT_Y
    // );

    // if (this->textureID == 0) {
    // const char* error = SOIL_last_result();
    // printf("Erro ao carregar textura: %s\n", error);
    // }
}