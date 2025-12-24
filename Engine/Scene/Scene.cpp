#include "Scene.h"

Entity& Scene::CreateEntity()
{
    int id = static_cast<int>(m_Entities.size());
    m_Entities.emplace_back(id);
    return m_Entities.back();
}

void Scene::Update(float dt)
{
    std::cout << "[Scene] Update\n";
}