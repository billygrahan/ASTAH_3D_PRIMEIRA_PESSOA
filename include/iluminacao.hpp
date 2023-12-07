#ifndef ILUMINACAO_H
#define ILUMINACAO_H

#include <GL/glut.h>
#include <GL/gl.h>
#include <cmath>
#include <iostream>

class Iluminacao{
    private:
        GLfloat posicao[4];
        GLfloat ambiente[4];
        GLfloat difusa[4];
        GLfloat especular[4];
        GLfloat brilho[1];
        GLfloat direcaoSpot[3];
        GLfloat expoenteSpot[1];
        GLfloat corteSpot[1];
        GLfloat constanteAttenuation[1];
        GLfloat linearAttenuation[1];
        GLfloat quadraticAttenuation[1];

    public:
        Iluminacao()
        {
            this->posicao[0] = 20.0f;
            this->posicao[1] = 20.0f;
            this->posicao[2] = 20.0f;
            this->posicao[3] = 1.0f;

            this->ambiente[0] = 0.2f;
            this->ambiente[1] = 0.2f;
            this->ambiente[2] = 0.2f;
            this->ambiente[3] = 1.0f;

            this->difusa[0] = 1.5f;
            this->difusa[1] = 1.5f;
            this->difusa[2] = 1.5f;
            this->difusa[3] = 1.0f;

            this->especular[0] = 2.0f;
            this->especular[1] = 2.0f;
            this->especular[2] = 2.0f;
            this->especular[3] = 1.0f;

            this->brilho[0] = 0.0f;

            this->direcaoSpot[0] = 0.0f;
            this->direcaoSpot[1] = 0.0f;
            this->direcaoSpot[2] = 0.0f;

            this->expoenteSpot[0] = 0.0f;

            this->corteSpot[0] = 180.0f;

            this->constanteAttenuation[0] = 0.2f;

            this->linearAttenuation[0] = 0.0f;

            this->quadraticAttenuation[0] = 0.0f;
        }
        void setPosicao(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
        void setAmbiente(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
        void setDifusa(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
        void setEspecular(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
        void setBrilho(GLfloat brilho);

        void ativa();
        void desativa();
        ~Iluminacao();
};

#endif