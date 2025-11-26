#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <IProperty.h>

#include "Shader.h"
#include "Mesh.h"

class Renderer: public IProperty{

    public:
        Renderer(){ 

        }
        ~Renderer(){ 

        }

        void Draw() override{
            std::cout << "Calling renderer function\n" << std::endl;
        }
};