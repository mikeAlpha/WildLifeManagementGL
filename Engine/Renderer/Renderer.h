#pragma once

#include <iostream>
#include <glm/glm.hpp>

class Mesh;
class Shader;
class ModelLoader;

class Renderer
{
public:
    static void Init();
    static void Shutdown();

    static void BeginFrame(const glm::mat4& proj,const glm::mat4& view);
    static void EndFrame();

    static void DrawMesh(const Mesh& mesh, const Shader& shader, const glm::mat4& transform);
    static void DrawModel(const ModelLoader& model, const Shader& shader, const glm::mat4& transform);
};