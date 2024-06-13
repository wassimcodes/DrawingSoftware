#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "WindowManager.h"
#include "Callbacks.h"
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

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}