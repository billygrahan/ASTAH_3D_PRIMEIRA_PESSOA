#ifndef TEXTURA_H
#define TEXTURA_H

#include <GL/glut.h>
#include <cmath>
#include <SOIL/SOIL.h>
#include <string>
#include <cstdio>

using namespace std;

class Textura{
    private:
        GLuint textureID;
    public:
        Textura(const string& caminho);
        ~Textura();
        GLuint get_textureID();
};

#endif