#pragma once

#include <memory>
#include <vector>
#include <typeindex>
#include <type_traits>

#include "Component.h"

class SceneObject
{
public:
    template<typename T, typename... Args>
    T& AddComponent(Args&&... args)
    {
        static_assert(std::is_base_of<Component, T>::value,
                      "T must derive from Component");

        auto comp = std::make_unique<T>(std::forward<Args>(args)...);
        comp->m_Owner = this;

        T& ref = *comp;
        m_Components.push_back(std::move(comp));
        return ref;
    }

    template<typename T>
    T* GetComponent()
    {
        for (auto& c : m_Components)
            if (auto casted = dynamic_cast<T*>(c.get()))
                return casted;

        return nullptr;
    }

    template<typename T>
    bool HasComponent() { return GetComponent<T>() != nullptr; }

    bool Visible = true;

private:
    std::vector<std::unique_ptr<Component>> m_Components;
};
