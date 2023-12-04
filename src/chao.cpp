#include "../include/chao.hpp"
#include "../include/textura.hpp"



Chao::Chao(double largura, double especura){
    this->largura = largura;
    this->especura = especura;
}

void Chao::desenha(){
    /*glBegin(GL_TRIANGLE_FAN);
        glVertex3f(largura, 0.0, largura);
        glVertex3f(-largura, 0.0, largura);

        glVertex3f(-largura, 0.0, largura);
        glVertex3f(-largura, 0.0, -largura);

        glVertex3f(-largura, 0.0, -largura);
        glVertex3f(largura, 0.0, -largura);

        glVertex3f(largura, 0.0, -largura);
        glVertex3f(largura, 0.0, largura);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(largura, -0.5, largura);
        glVertex3f(-largura, -0.5, largura);

        glVertex3f(-largura, -0.5, largura);
        glVertex3f(-largura, -0.5, -largura);

        glVertex3f(-largura, -0.5, -largura);
        glVertex3f(largura, -0.5, -largura);

        glVertex3f(largura, -0.5, -largura);
        glVertex3f(largura, -0.5, largura);

    glEnd();*/
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(largura, 0.0, largura);
        glVertex3f(-largura, 0.0, largura);
        glVertex3f(largura, -especura, largura);
        glVertex3f(-largura, -especura, largura);

        glVertex3f(-largura, 0.0, largura);
        glVertex3f(-largura, 0.0, -largura);
        glVertex3f(-largura, -especura, largura);
        glVertex3f(-largura, -especura, -largura);

        glVertex3f(-largura, 0.0, -largura);
        glVertex3f(largura, 0.0, -largura);
        glVertex3f(-largura, -especura, -largura);
        glVertex3f(largura, -especura, -largura);

        glVertex3f(largura, 0.0, -largura);
        glVertex3f(largura, 0.0, largura);
        glVertex3f(largura, -especura, -largura);
        glVertex3f(largura, -especura, largura);

    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
        glVertex3f(largura, 0.0, largura);
        glVertex3f(-largura, 0.0, largura);
        glVertex3f(largura, -especura, largura);
        glVertex3f(-largura, -especura, largura);

        glVertex3f(-largura, 0.0, largura);
        glVertex3f(-largura, 0.0, -largura);
        glVertex3f(-largura, -especura, largura);
        glVertex3f(-largura, -especura, -largura);

        glVertex3f(-largura, 0.0, -largura);
        glVertex3f(largura, 0.0, -largura);
        glVertex3f(-largura, -especura, -largura);
        glVertex3f(largura, -especura, -largura);

        glVertex3f(largura, 0.0, -largura);
        glVertex3f(largura, 0.0, largura);
        glVertex3f(largura, -especura, -largura);
        glVertex3f(largura, -especura, largura);

        glVertex3f(largura, 0.0, largura);
        glVertex3f(largura, -especura, largura);

        glVertex3f(-largura, 0.0, largura);
        glVertex3f(-largura, -especura, largura);

        glVertex3f(-largura, 0.0, -largura);
        glVertex3f(-largura, -especura, -largura);

        glVertex3f(largura, 0.0, -largura);
        glVertex3f(largura, -especura, -largura);

    glEnd();
}

