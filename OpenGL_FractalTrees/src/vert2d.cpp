#include "vert2d.h"

vert2d::vert2d(GLfloat x, GLfloat y) : m_x(x), m_y(y) {}

void vert2d::Draw(int color)
{
    glEnd();

    if (color == 0)
        glPointSize(3.0);
    else if (color == 1)
        glPointSize(5.0);
    else
        glPointSize(9.0);

    glBegin(GL_POINTS);

    if (color == 0)
        glColor3f(1.0, 1.0, 1.0);
    else if (color == 1)
        glColor3f(0.0, 0.0, 0.0);
    else
        glColor3f(1.0, 0.0, 1.0);

    glVertex2f(this->m_x, this->m_y);

    glEnd();
    glBegin(GL_LINES);
}