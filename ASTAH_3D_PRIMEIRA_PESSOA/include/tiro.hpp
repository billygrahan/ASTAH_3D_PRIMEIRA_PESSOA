#ifndef TIRO_H
#define TIRO_H

#include <GL/glut.h>
#include <cmath>
#include <SOIL/SOIL.h>
#include "../include/textura.hpp"
#include "../include/torre.hpp"

class Tiro{
    private:
        GLfloat raio;
        Textura *textura_tiro;
        GLfloat x_tiro;
        GLfloat y_tiro;
        GLfloat z_tiro;
        GLfloat velocidade;
        GLfloat aux_x, aux_y, aux_z;
        bool disparo;
        bool atualizacao;
    private:
        void esfera();
    public:
        Tiro(GLfloat raio);
        void desenha();
        void updateTiroPosition(const GLfloat *x_cam, const GLfloat * y_cam, const GLfloat * z_cam, int* cont_tiros);
        void set_disparo(bool disparo);
};

#endif