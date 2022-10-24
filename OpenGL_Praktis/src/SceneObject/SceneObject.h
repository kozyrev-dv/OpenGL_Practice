#pragma once
#include "../Engine.h"
#include "../Shader/ShaderProgram.h"
#include "../vao/vaolayout/vaolayout.h"
#include "../Texture/texture.h"
#include <vector>
class SceneObject {
private:
	const float* vertices;
	unsigned int verticesCount;
	const unsigned int* indices;
	unsigned int indicesCount;

	VaoLayout vaoLayout;
	GLuint vao;
	GLuint vbo;
	GLuint ebo;
	ShaderProgram shaderProg;
	
	std::vector<Texture> textures;

public:
	const float* getVertices();
	const unsigned int& getVerticesCount();

	const unsigned int* getIndices();
	const unsigned int& getIndicesCount();

	const ShaderProgram getShaderProgram();

	SceneObject(const float* vertices, const unsigned int& verticesSize, const unsigned int* indices, const unsigned int& indicesSize, VaoLayout* vaoLayout, const ShaderProgram shaderProg);
	void PushTexture(Texture texture, const std::string& samplerUniformName);
	void Delete();
	void Draw();
};