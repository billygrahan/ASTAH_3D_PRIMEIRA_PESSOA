#ifndef PREDIOS_H
#define PREDIOS_H

#include <GL/glut.h>
#include <cmath>
#include "../include/textura.hpp"

class Predios{
    private:
        GLfloat altura;
        GLfloat largura;
        Textura *textura_predios;
        Textura *textura_predios_topo;
        int colisao;
    protected:
        void predio_principal();
    public:
        Predios(GLfloat largura, GLfloat altura);
        void desenha();
        GLfloat get_altura();
        void calcula_normal(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
        ~Predios();
};

#endif