//
// Created by Nazar on 16.04.2025.
//

#ifndef TEXTURE_H
#define TEXTURE_H


class Texture {
private:
    unsigned char *data = nullptr;

    int width, height, nrChannels;

    unsigned int texture;

public:
    Texture(const char *texture_file);

    void use();
};


#endif //TEXTURE_H
