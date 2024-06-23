#pragma once
#include <glad/glad.h>
#include <vector>

void initializeBuffers(GLuint& VAO, GLuint& VBO);
void updateVertexBuffer(GLuint VBO, const std::vector<float>& vertices);
void drawCircle(GLuint VAO, GLuint VBO, const std::vector<float>& vertices, GLenum mode);
