#pragma once
#include <GLFW/glfw3.h>
//#include "vert2d.h"
#include "vec2d.h"

struct FractalTreeParams
{
    GLfloat min_length = 0.001;
    GLfloat length_factor = 0.5;
    GLfloat shift_angle = 45.0;
    vec2d initial_vec = { 0.0, 1.0 };
    GLboolean should_be_recorded = false;
};

struct FractalTreeInfo
{
    GLint iterations = 0;
    GLint fps = 0;
};

class FractalTree
{
public:
    FractalTreeParams params;
    FractalTreeInfo info;

    FractalTree() {}
    void Draw(vert2d& start, GLfloat factor, GLfloat angle);

private:
    void Iterate(vert2d& start, GLfloat factor, GLfloat angle, int depth = 0);
};