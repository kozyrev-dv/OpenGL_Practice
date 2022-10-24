#include "vertexattribpointer.h"

VertexAttribPointer::VertexAttribPointer(const GLuint& location, const GLint& vertexAttribCount, const GLenum& type, const GLboolean& normalized, const GLsizei& stride, const GLvoid* pointer)
{

	this->location = location;
	this->vertexAttribCount = vertexAttribCount;
	this->type = type;
	this->normalized = normalized;
	this->stride = stride;
	this->pointer = pointer;

}

const GLuint& VertexAttribPointer::getLocation() {
	return location;
}
const GLint& VertexAttribPointer::getVertexAttribCount() {
	return vertexAttribCount;
}
const GLenum& VertexAttribPointer::getType() {
	return type;
}
const GLboolean& VertexAttribPointer::getIsNormalized() {
	return normalized;
}
const GLsizei& VertexAttribPointer::getStride() {
	return stride;
}
const GLvoid* VertexAttribPointer::getPointer() {
	return pointer;
}