#ifndef LUA_H
#define LUA_H

#include <GL/glut.h>
#include <cmath>
#include <SOIL/SOIL.h>
#include <string>
#include "../include/textura.hpp"

class Lua{
    private:
        GLfloat raio;
        Textura *textura_lua;
    public:
        Lua(GLfloat raio);
        void desenha();
        ~Lua();
};
#endif