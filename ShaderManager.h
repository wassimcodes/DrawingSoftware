#pragma once

#include <glad/glad.h>
#include <string>

std::string readShaderFile(const char* filename);

GLuint compileShader(GLenum shaderType, const std::string& source);

GLuint createShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath);
