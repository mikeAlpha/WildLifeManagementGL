#pragma once

#include <vector>
#include <memory>
#include <iostream>

#include "Layer.h"
#include "../Platform/Window.h"
#include "../Renderer/Renderer.h"
#include "../Scene/Scene.h"
#include "Time.h"

class Application
{
public:
    Application();
    virtual ~Application();

    void Run();
    void PushLayer(std::unique_ptr<Layer> layer);

protected:
    std::unique_ptr<Window> m_Window;
    std::vector<std::unique_ptr<Layer>> m_Layers;
    bool m_Running = true;
};
