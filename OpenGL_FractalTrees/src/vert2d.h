#pragma once
#include <GLFW/glfw3.h>

class vert2d
{
public:
    GLfloat m_x, m_y;

    vert2d() {}
    vert2d(GLfloat x, GLfloat y);
    void Draw(int color);
};