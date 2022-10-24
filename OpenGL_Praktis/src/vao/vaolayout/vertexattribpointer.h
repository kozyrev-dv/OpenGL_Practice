#pragma once
#include "../../Engine.h"

class VertexAttribPointer {
	GLuint location;
	GLint vertexAttribCount;
	GLenum type;
	GLboolean normalized;
	GLsizei stride;
	const GLvoid* pointer;
public:
	VertexAttribPointer(const GLuint& location, const GLint& vertexAttribCount, const GLenum& type, const GLboolean& normalized, const GLsizei& stride, const GLvoid* pointer);
	
	const GLuint& getLocation();
	const GLint& getVertexAttribCount();
	const GLenum& getType();
	const GLboolean& getIsNormalized();
	const GLsizei& getStride();
	const GLvoid* getPointer();
};