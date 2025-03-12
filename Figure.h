//
// Created by Nazar on 12.03.2025.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shader.h"
#include <glfw3.h>

class Figure {
private:
    float* vertices;
    unsigned int* indices;

    size_t indices_count, vertices_count;

    Shader shader;

public:
    Figure(float* vertices, unsigned int* indices, size_t vertices_count, size_t indices_count);
    void prepare_draw(unsigned int& VAO, unsigned int& VBO,  unsigned int& EBO);
    void draw(unsigned int& VAO);
    void set_shader(Shader& shader);
    void delete_shader();
};



#endif //TRIANGLE_H
