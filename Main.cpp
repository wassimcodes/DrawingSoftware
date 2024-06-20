#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "WindowManager.h"
#include "Callbacks.h"
#include "ShaderManager.h"
#include "OpenGLUtils.h"
#include "Drawing.h"
#include<iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
int main()
{
    GLFWwindow* window = WindowManager::createWindow(720 , 720, "Wacky Drawing Software");
    WindowManager::setupCallbacks(window);

    GLuint shaderProgram = createShaderProgram("vertex_shader.vert", "fragment_shader.frag");
    glUseProgram(shaderProgram);

    GLuint VAO = createVertexArrayObject();
    GLuint VBO = 0;
    glGenBuffers(1, &VBO);
    std::vector<std::vector<float>> circles;

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);

        float x = (float)xpos / width * 2.0f - 1.0f;
        float y = -(float)ypos / height * 2.0f + 1.0f;
        const float radius = 0.005f;

        std::vector<float> currentCircle = DrawingCircle::drawCircle(x, y, radius);

        VBO = createVertexBufferObject(currentCircle);

        drawCircle(VAO, VBO, currentCircle, GL_TRIANGLE_FAN);

        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
            circles.push_back(currentCircle);
        }

       
        for (const auto& circle : circles) {
            drawCircle(VAO, VBO, circle, GL_TRIANGLE_FAN);
        }

        glfwPollEvents();
        glfwSwapBuffers(window);


    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

