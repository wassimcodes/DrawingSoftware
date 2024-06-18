#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

// Function to create and bind a Vertex Array Object (VAO)
GLuint createVertexArrayObject() {
    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    return VAO;
}

// Function to create and bind a Vertex Buffer Object (VBO) with provided vertex data
GLuint createVertexBufferObject(const std::vector<float>& vertices) {
    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
    return VBO;
}

// Function to draw a circle using provided VBO and VAO, vertex data, drawing mode.
void drawCircle(GLuint VAO, GLuint VBO, const std::vector<float>& vertices, GLenum mode) {
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizei>(vertices.size() * sizeof(float)), vertices.data(), GL_STATIC_DRAW);
    glDrawArrays(mode, 0, static_cast<GLsizei>(vertices.size() / 2));
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}
