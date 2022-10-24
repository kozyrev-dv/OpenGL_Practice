#pragma once
#include "../Engine.h"
#include "vaolayout/vaolayout.h"
class Vao {
	GLuint vaoId;
	GLuint vboId;
	GLuint eboId;
	VaoLayout* vaoLayout;

public:
	Vao();
	Vao(const GLuint& vaoId, const GLuint& vboId, const GLuint& eboId, VaoLayout* vaoLayout);
	void Creat(const unsigned int& verticesSize, const float* vertices, const unsigned int& indicesSize, const unsigned int* indices);

	GLuint getVaoId();
	GLuint getVboId();
	GLuint getEboId();
};