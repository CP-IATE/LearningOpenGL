#include "Window.h"
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main() {
    float vertices[] = {
        0.0f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        // -0.5f, 0.5f, 0.0f,
        // -0.6f, 0.8f, 0.0f
    };

    float vertices_colors[] = {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f
    };

    unsigned int indices[] = {
        0, 1, 2
        // 0, 1, 3,
        // 0, 1, 4,
    };

    auto window = Window(800, 600, "Hello");

    auto figure_to_draw = Figure(vertices, indices, vertices_colors, sizeof(vertices), sizeof(indices),
                                 sizeof(vertices_colors), "shaders/frag.glsl", "shaders/vert.glsl");
    window.set_figure(&figure_to_draw);

    window.run();
}
