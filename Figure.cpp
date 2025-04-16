//
// Created by Nazar on 12.03.2025.
//

#include "Figure.h"

Figure::Figure(float *vertices, unsigned int *indices, float *colors, float *texture_coords,
               size_t vertices_count, size_t indices_count, size_t colors_count, size_t texture_count,
               const char *frag_shader_file, const char *vert_shader_file,
               const char *texture_file): shader(frag_shader_file, vert_shader_file), texture(texture_file) {
    this->vertices = vertices;
    this->indices = indices;
    this->colors = colors;
    this->texture_coords = texture_coords;
    this->vertices_count = vertices_count;
    this->indices_count = indices_count;
    this->colors_count = colors_count;
    this->texture_count = texture_count;
}

void Figure::prepare_draw(unsigned int &VAO, unsigned int *VBO, unsigned int &EBO) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &EBO);
    glGenBuffers(3, VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, this->vertices_count, this->vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices_count, this->indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(GL_ARRAY_BUFFER, this->colors_count, this->colors, GL_STATIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
    glBufferData(GL_ARRAY_BUFFER, this->texture_count, this->texture_coords, GL_STATIC_DRAW);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(2);
}

void Figure::draw(unsigned int &VAO) {
    // float timeValue = glfwGetTime();
    // float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
    // int vertexColorLocation = glGetUniformLocation(this->shader.get_shader_program(), "myColor");
    glUseProgram(this->shader.get_shader_program());
    // glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
    this->texture.use();
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Figure::set_shader(Shader &shader) {
    this->shader = shader;
}

void Figure::delete_shader() {
    glDeleteProgram(this->shader.get_shader_program());
}
