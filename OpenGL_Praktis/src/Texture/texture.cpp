#include "texture.h"

Texture::Texture() :id(NULL),type(NULL), width(0), height(0), nrChannels(0) {}

Texture::Texture(const GLenum target, const char* filepath)
{
	this->type = target;
	
	unsigned char* data = stbi_load(filepath, &this->width, &this->height, &this->nrChannels, 0);
	if (data) {
		GLCall(glGenTextures(1, &this->id));
		this->Bind();

		GLCall(glTexImage2D(this->type, 0, GL_RGBA, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data));
	}
	else {
		std::cout << "ERROR::TEXTURE::FAIL_TO_LOAD";
	}

	stbi_image_free(data);
}

Texture::Texture(const GLenum target, const char* filepath, const GLint wrapping_s, const GLint wrapping_t):Texture(target, filepath)
{
	this->wrapping_s = wrapping_s;
	this->wrapping_t = wrapping_t;

}

Texture::Texture(const GLenum target, const char* filepath, const GLint wrapping_s, const GLint wrapping_t, const GLint filter_min, const GLint filter_mag):Texture(target, filepath, wrapping_s, wrapping_t)
{
	this->filter_min = filter_min;
	this->filter_mag = filter_mag;
}

void Texture::GenMipmaps()
{
	GLCall(glGenerateMipmap(this->type));
	this->isMipmapsGenerated = true;
}

void Texture::UseMipmaps(const bool value)
{
	this->useMipmaps = value;
	if (value && !this->isMipmapsGenerated)
		this->GenMipmaps();
}

void Texture::Bind()
{
	GLCall(glBindTexture(this->type, this->id));
}

void Texture::Bind(GLenum texture)
{
	GLCall(glActiveTexture(texture));
	this->Bind();
}

void Texture::Unbind()
{
	GLCall(glBindTexture(this->type, 0));
}
