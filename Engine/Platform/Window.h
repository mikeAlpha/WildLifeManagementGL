#pragma once
#include <iostream>
#include <string>

class Window
{
public:
    Window(int width, int height, const std::string& title);

    void PollEvents();
    void SwapBuffers();
    bool IsWindowClosed();

private:
    int m_Width;
    int m_Height;
    std::string m_Title;
};