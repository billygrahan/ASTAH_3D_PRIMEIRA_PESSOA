#include "../include/lua.hpp"

void Lua::desenha(){
    GLfloat pilhas = 20;
    GLfloat fatias = 20;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,textura_lua->get_textureID());

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
}

Lua::Lua(GLfloat raio){
    this->raio = raio;
    const char* caminho = "lua.jpg";
    textura_lua = new Textura(caminho);
}