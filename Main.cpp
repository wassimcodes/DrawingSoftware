#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "WindowManager.h"
#include "Callbacks.h"
#include "ShaderManager.h"
#include "OpenGLUtils.h"
#include "DrawingUtils.h"
#include "Drawing.h"
#include "GuiManager.h"
#include <iostream>
#include <vector>

extern bool darkMode;
extern ImVec4 clear_color;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {

    GLFWwindow* window = WindowManager::createWindow(720, 720, "Wacky Drawing Software");
    WindowManager::setupCallbacks(window);

    glfwSwapInterval(0);

    GLuint VAO, VBO;
    initializeBuffers(VAO, VBO);

    GuiManager::Init(window);

    GLuint shaderProgram = createShaderProgram("vertex_shader.vert", "fragment_shader.frag");
    glUseProgram(shaderProgram);

    std::vector<std::vector<float>> circles;

    const float radius = 0.005f;
    const int sides = 30;

    while (!glfwWindowShouldClose(window)) {
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);

        GuiManager::NewFrame();
        GuiManager::CreateUI(circles);
        
        static double prevXpos, prevYpos; 
        handleCursorMovement(window, prevXpos, prevYpos, circles, VBO, VAO, radius, sides);
        for (const auto& circle : circles) {
            updateVertexBuffer(VBO, circle);
            drawCircle(VAO, VBO, circle, GL_TRIANGLE_FAN);
        }

        GuiManager::Render();

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    GuiManager::Shutdown();
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
