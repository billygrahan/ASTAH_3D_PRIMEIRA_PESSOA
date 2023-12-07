#include "../include/textura.hpp" 


Textura::Textura(const char* caminho){
    const char* diretorio = "../texturas/";

    size_t tam_textura = strlen(diretorio) + strlen(caminho);

    char* textura = new char[tam_textura];
    strcpy(textura, diretorio);
    strcat(textura, caminho);

    // Carregar a textura
    textureID = SOIL_load_OGL_texture(
        textura,  // Substitua com o caminho para sua textura
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y
    );

    if (textureID == 0) {
    const char* error = SOIL_last_result();
    printf("Erro ao carregar textura: %s\n", error);
    }

    delete[] textura;
}

Textura::~Textura(){
    glDeleteTextures(1, &textureID);
}

GLuint Textura::get_textureID(){
    return textureID;
}