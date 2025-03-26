# First try on OpenGL
This is my first project connected to OpenGL. I will gladly listen to criticism and advice on this matter. At the current stage all actual code can be found in 
[ClassBased](https://github.com/CP-IATE/LearningOpenGL/tree/ClassBased) branch. I'm trying to implement basic OpenGL staff in OOP style there.

# Functionality
As for now, program can only display simple and slightly complex 2D-figures on the screed. In the furute updetes multiple figures and 3D-figures displaying will be added.

# Instalation
To try existing code you need to clone [ClassBased](https://github.com/CP-IATE/LearningOpenGL/tree/ClassBased) branch, install GLFW.
Instalation guidlines can be found [here](https://learnopengl.com/Getting-started/Creating-a-window)
Prefered lib file structure
```
lirary:
  .lib file
  include:
    GLFW:
      ...
```
After instalation change locations in CMakeList.txt file to locations, where you stored GLFW.
```
...
set_target_properties(GLFW PROPERTIES
        IMPORTED_LOCATION "YOUR_PATH_TO_LIB_FILE"
        INTERFACE_INCLUDE_DIRECTORIES "YOUR_PATH_TO_GLFW_FOLDER"
)
...
target_include_directories(TestingOpenGL PRIVATE "YOUR_PATH_TO_INCLUDE_FOLDER")
```
---
If you just want to see compiled result simply dowload content from [cmake-build-release](https://github.com/CP-IATE/LearningOpenGL/tree/ClassBased/cmake-build-release) folder and then run TestingOpenGL.exe
