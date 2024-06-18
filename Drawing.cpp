#include "Drawing.h"
#include <vector>
#include <cmath>
#include <iostream>

std::vector<float> DrawingCircle::drawCircle(float x, float y, float radius, int sides) {
    std::vector<float> vertices;
    for (int i = 0; i < sides; ++i) {
        float theta = 2.0f * 3.1415926f * float(i) / float(sides); 
        float vx = x + radius * cosf(theta); 
        float vy = y + radius * sinf(theta); 
        vertices.push_back(vx); 
        vertices.push_back(vy); 
    }
    //std::cout << "First vertex coordinates:" << std::endl;
    //std::cout << "(" << vertices[0] << ", " << vertices[1] << ")" << std::endl;

    return vertices;
}