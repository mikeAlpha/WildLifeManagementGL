#pragma once

class SceneObject;
class Scene;

class Component
{
public:
    virtual ~Component() = default;

    virtual void OnStart() {}
    virtual void OnUpdate(float dt) {}
    virtual void OnUpdate(Scene& scene, float dt) {}

    SceneObject* GetOwner() const { return m_Owner; }

protected:
    SceneObject* m_Owner = nullptr;

    friend class SceneObject;
};
