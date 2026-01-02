#pragma once

#include "Scene/Component.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class TransformComponent : public Component
{
public:
    glm::vec3 Position{0.0f};
    glm::vec3 Rotation{0.0f};
    glm::vec3 Scale{1.0f};

    glm::mat4 GetTransform() const
    {
        glm::mat4 m(1.0f);
        m = glm::translate(m, Position);

        m = glm::rotate(m, Rotation.x, {1,0,0});
        m = glm::rotate(m, Rotation.y, {0,1,0});
        m = glm::rotate(m, Rotation.z, {0,0,1});

        m = glm::scale(m, Scale);
        return m;
    }
};
