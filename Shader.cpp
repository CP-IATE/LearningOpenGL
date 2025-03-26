//
// Created by Nazar on 12.03.2025.
//

#include "Shader.h"
#include <fstream>
#include <sstream>

void Shader::create_fragment_shader(unsigned int fragment_shader, const char *frag_shader_file) {
    const char *fragment_shader_source = read_shader(frag_shader_file).c_str();

    glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
    glCompileShader(fragment_shader);

    check_shader_compilation(fragment_shader, "FRAGMENT");
}

void Shader::create_vertex_shader(unsigned int vertex_shader, const char *vert_shader_file) {
    const char *vertex_shader_source = read_shader(vert_shader_file).c_str();

    glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
    glCompileShader(vertex_shader);

    check_shader_compilation(vertex_shader, "VERTEX");
}

void Shader::check_shader_compilation(unsigned int shader, const char *type) {
    int success;
    char info_log[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, info_log);
        std::cout << "ERROR::SHADER::" << type << "::COMPILATION_FAILED\n" << info_log << std::endl;
    }
}

void Shader::check_linking_integrity() {
    int success;
    char infoLog[512];
    glGetProgramiv(this->shader_program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(this->shader_program, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

std::string Shader::read_shader(const char *filename) {
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "ERROR::SHADER::READ\n" << "Unable to open and read file: " << filename << std::endl;
        return "";
    }

    std::stringstream content;

    content << file.rdbuf();

    file.close();
    return content.str();
}

Shader::Shader(const char *frag_shader_file, const char *vert_shader_file) {
    unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    create_vertex_shader(vertex_shader, vert_shader_file);

    unsigned int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    create_fragment_shader(fragment_shader, frag_shader_file);

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
