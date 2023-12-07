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
        bool colisao;
    protected:
        void predio_principal();
    public:
        Predios(GLfloat largura, GLfloat altura);
        void desenha();
        GLfloat get_altura();
        GLfloat get_largura();
        void set_colisao(bool colisao);
        ~Predios();
};

#endif