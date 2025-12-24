#pragma once
#include <iostream>
#include "Components.h"

class Entity
{
public:
    Entity(int id) : m_ID(id)
    {
        std::cout << "[Entity] Created: " << id << "\n";
    }

    TransformComponent& GetTransform() { return m_Transform; }

private:
    int m_ID;
    TransformComponent m_Transform;
};
