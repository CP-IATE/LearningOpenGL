//
// Created by Nazar on 12.03.2025.
//

#ifndef WINDOW_H
#define WINDOW_H

#include "Figure.h"

class Window {
private:
    unsigned int VAO, EBO;
    unsigned int VBO[3];
    GLFWwindow *window;
    Figure *figure = nullptr;
    bool linemode = false;

private:
    void init_window(int width, int height, const char *title);

    void move_context();

    static void framebufferSizeCallback(GLFWwindow *window, int width, int height);

    static void processInput(GLFWwindow *window);

public:
    Window(int width, int height, const char *title, bool linemode = false);

    int run();

    void set_viewport(int x, int y, int width, int height);

    void set_figure(Figure *figure_to_draw);
};


#endif //WINDOW_H
