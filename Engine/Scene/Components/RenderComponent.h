#pragma once
#include "Scene/Component.h"
#include "Renderer/Mesh.h"
#include "Renderer/Shader.h"

class RenderComponent : public Component
{
public:
    Mesh* MeshPtr = nullptr;
    Shader* ShaderPtr = nullptr;
};
