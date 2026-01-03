#pragma once
#include "Scene/Component.h"
#include "Renderer/Mesh.h"
#include "Renderer/Shader.h"
#include "Renderer/ModelLoader.h"

class RenderComponent : public Component
{
public:
    ModelLoader* ModelPtr = nullptr;
    Mesh* MeshPtr = nullptr;
    Shader* ShaderPtr = nullptr;
};
