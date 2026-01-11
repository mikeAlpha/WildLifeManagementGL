#include "Window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Core/Input.h"

GLFWwindow* window;

static void CursorPosCallback(GLFWwindow*, double xpos, double ypos);
static void KeyCallback(GLFWwindow*, int key, int, int action, int);
static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

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
    glfwSetKeyCallback(window, KeyCallback);
    glfwSetCursorPosCallback(window, CursorPosCallback);
    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
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

static void KeyCallback(GLFWwindow*, int key, int, int action, int)
{
    if (action == GLFW_PRESS)
        Input::SetKey(key, true);
    else if (action == GLFW_RELEASE)
        Input::SetKey(key, false);
}

static void CursorPosCallback(GLFWwindow*, double xpos, double ypos)
{
    static bool first = true;
    static double lastX = 0.0, lastY = 0.0;

    if (first)
    {
        lastX = xpos;
        lastY = ypos;
        first = false;
    }

    Input::AddMouseDelta(
        static_cast<float>(xpos - lastX),
        static_cast<float>(lastY - ypos)
    );

    lastX = xpos;
    lastY = ypos;
}

static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
