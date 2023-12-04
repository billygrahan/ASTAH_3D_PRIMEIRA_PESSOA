#ifndef TORRE_H
#define TORRE_H

#include <GL/glut.h>
#include <cmath>

class Torre{
    private:
        double altura;
        double largura;
    public:
        Torre(double largura, double altura);
        void desenha();
        double get_altura();
};

#endif