#include "Window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

GLFWwindow* window;


Window::Window(int width, int height, const std::string& title)
    : m_Width(width), m_Height(height), m_Title(title)
{
    std::cout << "[Window] Created: " << m_Title 
              << " (" << m_Width << "x" << m_Height << ")\n";
              glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(1280, 720, "Ecosystem 3D", NULL, NULL);
    glfwMakeContextCurrent(window);
    //glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}

bool Window::IsWindowClosed()
{
    return glfwWindowShouldClose(window);
}

void Window::PollEvents()
{
    glfwPollEvents();
}

void Window::SwapBuffers()
{
    glfwSwapBuffers(window);
}
