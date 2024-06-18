#pragma once
#include <GLFW/glfw3.h>
#include <vector>

// Function to create and bind a Vertex Array Object (VAO)
GLuint createVertexArrayObject();

// Function to create and bind a Vertex Buffer Object (VBO) with provided vertex data
GLuint createVertexBufferObject(const std::vector<float>& vertices);

// Function to draw a circle using provided VAO, VBO, vertex data, and drawing mode
void drawCircle(GLuint VAO, GLuint VBO, const std::vector<float>& vertices, GLenum mode);