#pragma once

#include <vector>
#include <iostream>
#include "../ECS/Entity.h"

class Scene
{
public:
    Entity& CreateEntity();
    void Update(float dt);

private:
    std::vector<Entity> m_Entities;
};