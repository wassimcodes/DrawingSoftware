#pragma once

#include <GLFW/glfw3.h>
#include <vector>

class DrawingCircle {
public:
    static std::vector<float> drawCircle(float x, float y, float radius, int sides = 30);
};
