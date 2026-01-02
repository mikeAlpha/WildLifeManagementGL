#include "Renderer.h"
#include "Mesh.h"
#include "Shader.h"

#include <glad/glad.h>

static glm::mat4 s_Projection;
static glm::mat4 s_View;

void Renderer::Init()
{
    std::cout << "[Renderer] Init\n";
    glEnable(GL_DEPTH_TEST);
}

void Renderer::BeginFrame(const glm::mat4& proj,const glm::mat4& view)
{
    std::cout << "[Renderer] BeginFrame\n";
    s_Projection = proj;
    s_View = view;
}

void Renderer::EndFrame()
{
    std::cout << "[Renderer] EndFrame\n";
}

void Renderer::DrawMesh(const Mesh& mesh, const Shader& shader, const glm::mat4& transform)
{
        // shader.Bind();
        shader.use();

        // glm::mat4 mvp = s_ViewProjection * transform;
        shader.SetMatrix("view", s_View);
        shader.SetMatrix("projection", s_Projection);
        shader.SetMatrix("model", transform);
        
        // shader.SetMat4("u_MVP", mvp);

        mesh.Draw();
}