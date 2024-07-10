#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "WindowManager.h"
#include "Callbacks.h"
#include "ShaderManager.h"
#include "OpenGLUtils.h"
#include "Drawing.h"
#include "GuiManager.h"
#include "DrawingUtils.h"
#include <iostream>
#include <vector>

extern bool darkMode;
extern ImVec4 clear_color;
extern ImVec4 selected_color;
extern float brushSize;
extern int brushSizeDisplay;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    GLFWwindow* window = WindowManager::createWindow(720, 720, "Wacky Drawing Software");
    WindowManager::setupCallbacks(window);

    
    setWindowIcon(window, "C:/Users/woule/Documents/c++/DrawingSoftware/Icon/brushImage.jpg");

    glfwSwapInterval(0);
    GuiManager::Init(window);
    GLuint shaderProgram = createShaderProgram("vertex_shader.vert", "fragment_shader.frag");
    glUseProgram(shaderProgram);
    GLuint VAO, VBO;
    initializeBuffers(VAO, VBO);
    const int sides = 60;

    std::vector<std::vector<float>> circles;

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);

        GuiManager::NewFrame();
        GuiManager::CreateUI(circles);

        static double prevXpos, prevYpos;
        handleCursorMovement(window, prevXpos, prevYpos, circles, VBO, VAO, brushSize, sides);

        int brushColorLocation = glGetUniformLocation(shaderProgram, "u_BrushColor");
        glUniform4f(brushColorLocation, selected_color.x, selected_color.y, selected_color.z, selected_color.w);

        for (const auto& circle : circles) {
            updateVertexBuffer(VBO, circle);
            drawCircle(VAO, VBO, circle, GL_TRIANGLE_FAN);
        }
        GuiManager::Render();
        glfwSwapBuffers(window);
    }
    GuiManager::Shutdown();
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
