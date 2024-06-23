#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>

void initializeBuffers(GLuint& VAO, GLuint& VBO) {
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
}

void updateVertexBuffer(GLuint VBO, const std::vector<float>& vertices) {
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_DYNAMIC_DRAW);
}

void drawCircle(GLuint VAO, GLuint VBO, const std::vector<float>& vertices, GLenum mode) {
    glBindVertexArray(VAO);
    glDrawArrays(mode, 0, static_cast<GLsizei>(vertices.size() / 2));
    glBindVertexArray(0);
}
