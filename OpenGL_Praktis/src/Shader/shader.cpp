#include "shader.h"
// ShaderClass

Shader::Shader(const GLenum& type, const std::string& filepath) {

    this->type = type;
    std::stringstream shaderSource;
    std::ifstream shaderFile(filepath);

    std::string line;
    while (getline(shaderFile, line)) {

        if (line.find("uniform") != std::string::npos) {
            std::string name = "";
            unsigned int spaceCount = 0;
            for (auto ch : line)
                if ((ch == ' ' || ch==';') && spaceCount == 2) { break; }
                else {
                    if (ch == ' ') { name = ""; spaceCount++; }
                    else
                        name += ch;
                }
            this->uniforms.insert(name);
        };

        shaderSource << line << '\n';
    }

    shaderFile.close();

    this->source = shaderSource.str();
}

const std::string& Shader::getSource()
{
    return this->source;
}

const GLenum& Shader::getType()
{
    return this->type;
}

const std::set<std::string>& Shader::getUniforms()
{
    return this->uniforms;
}

unsigned int CompileShader(const std::string& source, const GLenum type) {

    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    GLCall(glShaderSource(id, 1, &src, NULL));
    GLCall(glCompileShader(id));

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Fail to compile shader" << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);
        return 0;
    }

    return id;
}