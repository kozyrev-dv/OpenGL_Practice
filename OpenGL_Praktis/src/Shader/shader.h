#pragma once
#include "../Engine.h"

class Shader {
	std::string source = "";
	GLenum type = NULL;
	std::set<std::string> uniforms = {};
public:
	Shader(const GLenum& type, const std::string& filepath);
	const std::string& getSource();
	const GLenum& getType();
	const std::set<std::string>& getUniforms();
};

//std::string ParseShader(const char* filepath, std::map<std::string, int>& uniformNames);
unsigned int CompileShader(const std::string& source, const GLenum type);