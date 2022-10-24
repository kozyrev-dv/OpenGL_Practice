#include "SceneObject.h"
#include "../vao/vao.h"
SceneObject::SceneObject(const float* vertices, const unsigned int& verticesSize, const unsigned int* indices, const unsigned int& indicesSize,  VaoLayout* vaoLayout, const ShaderProgram shaderProg) {

	this->vertices = vertices;
	this->verticesCount = verticesSize / sizeof(float);

	this->indices = indices;
	this->indicesCount = indicesSize / sizeof(unsigned int);

	GLCall(glGenVertexArrays(1, &this->vao));
	GLCall(glGenBuffers(1, &this->vbo));
	GLCall(glGenBuffers(1, &this->ebo));

    Vao vao(this->vao, this->vbo, this->ebo, vaoLayout);
    vao.Creat(verticesSize, vertices, indicesSize, indices);

	GLCall(glBindVertexArray(0));

	this->shaderProg = shaderProg;
}

void SceneObject::PushTexture(Texture texture, const std::string& samplerUniformName)
{
    this->textures.push_back(texture);
    this->shaderProg.SetUniform1i(samplerUniformName, this->textures.size()-1);
}

void SceneObject::Delete()
{

    glDeleteVertexArrays(1, &this->vao);
    glDeleteBuffers(1, &this->vbo);
    glDeleteBuffers(1, &this->ebo);
    glDeleteProgram(this->shaderProg.getId());

}

void SceneObject::Draw()
{
    this->shaderProg.Use();
    for (int i = 0; i < this->textures.size(); i++) {
        if (this->textures[i].getId() != NULL) {
            this->textures[i].Bind(GL_TEXTURE0 + i);
            GLCall(glTexParameteri(this->textures[i].getType(), GL_TEXTURE_WRAP_S, this->textures[i].getWrapping_s()));
            GLCall(glTexParameteri(this->textures[i].getType(), GL_TEXTURE_WRAP_T, this->textures[i].getWrapping_t()));
            GLCall(glTexParameteri(this->textures[i].getType(), GL_TEXTURE_WRAP_R, this->textures[i].getWrapping_r()));

            GLCall(glTexParameteri(this->textures[i].getType(), GL_TEXTURE_MIN_FILTER, this->textures[i].getFilter_min()));
            GLCall(glTexParameteri(this->textures[i].getType(), GL_TEXTURE_MAG_FILTER, this->textures[i].getFilter_mag()));
        }
    } 

    GLCall(glBindVertexArray(this->vao));
    GLCall(glDrawElements(GL_TRIANGLE_STRIP, this->indicesCount, GL_UNSIGNED_INT, 0));

    this->shaderProg.UnUse();

}

const float* SceneObject::getVertices()
{
    return this->vertices;
}

const unsigned int& SceneObject::getVerticesCount() {
    return this->verticesCount;
}

const unsigned int* SceneObject::getIndices()
{
    return this->indices;
}

const unsigned int& SceneObject::getIndicesCount()
{
    return this->indicesCount;
}

const ShaderProgram SceneObject::getShaderProgram()
{
    return this->shaderProg;
}
