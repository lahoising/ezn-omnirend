#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <ezn_omnirend.h>

namespace ezn
{

Omnirend::Omnirend()
{
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplOpenGL3_Init("#version 410");
}

Omnirend::~Omnirend()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void Omnirend::AddWindow(void *windowHandle)
{
    ImGui_ImplGlfw_InitForOpenGL((GLFWwindow*)windowHandle, true);
}

void Omnirend::FrameBegin()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void Omnirend::FrameEnd()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

}

void Omnirend::FrameClear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}
    
} // namespace ezn
