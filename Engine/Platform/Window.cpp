#include "Window.h"

Window::Window(int width, int height, const std::string& title)
    : m_Width(width), m_Height(height), m_Title(title)
{
    std::cout << "[Window] Created: " << m_Title 
              << " (" << m_Width << "x" << m_Height << ")\n";
}

void Window::PollEvents()
{
    std::cout << "[Window] PollEvents\n";
}

void Window::SwapBuffers()
{
    std::cout << "[Window] SwapBuffers\n";
}
