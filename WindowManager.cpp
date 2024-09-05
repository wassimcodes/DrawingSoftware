#include <glad/glad.h>
#include "WindowManager.h"
#include "Callbacks.h"
#include <iostream>
#include <vector>
#include <fstream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GLFWwindow* WindowManager::createWindow(int width, int height, const char* title) {
    glfwInit();
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    GLFWwindow* window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return nullptr;
    }
    glViewport(0, 0, width, height);
    return window;
}

void WindowManager::setupCallbacks(GLFWwindow* window) {
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetKeyCallback(window, key_callback);
}


// Window Icon

void setWindowIcon(GLFWwindow* window, const char* imagePath) {
    int width, height, channels;

    std::ifstream file(imagePath, std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open image file: " << imagePath << std::endl;
        return;
    }

    file.seekg(0, std::ios::end);
    size_t fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<char> buffer(fileSize);
    file.read(buffer.data(), fileSize);
    file.close();

    unsigned char* pixels = stbi_load_from_memory(reinterpret_cast<unsigned char*>(buffer.data()), fileSize, &width, &height, &channels, STBI_rgb_alpha);
    if (!pixels) {
        std::cerr << "Failed to load image: " << imagePath << std::endl;
        return;
    }

    GLFWimage image;
    image.width = width;
    image.height = height;
    image.pixels = pixels;

    glfwSetWindowIcon(window, 1, &image);

    stbi_image_free(pixels);
}
