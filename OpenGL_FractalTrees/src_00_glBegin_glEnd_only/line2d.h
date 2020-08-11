#pragma once
#include <GLFW/glfw3.h>
#include "vert2d.h"

class line2d
{
public:
    vert2d m_start;
    vert2d m_end;

    line2d() {}
    line2d(vert2d& start, vert2d& end);
};