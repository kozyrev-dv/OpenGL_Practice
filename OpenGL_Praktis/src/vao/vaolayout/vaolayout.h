#pragma once
#include "vertexattribpointer.h"
#include <vector>

class VaoLayout {
	std::vector<VertexAttribPointer> pointers;


public:

	void Push(VertexAttribPointer pointer);
	void Set();
};
