#include "../../Engine.h"
#include "vaolayout.h"

void VaoLayout::Push(VertexAttribPointer pointer)
{
	this->pointers.push_back(pointer);
}

void VaoLayout::Set()
{
	for (int i = 0; i < this->pointers.size(); i++) {
		GLCall(glVertexAttribPointer(pointers[i].getLocation(),
									 pointers[i].getVertexAttribCount(),
									 pointers[i].getType(),
									 pointers[i].getIsNormalized(),
									 pointers[i].getStride(),
									 pointers[i].getPointer()));

		GLCall(glEnableVertexAttribArray(i));
	}
}
