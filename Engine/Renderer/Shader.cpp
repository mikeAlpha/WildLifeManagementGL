#include"Shader.h"
#include<fstream>
#include<sstream>
#include<iostream>

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	try {
		std::ifstream vertexFile(vertexPath);
		std::ifstream fragmentFile(fragmentPath);
		std::stringstream vStream, fStream;

		vStream << vertexFile.rdbuf();
		fStream << fragmentFile.rdbuf();
		std::string vCode = vStream.str();
		std::string fCode = fStream.str();

		const char* vShader = vCode.c_str();
		const char* fShader = fCode.c_str();

		unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vs, 1, &vShader, NULL);
		glCompileShader(vs);

		unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fs, 1, &fShader, NULL);
		glCompileShader(fs);

		ID = glCreateProgram();
		glAttachShader(ID, vs);
		glAttachShader(ID, fs);
		glLinkProgram(ID);

		glDeleteShader(vs);
		glDeleteShader(fs);
	}
	catch(std:: string){
		std::cout << "Error loading shader" << std::endl;
	}
}

void Shader::use() const
{
	glUseProgram(ID);
}

void Shader::SetMatrix(const std::string& name, const glm::mat4& matrix) const
{
	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &matrix[0][0]);
}

void Shader::SetVector3(const std::string& name, float x, float y, float z) const
{
	glUniform3f(glGetUniformLocation(ID, name.c_str()),x,y,z);
}
