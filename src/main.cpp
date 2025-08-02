#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

#include "Shader.h"
#include "Mesh.h"
#include "CircleMesh.cpp"

unsigned int WIDTH = 1366, HEIGHT = 768;

void framebuffer_size_callback(GLFWwindow*, int, int);
glm::vec3 CheckMouseSelection(GLFWwindow* window, glm::mat4 projection, glm::mat4 view);
bool IntersectRayAABB(const glm::vec3& rayOrigin, const glm::vec3& rayDir,
    const glm::vec3& boxMin, const glm::vec3& boxMax);

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Ecosystem 3D", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    glEnable(GL_DEPTH_TEST);

    Shader shader("../../shaders/vertex.glsl", "../../shaders/fragment.glsl");

    Shader lightShader("../../shaders/emitv.glsl", "../../shaders/emitf.glsl");

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

    float lightVertices[] = {
        // positions          // normals
       // Front face
    -0.1f, -0.1f,  0.1f,   0.0f,  0.0f,  1.0f,
     0.1f, -0.1f,  0.1f,   0.0f,  0.0f,  1.0f,
     0.1f,  0.1f,  0.1f,   0.0f,  0.0f,  1.0f,
    -0.1f,  0.1f,  0.1f,   0.0f,  0.0f,  1.0f,

    // Back face
    -0.1f, -0.1f, -0.1f,   0.0f,  0.0f, -1.0f,
     0.1f, -0.1f, -0.1f,   0.0f,  0.0f, -1.0f,
     0.1f,  0.1f, -0.1f,   0.0f,  0.0f, -1.0f,
    -0.1f,  0.1f, -0.1f,   0.0f,  0.0f, -1.0f,

    // Left face
    -0.1f, -0.1f, -0.1f,  -1.0f,  0.0f,  0.0f,
    -0.1f, -0.1f,  0.1f,  -1.0f,  0.0f,  0.0f,
    -0.1f,  0.1f,  0.1f,  -1.0f,  0.0f,  0.0f,
    -0.1f,  0.1f, -0.1f,  -1.0f,  0.0f,  0.0f,

    // Right face
     0.1f, -0.1f, -0.1f,   1.0f,  0.0f,  0.0f,
     0.1f, -0.1f,  0.1f,   1.0f,  0.0f,  0.0f,
     0.1f,  0.1f,  0.1f,   1.0f,  0.0f,  0.0f,
     0.1f,  0.1f, -0.1f,   1.0f,  0.0f,  0.0f,

     // Top face
     -0.1f,  0.1f, -0.1f,   0.0f,  1.0f,  0.0f,
     -0.1f,  0.1f,  0.1f,   0.0f,  1.0f,  0.0f,
      0.1f,  0.1f,  0.1f,   0.0f,  1.0f,  0.0f,
      0.1f,  0.1f, -0.1f,   0.0f,  1.0f,  0.0f,

      // Bottom face
      -0.1f, -0.1f, -0.1f,   0.0f, -1.0f,  0.0f,
      -0.1, -0.1f,  0.1f,   0.0f, -1.0f,  0.0f,
       0.1f, -0.1f,  0.1f,   0.0f, -1.0f,  0.0f,
       0.1f, -0.1f, -0.1f,   0.0f, -1.0f,  0.0f
    };


    unsigned int cubeIndices[] = {
        0, 1, 2, 2, 3, 0,       // front
        4, 5, 6, 6, 7, 4,       // back
        8, 9,10,10,11, 8,       // left
       12,13,14,14,15,12,       // right
       16,17,18,18,19,16,       // top
       20,21,22,22,23,20        // bottom
    };

    Mesh mesh(cubeVertices, sizeof(cubeVertices) / sizeof(float), cubeIndices, sizeof(cubeIndices) / sizeof(unsigned int));

    Mesh lightMesh(lightVertices, sizeof(lightVertices) / sizeof(float), cubeIndices, sizeof(cubeIndices) / sizeof(unsigned int));

    //Mesh* circle = CreateCircle(0.5f, 64);

    glm::vec3 cubeMin = glm::vec3(-0.5f, -0.5f, -0.5f);
    glm::vec3 cubeMax = glm::vec3(0.5f, 0.5f, 0.5f);
    glm::vec3 cubePosition = glm::vec3(0);

    glm::vec3 lightMin = glm::vec3(-0.1f, -0.1f, -0.1f);
    glm::vec3 lightMax = glm::vec3(0.1f, 0.1f, 0.1f);
    glm::vec3 lightPosition = glm::vec3(0.5f, 0.5f, 2.0f);

    bool IsObjectSelected = false;

    while (!glfwWindowShouldClose(window)) {
        float time = glfwGetTime();

        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader.use();

        glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0.0, -3));
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);

        glm::mat4 model, lightModel;
        glm::vec3 camPos = glm::vec3(0.0f, 0.0f, 3.0f);

        bool isPressed = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
        /*if (isPressed) {
            glm::vec3 ray = CheckMouseSelection(window, projection, view);
            
            glm::vec3 movedMin = cubePosition + cubeMin;
            glm::vec3 movedMax = cubePosition + cubeMax;


            if (IntersectRayAABB(camPos, ray, movedMin, movedMax)) {
                cubePosition = camPos + ray * 3.0f;
                IsObjectSelected = true;
            }
            else
                IsObjectSelected = false;
        }*/
        model = glm::translate(glm::mat4(1.0f), cubePosition);
        model = glm::rotate(model, time, glm::vec3(1, 1, 0.5f));

        shader.SetVector3("lightPos", lightPosition.x, lightPosition.y, lightPosition.z);
        shader.SetVector3("lightColor", 0.8, 0.5f, 0.1f);
        shader.SetVector3("viewPos", camPos.x, camPos.y,camPos.z);
        shader.SetVector3("objectColor", 0.8, 0.1f, 0.0f);

        shader.SetMatrix("view", view);
        shader.SetMatrix("projection", projection);
        shader.SetMatrix("model", model);

        mesh.Draw();

        lightShader.use();
        lightShader.SetMatrix("view", view);
        lightShader.SetMatrix("projection", projection);

        isPressed = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
        if (isPressed) {
            glm::vec3 ray = CheckMouseSelection(window, projection, view);

            glm::vec3 lightmovedMin = lightPosition + lightMin;
            glm::vec3 lightmovedMax = lightPosition + lightMax;

            if (IntersectRayAABB(camPos, ray, lightmovedMin, lightmovedMax)) {
                lightPosition = camPos + ray * 2.0f;
                IsObjectSelected = true;
            }
            else
                IsObjectSelected = false;
        }

        lightModel = glm::translate(glm::mat4(1.0f), lightPosition);
        lightShader.SetMatrix("model", lightModel);
        lightMesh.Draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

