#include "vao.h"

Vao::Vao() {
	this->vaoId = 0;
	this->vboId = 0;
	this->eboId = 0;
	this->vaoLayout = nullptr;
}

Vao::Vao(const GLuint& vaoId, const GLuint& vboId, const GLuint& eboId, VaoLayout* vaoLayout)
{
	this->vaoId = vaoId;
	this->vboId = vboId;
	this->eboId = eboId;
	this->vaoLayout = vaoLayout;
}

void Vao::Creat(const unsigned int& verticesSize, const float* vertices, const unsigned int& indicesSize, const unsigned int* indices)
{

	GLCall(glBindVertexArray(this->getVaoId()));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, this->getVboId()));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->getEboId()));

	this->vaoLayout->Set();

	GLCall(glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, GL_STATIC_DRAW));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices, GL_STATIC_DRAW));

}

GLuint Vao::getVaoId()
{
	return this->vaoId;
}

GLuint Vao::getVboId()
{
	return this->vboId;
}

GLuint Vao::getEboId()
{
	return this->eboId;
}
