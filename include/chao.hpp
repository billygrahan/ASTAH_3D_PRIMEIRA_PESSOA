#ifndef CHAO_H
#define CHAO_H

#include <GL/glut.h>
#include <cmath>

class Chao{
    private:
        double largura;
        double especura;
    public:
        Chao(double largura, double especura);
        void desenha();
};

#endif