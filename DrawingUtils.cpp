#include "DrawingUtils.h"
#include "Drawing.h"
#include "OpenGLUtils.h"
#include <iostream> 
void handleCursorMovement(GLFWwindow* window, double& prevXpos, double& prevYpos, std::vector<std::vector<float>>& circles, GLuint VBO, GLuint VAO, float radius, int sides) {
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);

    float x1 = static_cast<float>(prevXpos) / width * 2.0f - 1.0f;
    float y1 = -static_cast<float>(prevYpos) / height * 2.0f + 1.0f;
    float x2 = static_cast<float>(xpos) / width * 2.0f - 1.0f;
    float y2 = -static_cast<float>(ypos) / height * 2.0f + 1.0f;

    std::vector<float> currentCircle = DrawingCircle::drawCircle(x2, y2, radius, sides);
    updateVertexBuffer(VBO, currentCircle);
    drawCircle(VAO, VBO, currentCircle, GL_TRIANGLE_FAN);

    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
        int num_samples = std::max(static_cast<int>(sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) / radius), 1);
        for (int i = 0; i <= num_samples; ++i) {
            float t = static_cast<float>(i) / num_samples;
            float vx = x1 * (1 - t) + x2 * t;
            float vy = y1 * (1 - t) + y2 * t;
            std::vector<float> currentCircle = DrawingCircle::drawCircle(vx, vy, radius, sides);
            circles.push_back(currentCircle);
        }
    }

    // Update previous cursor position
    prevXpos = xpos;
    prevYpos = ypos;
}
