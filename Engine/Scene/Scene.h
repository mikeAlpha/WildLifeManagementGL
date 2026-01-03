#pragma once

#include <vector>
#include <memory>

#include "SceneObject.h"
#include "Components/TransformComponent.h"
#include "Components/RenderComponent.h"
#include "Renderer/Renderer.h"

class Scene
{
public:
    SceneObject& CreateObject()
    {
        m_Objects.push_back(std::make_unique<SceneObject>());
        auto& obj = *m_Objects.back();

        obj.AddComponent<TransformComponent>();

        return obj;
    }

    void Render(const glm::mat4& proj, const glm::mat4& view)
    {
        Renderer::BeginFrame(proj, view);

        for (auto& obj : m_Objects)
        {
            if (!obj->Visible) continue;

            auto* transform = obj->GetComponent<TransformComponent>();
            auto* render    = obj->GetComponent<RenderComponent>();

            if (transform && render && render->ModelPtr && render->ShaderPtr)
            {
                // Renderer::DrawMesh(
                //     *render->MeshPtr,
                //     *render->ShaderPtr,
                //     transform->GetTransform()
                // );
                Renderer::DrawModel(
                    *render->ModelPtr,
                    *render->ShaderPtr,
                    transform->GetTransform()
                );
            }
        }

        Renderer::EndFrame();
    }

    std::vector<std::unique_ptr<SceneObject>>& GetObjects()
    {
        return m_Objects;
    }

    const std::vector<std::unique_ptr<SceneObject>>& GetObjects() const
    {
        return m_Objects;
    }

private:
    std::vector<std::unique_ptr<SceneObject>> m_Objects;
};
