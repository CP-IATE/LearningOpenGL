#include "Window.h"
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main() {
    float vertices[] = {
        0.5f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f
    };

    float vertices_colors[] = {
        1.0f, 0.0f, 0.0f,
        0.5f, 0.0f, 0.5f,
        0.0f, 0.0f, 1.0f,
        0.5f, 0.0f, 0.5f
    };

    float texture_coords[] = {
        1.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 0.0f,
        0.0f, 1.0f
    };

    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3,
    };

    auto window = Window(800, 600, "Hello");

    auto figure_to_draw = Figure(vertices, indices, vertices_colors, texture_coords,
                                 sizeof(vertices), sizeof(indices), sizeof(vertices_colors), sizeof(texture_coords),
                                 "shaders/frag.glsl", "shaders/vert.glsl", "textures/container.jpg");
    window.set_figure(&figure_to_draw);

    window.run();
}
