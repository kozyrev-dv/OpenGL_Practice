#pragma once
#include "../Engine.h"
#include "../Third party/stb_image/stb_image.h"

class Texture {

private: 

	GLenum type;
	unsigned int id = NULL;

	GLint wrapping_s = GL_REPEAT;
	GLint wrapping_t = GL_REPEAT;
	GLint wrapping_r = GL_REPEAT;

	GLint filter_min = GL_LINEAR;
	GLint filter_mag = GL_LINEAR;

	bool useMipmaps = false;
	bool isMipmapsGenerated = false;

	int width, height, nrChannels;

private:
	void GenMipmaps();
	void Bind();

public:
	inline const unsigned int getId() { return this->id; };
	inline const unsigned int getType() { return this->type; };
	inline const unsigned int getWrapping_s() { return this->wrapping_s; };
	inline const unsigned int getWrapping_t() { return this->wrapping_t; };
	inline const unsigned int getWrapping_r() { return this->wrapping_r; };
	inline const unsigned int getFilter_min() { return this->filter_min; };
	inline const unsigned int getFilter_mag() { return this->filter_mag; };

	Texture();
	Texture(const GLenum target, const char* filepath);
	Texture(const GLenum target, const char* filepath, const GLint wrapping_s, const GLint wrapping_t);
	Texture(const GLenum target, const char* filepath, const GLint wrapping_s, const GLint wrapping_t, const GLint filter_min, const GLint filter_mag);

	void UseMipmaps(const bool value);
	void Bind(GLenum texture);
	void Unbind();

};