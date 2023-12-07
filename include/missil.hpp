#ifndef MISSIL_H
#define MISSIL_H

#include <GL/glut.h>
#include <cmath>
#include <SOIL/SOIL.h>
#include "../include/textura.hpp"
#include <random>

class Missil {
    private:
        GLfloat velocidade;
        GLfloat altura_spall;
        GLfloat x_missil;
        GLfloat y_missil;
        GLfloat z_missil;
        GLfloat raio;
        GLfloat altura;
        Textura *textura_meio;
        Textura *textura_esfera;
    protected:
        void esfera();
        void cilindro();
        GLfloat gerarNumeroAleatoriofloat(GLfloat minn, GLfloat maxx);
    public:
        Missil(GLfloat raio, GLfloat altura, GLfloat velocidade);
        void updateMissilPosition();
        void desenha();
        GLfloat get_x();
        GLfloat get_y();
        GLfloat get_z();
        ~Missil();
};

#endif