#pragma once

#include <vector>
#include <string>
#include <GLFW/glfw3.h>

std::vector<unsigned char> CaptureFramebuffer(GLFWwindow* window, int& width, int& height);
void SaveDrawingAsPNG(GLFWwindow* window);