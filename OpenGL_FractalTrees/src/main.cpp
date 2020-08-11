#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include "FractalTree.h"

//         Welcome to the basic OpenGL
//            GLEW & GLFW project!
//
//   Make sure you've got Dependencies folder 
//       in your solution directory to be
//             ready for creating.

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glewInit();

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1001, 1001, "OpenGL Fractal Trees", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        std::cout << "Error! glewInit failed." << std::endl;

    std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

    /* Smooth edges */
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);

    /* Global settings */
    glClearColor(0.0, 0.0, 0.0, 1);
    glPointSize(3.0);
    glLineWidth(1.3);

    FractalTree tree;
#ifdef _DEBUG
    tree.params.should_be_recorded = true;
#endif
    vert2d start = { 0.0, -1.0 };
    double xpos, ypos;
    int width, height;
    GLfloat initial_factor = 0.5;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Refresh params */
        glfwGetCursorPos(window, &xpos, &ypos);
        glfwGetWindowSize(window, &width, &height);
        tree.params.length_factor = ypos / height;
        tree.params.shift_angle = xpos / width * 180.0;

        int mouse_left = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
        int mouse_right = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);
        if (mouse_left == GLFW_PRESS)
            initial_factor *= 0.8;
        else if (mouse_right == GLFW_PRESS)
            initial_factor *= 1.2;

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        vert2d vert = { 0.0, -1.0 };

        tree.Draw(start, initial_factor, 0.0);
        glfwSetWindowTitle(window, ("OpenGL Fractal Trees2    I    " + std::to_string(tree.info.fps) + " FPS").c_str());

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}