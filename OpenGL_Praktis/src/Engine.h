#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/fwd.hpp>

#include <iostream>
#include <fstream>

#include <string>
#include <sstream>
#include <map>
#include <set>

void GLClearError();

bool GLLogError(const char* function, const char* file, int line);

#define ASSERT(x) if(!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogError(#x, __FILE__, __LINE__))
