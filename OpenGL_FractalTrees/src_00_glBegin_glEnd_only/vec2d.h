#pragma once
#include <GLFW/glfw3.h>
#include "vert2d.h"

class vec2d
{
public:
    GLfloat m_x, m_y;

    vec2d() {};
    vec2d(GLfloat x, GLfloat y);
    vec2d& operator=(const vec2d& src);
    vert2d& Draw(GLfloat len_factor, vert2d& start);
    void Rotate(GLfloat angle);
};