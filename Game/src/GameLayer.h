#pragma once
#include <iostream>
#include <memory>
#include "Core/Layer.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Mesh;
class Shader;
class Scene;
class SceneObject;
class ModelLoader;

class GameLayer : public Layer
{
private:
    std::unique_ptr<ModelLoader> testObj;
    std::unique_ptr<Mesh> cubeMesh;
    std::unique_ptr<Mesh> lightMesh;
    std::unique_ptr<Shader> defaultShader;
    std::unique_ptr<Shader> lightShader;
    std::unique_ptr<Scene> mScene;

    glm::vec3 cubeMin = glm::vec3(-0.5f, -0.5f, -0.5f);
    glm::vec3 cubeMax = glm::vec3(0.5f, 0.5f, 0.5f);
    glm::vec3 cubePosition = glm::vec3(0);

    glm::vec3 lightMin = glm::vec3(-0.1f, -0.1f, -0.1f);
    glm::vec3 lightMax = glm::vec3(0.1f, 0.1f, 0.1f);
    glm::vec3 lightPosition = glm::vec3(0.5f, 0.5f, 2.0f);
public:
    virtual void OnAttach();
    virtual void OnUpdate(float dt);
};
