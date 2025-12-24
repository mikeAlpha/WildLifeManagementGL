#pragma once
#include <iostream>

class Script
{
public:
    virtual ~Script() = default;

    virtual void OnCreate() { std::cout << "[Script] OnCreate\n"; }
    virtual void OnUpdate(float dt) { std::cout << "[Script] OnUpdate\n"; }
};