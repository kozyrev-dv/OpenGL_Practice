#include "ShaderProgram.h"


ShaderProgram::ShaderProgram() {};

const GLuint& ShaderProgram::getId()
{
    return this->id;
}

std::map<std::string, int>& ShaderProgram::getUniformLocations()
{
    return this->uniformLocations;
}

void ShaderProgram::Push(const Shader& shader)
{

    this->shaders.push_back(shader);

}

void ShaderProgram::Create()
{
    this->id = glCreateProgram();

    for (int i = 0; i < shaders.size(); i++) {
        unsigned int shaderId = CompileShader(shaders[i].getSource(), shaders[i].getType());
        GLCall(glAttachShader(this->id, shaderId));
        GLCall(glDeleteShader(shaderId));
    }

    GLCall(glLinkProgram(this->getId()));

    for (int i = 0; i < shaders.size(); i++) {
        for (const auto& name : shaders[i].getUniforms()) {
            this->uniformLocations[name] = glGetUniformLocation(this->getId(), name.c_str());
        }
    }
}

void ShaderProgram::Use()
{
    GLCall(glUseProgram(this->getId()));
}

void ShaderProgram::UnUse()
{
    GLCall(glUseProgram(0));
}

void ShaderProgram::SetUniform1f(const std::string& name, const float& f)
{
    this->Use();
    if(this->getUniformLocations().find(name) == this->getUniformLocations().end())
    {
        std::cout << "ERROR::SHADER::UNIFORM_WAS_NOT_FOUND. Name(" + name + ")" << std::endl;
        return;
    }
    
    GLCall(glUniform1f(this->getUniformLocations()[name], f));
}

void ShaderProgram::SetUniform4f(const std::string& name, const float& f1, const float& f2, const float& f3, const float& f4)
{
    this->Use();
    if (this->getUniformLocations().find(name) == this->getUniformLocations().end())
    {
        std::cout << "ERROR::SHADER::UNIFORM_WAS_NOT_FOUND. Name(" + name + ")" << std::endl;
        return;
    }

    GLCall(glUniform4f(this->getUniformLocations()[name], f1, f2, f3, f4));

}

void ShaderProgram::SetUniform1i(const std::string& name, const int& i)
{
    this->Use();
    if (this->getUniformLocations().find(name) == this->getUniformLocations().end())
    {
        std::cout << "ERROR::SHADER::UNIFORM_WAS_NOT_FOUND. Name(" + name + ")" << std::endl;
        return;
    }

    GLCall(glUniform1i(this->getUniformLocations()[name], i));

}
