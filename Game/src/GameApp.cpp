#include "GameApp.h"

GameApp::GameApp()
{
    std::cout << "[GameApp] Construct\n";
    PushLayer(std::make_unique<GameLayer>());
}
