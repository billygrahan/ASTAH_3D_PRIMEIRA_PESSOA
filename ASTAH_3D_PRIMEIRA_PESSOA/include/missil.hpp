#ifndef MISSIL_H
#define MISSIL_H

#include <GL/glut.h>
#include <cmath>
#include <SOIL/SOIL.h>
#include "../include/textura.hpp"

class Missil {
    private:
        GLfloat raio;
        GLfloat altura;
        Textura *textura_meio;
        Textura *textura_esfera;
    protected:
        void esfera();
        void cilindro();
    public:
        Missil(GLfloat raio, GLfloat altura);
        void desenha();
        void get_raio();
};

#endif