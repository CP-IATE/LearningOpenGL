#include "Window.h"
// #pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main() {
    float vertices[] = {
        0.25f, 0.25f, 0.2f, //top-right-front      0
        0.25f, 0.25f, -0.2f, //top-right-back      1
        -0.25f, -0.25f, 0.2f, //bottom-left-front  2
        -0.25f, -0.25f, -0.2f, //bottom-left-back  3
        0.25f, -0.25f, 0.2f, //bottom-right-front  4
        0.25f, -0.25f, -0.2f, //bottom-right-back  5
        -0.25f, 0.25f, 0.2f, //top-left-front      6
        -0.25f, 0.25f, -0.2f, //top-left-back      7
        0.0f, 0.65f, 0.0f //hat                      8
    };

    float vertices_colors[] = {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f,
        0.5f, 0.0f, 0.5f
    };

    float texture_coords[] = {
        1.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 0.0f,
        0.0f, 1.0f
    };

    unsigned int indices[] = {
        0, 1,
        0, 4,
        0, 6,
        0, 8,
        1, 5,
        1, 7,
        1, 8,
        2, 4,
        2, 3,
        2, 6,
        3, 5,
        3, 7,
        4, 5,
        6, 7,
        6, 8,
        7, 8,
    };

    auto window = Window(800, 600, "Hello");

    auto figure_to_draw = Figure(vertices, indices, vertices_colors, texture_coords,
                                 sizeof(vertices), sizeof(indices), sizeof(vertices_colors), sizeof(texture_coords),
                                 "shaders/frag.glsl", "shaders/vert.glsl", "textures/container.jpg");
    window.set_figure(&figure_to_draw);

    window.run();
}
