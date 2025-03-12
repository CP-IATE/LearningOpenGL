//
// Created by Nazar on 12.03.2025.
//

#include "Figure.h"

Figure::Figure(float* vertices, unsigned int* indices, size_t vertices_count, size_t indices_count) {
    this->vertices = vertices;
    this->indices = indices;
    this->vertices_count = vertices_count;
    this->indices_count = indices_count;
}

void Figure::prepare_draw(unsigned int &VAO, unsigned int &VBO, unsigned int &EBO) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &EBO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, this->vertices_count, this->vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices_count, this->indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void Figure::draw(unsigned int& VAO) {

    glUseProgram(this->shader.get_shader_program());
    glBindVertexArray(VAO);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}

void Figure::set_shader(Shader& shader) {
    this->shader = shader;
}

void Figure::delete_shader() {
    glDeleteProgram(this->shader.get_shader_program());
}
