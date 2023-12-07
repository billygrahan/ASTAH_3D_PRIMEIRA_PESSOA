#ifndef PREDIOS_H
#define PREDIOS_H

#include <GL/glut.h>
#include <cmath>
#include "../include/textura.hpp"

class Predios{
    private:
        GLfloat pos;
        GLfloat altura;
        GLfloat largura;
        Textura *textura_predios;
        Textura *textura_predios_topo;
        int colisao;
    protected:
        void predio_principal();
    public:
        Predios(GLfloat largura, GLfloat altura, GLfloat pos);
        void desenha();
        GLfloat get_altura();
        ~Predios();
};

#endif