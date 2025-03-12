//
// Created by Nazar on 12.03.2025.
//

#ifndef SHADER_H
#define SHADER_H
#include <glad/glad.h>
#include <iostream>

class Shader {
private:
    unsigned int shader_program;

private:
    void create_fragment_shader(unsigned int fragment_shader);
    void create_vertex_shader(unsigned int vertex_shader);

    static void check_shader_compilation(unsigned int shader, const char* type);
    void check_linking_integrity();

public:
    Shader();
    unsigned int get_shader_program();
};



#endif //SHADER_H
