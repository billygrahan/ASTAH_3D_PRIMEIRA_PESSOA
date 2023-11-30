#ifndef ESPACO_H
#define ESPACO_H

#include <GL/glut.h>
#include <cmath>
#include <SOIL/SOIL.h>
#include <cstdio>


class Espaco{
    private:
        GLfloat raio;
        GLuint textureID;
    public:
        Espaco(GLfloat novo_raio, const char* caminho);
        void desenha();
};
#endif