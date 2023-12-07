#ifndef CHAO_H
#define CHAO_H

#include <GL/glut.h>
#include <cmath>
#include "../include/textura.hpp"

class Chao{
    private:
        GLfloat raio;
        GLfloat especura;
        Textura *textura_chao;
        Textura *textura_pista;
    protected:
        void grama();
        void pista();
        void arvore_1();
    public:
        Chao(GLfloat largura, GLfloat especura);
        void desenha();
        GLfloat get_raio();
        ~Chao();
};

#endif