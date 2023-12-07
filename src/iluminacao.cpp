#include "../include/iluminacao.hpp"

void Iluminacao::set_posicao(GLfloat x, GLfloat y, GLfloat z, GLfloat w){
    this->posicao[0] = x;
    this->posicao[1] = y;
    this->posicao[2] = z;
    this->posicao[3] = w;
}

void Iluminacao::set_ambiente(GLfloat r, GLfloat g, GLfloat b, GLfloat a){
    this->ambiente[0] = r;
    this->ambiente[1] = g;
    this->ambiente[2] = b;
    this->ambiente[3] = a;
}

void Iluminacao::set_difusa(GLfloat r, GLfloat g, GLfloat b, GLfloat a){
    this->difusa[0] = r;
    this->difusa[1] = g;
    this->difusa[2] = b;
    this->difusa[3] = a;
}

void Iluminacao::set_especular(GLfloat r, GLfloat g, GLfloat b, GLfloat a){
    this->especular[0] = r;
    this->especular[1] = g;
    this->especular[2] = b;
    this->especular[3] = a;
}

void Iluminacao::set_brilho(GLfloat brilho){
    this->brilho[0] = brilho;
}

void Iluminacao::mover_frente(){
    posicao[2] += 0.1;
    std::cout << "posicao[2] = " << posicao[2] << std::endl;
}

void Iluminacao::mover_tras(){
    posicao[2] -= 0.1;
    std::cout << "posicao[2] = " << posicao[2] << std::endl;
}

void Iluminacao::mover_direita(){
    posicao[0] -= 0.1;
    std::cout << "posicao[0] = " << posicao[0] << std::endl;
}

void Iluminacao::mover_esquerda(){
    posicao[0] += 0.1;
    std::cout << "posicao[0] = " << posicao[0] << std::endl;
}

void Iluminacao::mover_cima(){
    posicao[1] -= 0.1;
    std::cout << "posicao[1] = " << posicao[1] << std::endl;
}

void Iluminacao::mover_baixo(){
    posicao[1] += 0.1;
    std::cout << "posicao[1] = " << posicao[1] << std::endl;
}

void Iluminacao::ativa(){
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_POSITION, this->posicao);
    glLightfv(GL_LIGHT0, GL_AMBIENT, this->ambiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, this->difusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, this->especular);
    glLightfv(GL_LIGHT0, GL_SHININESS, this->brilho);
    glEnable(GL_LIGHT0);
}

void Iluminacao::desativa(){
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);
}

Iluminacao::~Iluminacao(){
    // Empty
}