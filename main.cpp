#include "Window.h"

int main() {
    float vertices[] = {
        0.5f,  0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
       -0.5f, -0.5f, 0.0f,
       -0.5f,  0.5f, 0.0f,
        -0.6f, 0.8f, 0.0f
    };
    unsigned int indices[] = {
        0, 1, 3,
        0, 1, 4,
    };

    auto window = Window(800, 600, "Hello");

    auto figure_to_draw = Figure(vertices, indices, sizeof(vertices), sizeof(indices));
    window.set_figure(&figure_to_draw);

    window.run();
}
