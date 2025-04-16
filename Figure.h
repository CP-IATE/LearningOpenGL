//
// Created by Nazar on 12.03.2025.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shader.h"
#include "Texture.h"
#include <glfw3.h>

class Figure {
private:
    float *vertices;
    unsigned int *indices;
    float *colors;
    float *texture_coords;
    size_t indices_count, vertices_count, colors_count, texture_count;

    Shader shader;

    Texture texture;

public:
    Figure(float *vertices, unsigned int *indices, float *colors, float *texture_coords,
           size_t vertices_count, size_t indices_count, size_t colors_count, size_t texture_count,
           const char *frag_shader_file, const char *vert_shader_file, const char *texture_file);

    void prepare_draw(unsigned int &VAO, unsigned int *VBO, unsigned int &EBO);

    void draw(unsigned int &VAO);

    void set_shader(Shader &shader);

    void set_texture(Texture &texture);

    void delete_shader();
};


#endif //TRIANGLE_H
