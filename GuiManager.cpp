#include "GuiManager.h"
#include <iostream>

bool darkMode = true;
ImVec4 clear_color = ImVec4(0, 0, 0, 0);

//bool IsMouseHoveringAnyWindow() {
//    return ImGui::IsWindowHovered(ImGuiHoveredFlags_AnyWindow) || ImGui::IsAnyItemHovered();
//}

void GuiManager::Init(GLFWwindow* window) {
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330 core");
    ImGui::StyleColorsDark();
}

void GuiManager::Shutdown() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void GuiManager::NewFrame() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void GuiManager::Render() {
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void ResetDrawing(std::vector<std::vector<float>>& circles) {
    circles.clear();
    std::cout << "Rest Drawing" << std::endl;
}

void ToggleDarkWhiteMode(bool& darkMode, ImVec4& clear_color) {

    if (darkMode)
    {
        ImGui::StyleColorsLight();
        clear_color = ImVec4(1, 1, 1, 1);
    }
    else
    {
        ImGui::StyleColorsDark();
        clear_color = ImVec4(0, 0, 0, 0);
    }
    darkMode = !darkMode;
    std::cout << "Dark/White Mode toggled" << std::endl;
}


void GuiManager::CreateUI(std::vector<std::vector<float>>& circles) {
    ImGuiWindowFlags windowFlags =   ImGuiWindowFlags_MenuBar 
                                   | ImGuiWindowFlags_NoMove | 
                                     ImGuiWindowFlags_NoResize | 
                                     ImGuiWindowFlags_NoCollapse | 
                                     ImGuiWindowFlags_NoTitleBar;

    ImGui::SetNextWindowPos(ImVec2(0, 0)); 
    ImGui::SetNextWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x, 0));  

    ImGui::Begin("UI Panel", nullptr, windowFlags);

    if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            if (ImGui::MenuItem("Save as PNG")) {

            }
            if (ImGui::MenuItem("Reset")) {
                ResetDrawing(circles);
            }
            if (ImGui::MenuItem("Dark/White Mode")) {
                ToggleDarkWhiteMode(darkMode, clear_color);
            }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Palette")) {
     
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Brush")) {
      
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Draw")) {
     
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }

    ImGui::Text("fps: %.1f ", ImGui::GetIO().Framerate);
    ImGui::End();
}
