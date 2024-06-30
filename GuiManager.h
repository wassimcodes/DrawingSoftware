#pragma once

#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <vector>

class GuiManager {
public:
    static void Init(GLFWwindow* window);
    static void Shutdown();
    static void NewFrame();
    static void Render();
    static void CreateUI(std::vector<std::vector<float>>& circles);
};