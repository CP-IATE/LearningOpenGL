//
// Created by Nazar on 12.03.2025.
//

#include "Shader.h"

void Shader::create_fragment_shader(unsigned int fragment_shader) {
    const char *fragment_shader_source = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\0";

    glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
    glCompileShader(fragment_shader);

    check_shader_compilation(fragment_shader, "FRAGMENT");
}

void Shader::create_vertex_shader(unsigned int vertex_shader) {
    const char *vertex_shader_source = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

    glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
    glCompileShader(vertex_shader);

    check_shader_compilation(vertex_shader, "VERTEX");
}

void Shader::check_shader_compilation(unsigned int shader, const char* type) {
    int  success;
    char info_log[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, info_log);
        std::cout << "ERROR::SHADER::" << type <<"::COMPILATION_FAILED\n" << info_log << std::endl;
    }
}

void Shader::check_linking_integrity() {
    int  success;
    char infoLog[512];
    glGetProgramiv(this->shader_program, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(this->shader_program, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

Shader::Shader() {
    unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    create_vertex_shader(vertex_shader);

    unsigned int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    create_fragment_shader(fragment_shader);

    this->shader_program = glCreateProgram();
    glAttachShader(this->shader_program, vertex_shader);
    glAttachShader(this->shader_program, fragment_shader);
    glLinkProgram(this->shader_program);

    check_linking_integrity();
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
}

unsigned int Shader::get_shader_program() {
    return this->shader_program;
}
