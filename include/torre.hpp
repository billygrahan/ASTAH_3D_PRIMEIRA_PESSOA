#ifndef TORRE_H
#define TORRE_H

#include <GL/glut.h>
#include <cmath>
#include "../include/textura.hpp"

class Torre{
    private:
        // GLfloat luzAmbiente[4] = {0.2, 0.2, 0.2, 1.0}; // Cor ambiente da luz
        // GLfloat luzDifusa[4] = {1.0, 1.0, 1.0, 1.0};   // Cor difusa da luz
        // GLfloat luzEspecular[4] = {1.0, 1.0, 1.0, 1.0}; // Cor especular da luz
        // GLfloat posicaoLuz[4] = {0.0, 20.0, 10.0, 1.0}; // Posição da luz

        // GLfloat materialAmbiente[4] = {0.2, 0.2, 0.2, 1.0}; // Cor ambiente do material
        // GLfloat materialDifuso[4] = {1.0, 1.0, 1.0, 1.0};   // Cor difusa do material
        // GLfloat materialEspecular[4] = {1.0, 1.0, 1.0, 1.0}; // Cor especular do material
        // GLfloat brilhoMaterial = 50.0; // Coeficiente de brilho do material

        GLfloat altura;
        GLfloat largura;
        Textura *textura_bandeira_br;
        Textura *textura_bandeira_jap;
        Textura *textura_torre;
        Textura *textura_torre_topo;
    protected:
        void bandeiras(GLint text);
        void predio_principal();
    public:
        Torre(GLfloat largura, GLfloat altura);
        void desenha();
        GLfloat get_altura();
        void calcula_normal(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
        ~Torre();
};

#endif