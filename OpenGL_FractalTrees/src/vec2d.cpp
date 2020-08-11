#include "vec2d.h"
#define _USE_MATH_DEFINES
#include <cmath>

vec2d::vec2d(GLfloat x, GLfloat y) : m_x(x), m_y(y) {}

vec2d& vec2d::operator=(const vec2d& src)
{
    if (this != &src)
    {
        this->m_x = src.m_x;
        this->m_y = src.m_y;
    }

    return *this;
}

vert2d& vec2d::Draw(GLfloat len_factor, vert2d& start)
{
    vert2d end;
    end.m_x = this->m_x * len_factor + start.m_x;
    end.m_y = this->m_y * len_factor + start.m_y;

    glVertex2f(start.m_x, start.m_y);
    glVertex2f(end.m_x, end.m_y);

    //DrawVert2d(start, 0);
    //DrawVert2d(end, 1);

    return end;
}

void vec2d::Rotate(GLfloat angle)
{
    GLfloat theta = angle * (M_PI / 180);
    GLfloat cs = cos(theta);
    GLfloat sn = sin(theta);

    vec2d res;
    res.m_x = this->m_x * cs - this->m_y * sn;
    res.m_y = this->m_x * sn + this->m_y * cs;
    *this = res;
}