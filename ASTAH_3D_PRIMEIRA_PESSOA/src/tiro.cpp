#include "../include/tiro.hpp"

void Tiro::desenha(){
    glPushMatrix();
        glTranslated(x_tiro,y_tiro,z_tiro);
        esfera();
    glPopMatrix();
}

void Tiro::esfera(){
    GLfloat pilhas = 20;
    GLfloat fatias = 20;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,textura_tiro->get_textureID());

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLE_STRIP);
    for (GLfloat i = 0; i < pilhas; ++i) {
        for (GLfloat j = 0; j <= fatias; ++j) {
            GLfloat phi = M_PI * static_cast<GLfloat>(i) / pilhas;
            GLfloat theta = 2.0f * M_PI * static_cast<GLfloat>(j) / fatias;

            GLfloat x = (raio+0.3f) * sin(phi) * cos(theta);
            GLfloat y = (raio+0.3f) * cos(phi);
            GLfloat z = (raio+0.3f) * sin(phi) * sin(theta);

            GLfloat s = static_cast<GLfloat>(j) / fatias;
            GLfloat t = static_cast<GLfloat>(i) / pilhas;

            glTexCoord2f(s, t);
            glVertex3f(x, y, z);

            phi = M_PI * static_cast<GLfloat>(i + 1) / pilhas;

            x = (raio+0.3f) * sin(phi) * cos(theta);
            y = (raio+0.3f) * cos(phi);    
            z = (raio+0.3f) * sin(phi) * sin(theta);

            s = static_cast<GLfloat>(j) / fatias;
            t = static_cast<GLfloat>(i + 1) / pilhas;

            glTexCoord2f(s, t);
            glVertex3f(x, y, z);
        }
    }
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void Tiro::updateTiroPosition(const GLfloat *x_cam, const GLfloat * y_cam, const GLfloat * z_cam, int* cont_tiros){
    if(disparo == true){
        aux_x = *x_cam;
        aux_y = *y_cam;
        aux_z = *z_cam;
        disparo = false;
        atualizacao = true;
        y_tiro = 3.0f;
    }
    else if(atualizacao == true && y_tiro <= aux_y){
        x_tiro += (aux_x/velocidade);
        y_tiro += (aux_y/velocidade);
        z_tiro += (aux_z/velocidade);
    }
    else if(atualizacao == true){
        aux_x = 0;
        aux_y = 0;
        aux_z = 0;
        x_tiro = 0;
        y_tiro = 0;
        z_tiro = 0;
        atualizacao = false;
        cont_tiros -= 1;
    }
}

void Tiro::set_disparo(bool disparo){
    this->disparo = disparo;
}

Tiro::Tiro(GLfloat raio){
    this->raio = raio;
    textura_tiro = new Textura("espiral.jpeg");
    aux_x = 0;
    aux_y = 0;
    aux_z = 0;
    velocidade = 100;
    disparo = false;
    atualizacao = false;
    x_tiro = 0;
    y_tiro = 0;
    z_tiro = 0;
}
