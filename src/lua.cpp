#include "../include/lua.hpp"
#include "../include/textura.hpp"
#include <SOIL/SOIL.h>
#include <GL/glut.h>
#include <cmath>
#include <string>

void Lua::desenha(){
    GLfloat pilhas = 20;
    GLfloat fatias = 20;

    Textura esfera("../texturas/mundo.png");

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, esfera.get_textureID());

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
    esfera.~Textura();
}

Lua::Lua(GLfloat raio){
    this->raio = raio;
}