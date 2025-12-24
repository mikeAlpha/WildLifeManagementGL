#include "Application.h"

float Time::DeltaTime = 1.0f / 60.0f;

Application::Application()
{
    std::cout << "[Application] Created\n";
    m_Window = std::make_unique<Window>(1280, 720, "Engine Window");
    Renderer::Init();
}

Application::~Application()
{
    std::cout << "[Application] Destroyed\n";
}

void Application::Run()
{
    std::cout << "[Application] Run\n";

    while (m_Running)
    {
        m_Window->PollEvents();

        for (auto& layer : m_Layers)
            layer->OnUpdate(Time::DeltaTime);

        Renderer::BeginFrame();
        Renderer::EndFrame();

        m_Window->SwapBuffers();

        // stop after one loop (debug only)
        m_Running = false;
    }
}

void Application::PushLayer(std::unique_ptr<Layer> layer)
{
    std::cout << "[Application] PushLayer\n";
    layer->OnAttach();
    m_Layers.emplace_back(std::move(layer));
}
