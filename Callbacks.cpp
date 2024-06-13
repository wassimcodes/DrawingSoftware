#include "Callbacks.h"
#include "iostream"

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT)
	{
		if (action == GLFW_PRESS)
		{
			std::cout << "left mouse is pressed" << std::endl;
		}
		else if (action == GLFW_RELEASE)
		{
			std::cout << "left mouse is released" << std::endl;
		}
	}
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	std::cout << "cursor position:( " << xpos << ", " << ypos << " )" << std::endl;
}
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	{
		std::cout << "key pressed: " << key << std::endl;
	}
}