cmake_minimum_required(VERSION 3.30)
project(TestingOpenGL)

set(CMAKE_CXX_STANDARD 20)

add_executable(TestingOpenGL main.cpp glad.c
        window.cpp
        window.h
        Figure.cpp
        Figure.h
        Shader.cpp
        Shader.h
        stb_image.h
        stb_image.cpp
        Texture.cpp
        Texture.h
)

add_library(GLFW STATIC IMPORTED)
add_library(OpenGL STATIC IMPORTED)

set_target_properties(GLFW PROPERTIES
        IMPORTED_LOCATION "D:/LibsForOpenGL/glfw3.lib"
        INTERFACE_INCLUDE_DIRECTORIES "D:/LibsForOpenGL/Include/GLFW"
)
set_target_properties(OpenGL PROPERTIES
        IMPORTED_LOCATION "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.22621.0/um/x64/OpenGL32.Lib"
)

target_link_libraries(TestingOpenGL PRIVATE GLFW)
target_include_directories(TestingOpenGL PRIVATE "D:/LibsForOpenGL/Include")

add_custom_target(copy_resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/shaders/
        $<TARGET_FILE_DIR:TestingOpenGL>/shaders
        COMMENT "Copying shaders"
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/textures/
        $<TARGET_FILE_DIR:TestingOpenGL>/textures
        COMMENT "Copying textures"
)

add_dependencies(TestingOpenGL copy_resources)

find_package(glm CONFIG REQUIRED)
target_link_libraries(TestingOpenGL PRIVATE glm::glm)