glm::vec3 CheckMouseSelection(GLFWwindow* window, glm::mat4 projection, glm::mat4 view) {
    double xpos, ypos;

    //Normalize to screen space [-1,1]
    glfwGetCursorPos(window, &xpos, &ypos);
    float x = (2.0f * xpos) / WIDTH - 1.0f;
    float y = 1.0f - (2.0f * ypos) / HEIGHT;
    float z = 1.0f;

    glm::vec3 rayNDC = glm::vec3(x, y, z);
    glm::vec4 rayClip = glm::vec4(rayNDC.x, rayNDC.y, -1.0f, 1.0f);

    glm::vec4 ray_eye = glm::inverse(projection) * rayClip;
    ray_eye = glm::vec4(ray_eye.x, ray_eye.y, -1.0f, 0.0f);

    glm::vec3 final_ray = glm::normalize(glm::vec3(glm::inverse(view) * ray_eye));
    return final_ray;
}

bool IntersectRayAABB(const glm::vec3& rayOrigin, const glm::vec3& rayDir,
    const glm::vec3& boxMin, const glm::vec3& boxMax) {
    float tmin = (boxMin.x - rayOrigin.x) / rayDir.x;
    float tmax = (boxMax.x - rayOrigin.x) / rayDir.x;

    if (tmin > tmax) std::swap(tmin, tmax);

    float tymin = (boxMin.y - rayOrigin.y) / rayDir.y;
    float tymax = (boxMax.y - rayOrigin.y) / rayDir.y;

    if (tymin > tymax) std::swap(tymin, tymax);

    if ((tmin > tymax) || (tymin > tmax))
        return false;

    if (tymin > tmin)
        tmin = tymin;
    if (tymax < tmax)
        tmax = tymax;

    float tzmin = (boxMin.z - rayOrigin.z) / rayDir.z;
    float tzmax = (boxMax.z - rayOrigin.z) / rayDir.z;

    if (tzmin > tzmax) std::swap(tzmin, tzmax);

    if ((tmin > tzmax) || (tzmin > tmax))
        return false;

    return true;
}

void framebuffer_size_callback(GLFWwindow*, int width, int height) {
    WIDTH = width;
    HEIGHT = height;
    glViewport(0, 0, width, height);
}
