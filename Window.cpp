//
// Created by Nazar on 12.03.2025.
//

#include "Window.h"

Window::Window(int width, int height, const char *title) {
    init_window(width, height, title);
    move_context();
    set_viewport(0, 0, width, height);
}

void Window::init_window(int width, int height, const char *title) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->window = glfwCreateWindow(width, height, title, NULL, NULL);

    if (this->window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(-1);
    }
}

//Changing current glfw context to created window
void Window::move_context() {
    glfwMakeContextCurrent(this->window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(-1);
    }
}

int Window::run() {
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    if (this->figure != nullptr) {
        this->figure->prepare_draw(VAO, VBO, EBO);
    }

    while (!glfwWindowShouldClose(this->window)) {
        processInput(this->window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        if (this->figure != nullptr) {
            this->figure->draw(VAO);
        }

        glfwSwapBuffers(this->window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(2, VBO);
    glDeleteBuffers(1, &EBO);
    if (this->figure != nullptr) this->figure->delete_shader();
    glfwTerminate();
    return 0;
}

void Window::set_viewport(int x, int y, int width, int height) {
    glViewport(x, y, width, height);
}

void Window::set_figure(Figure *figure_to_draw) {
    this->figure = figure_to_draw;
}

void Window::framebufferSizeCallback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

void Window::processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}
