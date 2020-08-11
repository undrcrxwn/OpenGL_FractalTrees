#include "FractalTree.h"
#include <cstdlib>
#include <iostream>

void FractalTree::Draw(vert2d& start, GLfloat factor, GLfloat angle)
{
    int i = 0;
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 1.0);
    double ts_start = glfwGetTime();
    Iterate(start, factor, angle);
    double ts_end = glfwGetTime();
    glEnd();

    if (params.should_be_recorded)
    {
        GLfloat spent_time = ts_end - ts_start;
        info.fps = int(1 / spent_time);
        if (info.fps > 999) info.fps = 999;
        else if (info.fps < 0) info.fps = 0;

        system("cls");
        std::cout << std::endl;
        std::cout << "      VALUE:\t" << info.iterations << "\t ITER-S" << std::endl;
        std::cout << "       TIME:\t" << int(spent_time * 1000) << "\t MS" << std::endl;
        std::cout << "     F-RATE:\t" << info.fps << "\t FPS" << std::endl;
        std::cout << std::endl;
    }

    info.iterations = 0;
}

void FractalTree::Iterate(vert2d& start, GLfloat factor, GLfloat angle, int depth)
{
    if (factor * params.length_factor > params.min_length)
    {
        info.iterations++;

        vec2d vec = params.initial_vec;
        vec.Rotate(angle);

        vert2d end = vec.Draw(factor, start);

        depth++;
        Iterate(end, factor * params.length_factor, angle + params.shift_angle, depth);
        Iterate(end, factor * params.length_factor, angle - params.shift_angle, depth);
    }
    else
        depth = 0;
}