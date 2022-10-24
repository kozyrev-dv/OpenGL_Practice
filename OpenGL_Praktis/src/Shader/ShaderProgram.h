#pragma once
#include "../Engine.h"
#include "shader.h"
#include <vector>

class ShaderProgram {
private:
	GLuint id = 0;
	std::vector<Shader> shaders;
	std::map<std::string, int> uniformLocations = {};
public:
	ShaderProgram();
	//ShaderProgram(Shader* shaders, const unsigned int& count);
	const GLuint& getId();
	std::map<std::string, int>& getUniformLocations();

	void Push(const Shader& shader);
	void Create();
	void Use();
	void UnUse();

	void SetUniform1f(const std::string& name, const float& f);
	void SetUniform4f(const std::string& name, const float& f1, const float& f2, const float& f3, const float& f4);
	void SetUniform1i(const std::string& name, const int& i);
};