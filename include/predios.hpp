#ifndef PREDIOS_H
#define PREDIOS_H

#include <GL/glut.h>
#include <cmath>
#include "../include/textura.hpp"

class Predios{
    private:
        // GLfloat luzAmbiente[4] = {0.2, 0.2, 0.2, 1.0}; // Cor ambiente da luz
        // GLfloat luzDifusa[4] = {1.0, 1.0, 1.0, 1.0};   // Cor difusa da luz
        // GLfloat luzEspecular[4] = {1.0, 1.0, 1.0, 1.0}; // Cor especular da luz
        // GLfloat posicaoLuz[4] = {0.0, 20.0, 10.0, 1.0}; // Posição da luz

        // GLfloat materialAmbiente[4] = {0.2, 0.2, 0.2, 1.0}; // Cor ambiente do material
        // GLfloat materialDifuso[4] = {1.0, 1.0, 1.0, 1.0};   // Cor difusa do material
        // GLfloat materialEspecular[4] = {1.0, 1.0, 1.0, 1.0}; // Cor especular do material
        // GLfloat brilhoMaterial = 50.0; // Coeficiente de brilho do material

        GLfloat pos;
        GLfloat altura;
        GLfloat largura;
        Textura *textura_predios;
        Textura *textura_predios_topo;
    protected:
        void predio_principal();
    public:
        Predios(GLfloat largura, GLfloat altura, GLfloat pos);
        void desenha();
        GLfloat get_altura();
        ~Predios();
};

#endif