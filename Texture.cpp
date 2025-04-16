//
// Created by Nazar on 16.04.2025.
//

#include "Texture.h"

#include <glad/glad.h>
#include <iostream>
#include "stb_image.h"

Texture::Texture(const char *texture_file) {
    glGenTextures(1, &this->texture);
    glBindTexture(GL_TEXTURE_2D, this->texture);

    this->data = stbi_load(texture_file, &this->width, &this->height, &this->nrChannels, 0);

    if (this->data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->width, this->height, 0,
                     GL_RGB, GL_UNSIGNED_BYTE, this->data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cerr << "ERROR::TEXTURE::LOAD\n" << "Can't load the texture" << std::endl;
    }

    stbi_image_free(this->data);
}

void Texture::use() {
    glBindTexture(GL_TEXTURE_2D, this->texture);
}


