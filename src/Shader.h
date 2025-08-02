#pragma once
#include<string>
#include<glad/glad.h>
#include<glm/glm.hpp>

class Shader {
public:
	unsigned int ID;
	Shader(const char* vertexPath, const char* fragmentPath);
	void use();
	void SetMatrix(const std::string& name, const glm::mat4& matrix);
	void SetVector3(const std::string& name, float x, float y, float z) const;
};
