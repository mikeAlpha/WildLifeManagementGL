#pragma once
#include <iostream>

class Layer
{
public:
    virtual ~Layer() = default;

    virtual void OnAttach() { std::cout << "[Layer] Attached\n"; }
    virtual void OnDetach() { std::cout << "[Layer] Detached\n"; }
    virtual void OnUpdate(float dt) { std::cout << "[Layer] Update\n"; }
};