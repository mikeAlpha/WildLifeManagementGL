#pragma once
#include <glad/glad.h>

class Mesh {
public:
    Mesh(float* vertices, unsigned int vertexCount, unsigned int* indices, unsigned int indexCount);
    ~Mesh();

    void Draw() const;

private:
    unsigned int VAO, VBO, EBO;
    unsigned int indexCount;
};