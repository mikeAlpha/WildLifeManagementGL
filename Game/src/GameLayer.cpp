#include "GameLayer.h"

#include "Renderer/Renderer.h"
#include "Renderer/Mesh.h"
#include "Renderer/Shader.h"

#include "Scene/Scene.h"
#include "Scene/SceneObject.h"

#include "Scene/Components/TransformComponent.h"
#include "Scene/Components/RenderComponent.h"
#include "Scene/Components/CameraComponent.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>

void GameLayer::OnAttach()
{
    std::cout << "[GameLayer] Attach\n";
    float cubeVertices[] = {
    // positions          // normals
    // Front face
    -0.5f, -0.5f,  0.5f,   0.0f,  0.0f,  1.0f,
    0.5f, -0.5f,  0.5f,   0.0f,  0.0f,  1.0f,
    0.5f,  0.5f,  0.5f,   0.0f,  0.0f,  1.0f,
    -0.5f,  0.5f,  0.5f,   0.0f,  0.0f,  1.0f,

    // Back face
    -0.5f, -0.5f, -0.5f,   0.0f,  0.0f, -1.0f,
    0.5f, -0.5f, -0.5f,   0.0f,  0.0f, -1.0f,
    0.5f,  0.5f, -0.5f,   0.0f,  0.0f, -1.0f,
    -0.5f,  0.5f, -0.5f,   0.0f,  0.0f, -1.0f,

    // Left face
    -0.5f, -0.5f, -0.5f,  -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f,  0.5f,  -1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f,  0.5f,  -1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f, -0.5f,  -1.0f,  0.0f,  0.0f,

    // Right face
    0.5f, -0.5f, -0.5f,   1.0f,  0.0f,  0.0f,
    0.5f, -0.5f,  0.5f,   1.0f,  0.0f,  0.0f,
    0.5f,  0.5f,  0.5f,   1.0f,  0.0f,  0.0f,
    0.5f,  0.5f, -0.5f,   1.0f,  0.0f,  0.0f,

    // Top face
    -0.5f,  0.5f, -0.5f,   0.0f,  1.0f,  0.0f,
    -0.5f,  0.5f,  0.5f,   0.0f,  1.0f,  0.0f,
    0.5f,  0.5f,  0.5f,   0.0f,  1.0f,  0.0f,
    0.5f,  0.5f, -0.5f,   0.0f,  1.0f,  0.0f,

    // Bottom face
    -0.5f, -0.5f, -0.5f,   0.0f, -1.0f,  0.0f,
    -0.5f, -0.5f,  0.5f,   0.0f, -1.0f,  0.0f,
    0.5f, -0.5f,  0.5f,   0.0f, -1.0f,  0.0f,
    0.5f, -0.5f, -0.5f,   0.0f, -1.0f,  0.0f
    };

    unsigned int cubeIndices[] = {
        0, 1, 2, 2, 3, 0,        // front
        4, 5, 6, 6, 7, 4,        // back
        8, 9,10,10,11, 8,        // left
        12,13,14,14,15,12,       // right
        16,17,18,18,19,16,       // top
        20,21,22,22,23,20        // bottom
    };

    cubeMesh = std::make_unique<Mesh>(cubeVertices, sizeof(cubeVertices) / sizeof(float), cubeIndices, sizeof(cubeIndices) / sizeof(unsigned int));
    
    testObj = std::make_unique<ModelLoader>("C:\\WildlifeGL\\WildLifeManagementGL\\Game\\src\\resources\\backpack\\backpack.obj");

    defaultShader = std::make_unique<Shader>("C:\\WildlifeGL\\WildLifeManagementGL\\Game\\src\\shaders\\vertex.glsl", "C:\\WildlifeGL\\WildLifeManagementGL\\Game\\src\\shaders\\fragment.glsl");

    lightShader = std::make_unique<Shader>("C:\\WildlifeGL\\WildLifeManagementGL\\Game\\src\\shaders\\emitv.glsl", "C:\\WildlifeGL\\WildLifeManagementGL\\Game\\src\\shaders\\emitf.glsl");
    
    mScene = std::make_unique<Scene>();
    
    auto& obj_1 = mScene->CreateObject();
    auto& obj_2 = mScene->CreateObject();
    camera = &mScene->CreateObject();
    auto& cam = camera->AddComponent<CameraComponent>();
    cam.SetCamProp(45.0f, 1280.0f / 720.0f, 0.1f, 1000.0f, camera->GetComponent<TransformComponent>());
    camera->GetComponent<TransformComponent>()->Position = camPos;
    
    auto& render_1 = obj_1.AddComponent<RenderComponent>();
    render_1.MeshPtr = cubeMesh.get();
    render_1.ShaderPtr = lightShader.get();

    auto& render_2 = obj_2.AddComponent<RenderComponent>();
    render_2.ModelPtr = testObj.get();
    render_2.ShaderPtr = defaultShader.get();

    render_2.ShaderPtr->use();
    printf("Haas Texture?:%d\n", render_2.ModelPtr->hasTexture());
    // if(render_2.ModelPtr->hasTexture())
    // {
    //     render_2.ShaderPtr->SetInt("hasTexture", 1);
    render_2.ShaderPtr->SetInt("texture_diffuse1", 0);
    // }
    // else    
    //     render_2.ShaderPtr->SetInt("hasTexture", 0);
}

void GameLayer::OnUpdate(float dt)
{
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);

    glm::mat4 view /*= glm::translate(glm::mat4(1.0f), glm::vec3(0, 0.0, -6.0f))*/;
    glm::mat4 projection /*= glm::perspective(glm::radians(45.0f), (float)1280 / (float)720, 0.1f, 1000.0f)*/;

    glm::mat4 model, lightModel;

    if(camera->GetComponent<CameraComponent>())
    {
        auto* camComp = camera->GetComponent<CameraComponent>();
        view = camComp->GetViewMatrix();
        projection = camComp->GetProjectionMatrix();
        camComp->OnUpdate(*mScene, dt);
    }

    

    for(auto& obj : mScene->GetObjects())
    {
        if(obj->GetComponent<RenderComponent>())
        {
            auto* render = obj->GetComponent<RenderComponent>();
            if(render->MeshPtr)
            {
                auto* transform = obj->GetComponent<TransformComponent>();
                transform->Scale = glm::vec3(0.2f);
                continue;
            }
        }

        if(obj->GetComponent<CameraComponent>())
            continue;

        auto* transform = obj->GetComponent<TransformComponent>();
        transform->Position = cubePosition;
        transform->Rotation.y  += dt * 0.5f;
        transform->Rotation.x  += dt * 0.5f;

        //transform->Scale = glm::vec3(0.2f);

        auto* render = obj->GetComponent<RenderComponent>();
        render->ShaderPtr->SetVector3("lightPos", lightPosition.x, lightPosition.y, lightPosition.z);
        render->ShaderPtr->SetVector3("lightColor", 1.0f, 1.0f, 1.0f);
        render->ShaderPtr->SetVector3("viewPos", camPos.x, camPos.y,camPos.z);
    }

    mScene->Render(projection,view);
}