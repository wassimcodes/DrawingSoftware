#pragma once

#include <vector>
#include <cmath>
#include <GLFW/glfw3.h>

void handleCursorMovement(GLFWwindow* window, double& prevXpos, double& prevYpos, std::vector<std::vector<float>>& circles, GLuint VBO, GLuint VAO, float radius, int sides);
