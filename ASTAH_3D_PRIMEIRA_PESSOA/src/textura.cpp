#include "../include/textura.hpp" 
#include <GL/glut.h>
#include <cmath>
#include <SOIL/SOIL.h>
#include <cstdio>


Textura::Textura(const string& caminho){
    // Carregar a textura
    textureID = SOIL_load_OGL_texture(
        caminho.c_str(),  // Substitua com o caminho para sua textura
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y
    );

    if (textureID == 0) {
    const char* error = SOIL_last_result();
    printf("Erro ao carregar textura: %s\n", error);
    }
}

Textura::~Textura(){
    glDeleteTextures(1, &textureID);
}

GLuint Textura::get_textureID(){
    return textureID;
}