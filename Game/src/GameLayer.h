#pragma once
#include <iostream>
#include "Core/Layer.h"

class GameLayer : public Layer
{
public:
    void OnAttach() override
    {
        std::cout << "[GameLayer] Attach\n";
    }

    void OnUpdate(float dt) override
    {
        std::cout << "[GameLayer] Update\n";
    }
};
