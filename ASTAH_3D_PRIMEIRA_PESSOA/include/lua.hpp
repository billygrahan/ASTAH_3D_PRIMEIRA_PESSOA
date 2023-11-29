#ifndef LUA_H
#define LUA_H

#include <GL/glut.h>
#include <cmath>
#include <SOIL/SOIL.h>

class Lua{
    private:
        GLfloat raio;
    public:
        Lua(GLfloat raio);
        void desenha();
};
#endif