#include "../include/iluminacao.hpp"

void Iluminacao::setPosicao(GLfloat x, GLfloat y, GLfloat z, GLfloat w){
    this->posicao[0] = x;
    this->posicao[1] = y;
    this->posicao[2] = z;
    this->posicao[3] = w;
}

void Iluminacao::setAmbiente(GLfloat r, GLfloat g, GLfloat b, GLfloat a){
    this->ambiente[0] = r;
    this->ambiente[1] = g;
    this->ambiente[2] = b;
    this->ambiente[3] = a;
}

void Iluminacao::setDifusa(GLfloat r, GLfloat g, GLfloat b, GLfloat a){
    this->difusa[0] = r;
    this->difusa[1] = g;
    this->difusa[2] = b;
    this->difusa[3] = a;
}

void Iluminacao::setEspecular(GLfloat r, GLfloat g, GLfloat b, GLfloat a){
    this->especular[0] = r;
    this->especular[1] = g;
    this->especular[2] = b;
    this->especular[3] = a;
}

void Iluminacao::setBrilho(GLfloat brilho){
    this->brilho[0] = brilho;
}

void Iluminacao::ativa(){
    glLightfv(GL_LIGHT0, GL_POSITION, this->posicao);
    glLightfv(GL_LIGHT0, GL_AMBIENT, this->ambiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, this->difusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, this->especular);
    glLightfv(GL_LIGHT0, GL_SHININESS, this->brilho);
    glEnable(GL_LIGHT0);
}

void Iluminacao::desativa(){
    glDisable(GL_LIGHT0);
}

Iluminacao::~Iluminacao(){
    // Empty
}