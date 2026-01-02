#pragma once

class SceneObject;

class Component
{
public:
    virtual ~Component() = default;

    virtual void OnStart() {}
    virtual void OnUpdate(float dt) {}

    SceneObject* GetOwner() const { return m_Owner; }

protected:
    SceneObject* m_Owner = nullptr;

    friend class SceneObject;
};
