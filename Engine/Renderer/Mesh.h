#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>
#include <string>

#include "Shader.h"

using namespace std;

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
    glm::vec3 Tangent;
    glm::vec3 Bitangent;
};

struct Texture {
    unsigned int id;
    string type;
    string path;
};


class Mesh {
public:
    Mesh(float* vertices, unsigned int vertexCount, unsigned int* indices, unsigned int indexCount);
    Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
    ~Mesh();

    void Draw() const;
    void Draw(const Shader& shader) const;

    vector<Vertex>       vertices;
    vector<unsigned int> indices;
    vector<Texture>      textures;

private:
    unsigned int VAO, VBO, EBO;
    unsigned int indexCount;
};