//
// Created by Nazar on 12.03.2025.
//

#ifndef WINDOW_H
#define WINDOW_H

#include "Figure.h"

class Window {
private:
    unsigned int VAO, EBO;
    unsigned int VBO[2] = {NULL, NULL};
    GLFWwindow *window;
    Figure *figure = nullptr;

private:
    void init_window(int width, int height, const char *title);

    void move_context();

    static void framebufferSizeCallback(GLFWwindow *window, int width, int height);

    static void processInput(GLFWwindow *window);

public:
    Window(int width, int height, const char *title);

    int run();

    void set_viewport(int x, int y, int width, int height);

    void set_figure(Figure *figure_to_draw);
};


#endif //WINDOW_H
