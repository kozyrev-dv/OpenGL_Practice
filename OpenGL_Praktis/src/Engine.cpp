#include "Engine.h"

void GLClearError() {
    while (glGetError() != GL_NO_ERROR);
}

bool GLLogError(const char* function, const char* file, int line) {
    while (GLenum error = glGetError()) {
        std::stringstream ss;
        ss << std::hex << error;
        std::string errHex(ss.str());
        std::cout << "[OpenGL Error] (0x0" << errHex << "): "
            << function << " " << file << ":" << line << std::endl;
        return false;
    }
    return true;
}
