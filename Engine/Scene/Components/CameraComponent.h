#include "Platform/Window.h"
#include "Scene/Scene.h"
#include "Scene/Component.h"
#include "Scene/Components/TransformComponent.h"
#include "Core/Input.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <GLFW/glfw3.h>

glm::vec3 front;
glm::vec3 lastPosition;

class CameraComponent : public Component
 {
 public:
     void SetCamProp(float fov, float aspectRatio, float nearClip, float farClip, TransformComponent* transform)
     {
         mFov = fov;
         mAspectRatio = aspectRatio;
         mNearClip = nearClip;
         mFarClip = farClip;
         this->transform = transform;
     }
     void OnStart() override {}
     void OnUpdate(Scene& scene, float dt) override 
     {
         for (auto& obj : scene.GetObjects())
        {
            if (transform == nullptr)
                continue;

           if(Input::IsKeyPressed(GLFW_KEY_LEFT_ALT))
           {    
                Window::ToggleCursor(false);

                float mouseDX = Input::GetMouseDX();
                float mouseDY = Input::GetMouseDY();

                yaw   += mouseDX * mouseSensitivity;
                pitch += mouseDY * mouseSensitivity;

                pitch = glm::clamp(pitch, -89.0f, 89.0f);

                this->front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
                this->front.y = sin(glm::radians(pitch));
                this->front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
                this->front = glm::normalize(front);

                float radius = glm::length(transform->Position);
                if(radius == 0.0f) radius = 3.0f;
                transform->Position = -this->front * radius;

                this->right = glm::normalize(glm::cross(this->front, {0,1,0}));
                this->up    = glm::normalize(glm::cross(this->right, this->front));
            }
            else
            {
                Window::ToggleCursor(true);
            }

            bool forward  = Input::IsKeyPressed(GLFW_KEY_W);
            bool backward = Input::IsKeyPressed(GLFW_KEY_S);
            bool left     = Input::IsKeyPressed(GLFW_KEY_A);
            bool right    = Input::IsKeyPressed(GLFW_KEY_D);

            float velocity = moveSpeed * dt;

            if (forward)  transform->Position += this->front * velocity;
            if (backward) transform->Position -= this->front * velocity;
            if (left)     transform->Position -= this->right * velocity;
            if (right)    transform->Position += this->right * velocity;
        }
        Input::EndFrame();
     }
     inline glm::mat4 GetViewMatrix()
     {
        return glm::lookAt(
            transform->Position,
            transform->Position + front,
            up
        );
     }

    inline glm::mat4 GetProjectionMatrix()
    {
        return glm::perspective(
            glm::radians(mFov),
            mAspectRatio,
            mNearClip,
            mFarClip
        );
    }

 private:
     float mFov;
     float mAspectRatio;
     float mNearClip;
     float mFarClip;

     glm::mat4 mView;
     glm::mat4 mProjection;

     float moveSpeed = 8.0f;
     float mouseSensitivity = 0.05f;

     glm::vec3 front  = { 0.0f, 0.0f, -1.0f };
     glm::vec3 up     = { 0.0f, 1.0f,  0.0f };
     glm::vec3 right  = { 1.0f, 0.0f,  0.0f };

     float yaw   = -90.0f;
     float pitch = 0.0f;
     TransformComponent* transform;
 };