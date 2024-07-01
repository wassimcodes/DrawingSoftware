#include "SaveManager.h"
#include <iostream>
#include <vector>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <Windows.h>

std::vector<unsigned char> CaptureFramebuffer(GLFWwindow* window, int& width, int& height) {
    glfwGetFramebufferSize(window, &width, &height);
    std::vector<unsigned char> pixels(width * height * 4);
    glReadBuffer(GL_FRONT);
    glReadPixels(0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixels.data());

    for (int y = 0; y < height / 2; ++y) {
        for (int x = 0; x < width * 4; ++x) {
            std::swap(pixels[y * width * 4 + x], pixels[(height - 1 - y) * width * 4 + x]);
        }
    }

    return pixels;
}

void SaveDrawingAsPNG(GLFWwindow* window) {
    int width, height;
    std::vector<unsigned char> pixels = CaptureFramebuffer(window, width, height);
    OPENFILENAMEA ofn;
    CHAR szFile[260] = { 0 };
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = szFile;
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = "PNG Files\0*.png\0All Files\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT;

    if (GetSaveFileNameA(&ofn) == TRUE) {
        std::string filePath = ofn.lpstrFile;
        if (filePath.find(".png") == std::string::npos) {
            filePath += ".png";
        }
        if (stbi_write_png(filePath.c_str(), width, height, 4, pixels.data(), width * 4)) {
            std::cout << "Saved drawing as PNG successfully to: " << filePath << std::endl;
        }
        else {
            std::cout << "Failed to save drawing as PNG." << std::endl;
        }
    }
    else {
        std::cout << "User canceled saving." << std::endl;
    }
}
