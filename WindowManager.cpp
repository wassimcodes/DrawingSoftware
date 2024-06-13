#include <glad/glad.h>
#include "WindowManager.h"
#include "Callbacks.h"
#include <iostream>

GLFWwindow* WindowManager::createWindow(int width, int height, const char* title)
{
	glfwInit();

	GLFWwindow* window = glfwCreateWindow(width, height, title, nullptr, nullptr);

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize OpenGL context" << std::endl;
		return nullptr;
	}
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	return window;
}

void WindowManager::setupCallbacks(GLFWwindow* window) {

	glfwSetMouseButtonCallback(window, mouse_button_callback);

	glfwSetCursorPosCallback(window, cursor_position_callback);

	glfwSetKeyCallback(window, key_callback);
}
