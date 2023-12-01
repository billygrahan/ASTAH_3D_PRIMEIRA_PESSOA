#ifndef ESPACO_H
#define ESPACO_H

#include <GL/glut.h>
#include <cmath>
#include <SOIL/SOIL.h>
#include <cstdio>
#include "../include/textura.hpp"


class Espaco{
    private:
        GLfloat raio;
        Textura *textura_ceu;
    public:
        Espaco(GLfloat novo_raio);
        void desenha();
};
#endif