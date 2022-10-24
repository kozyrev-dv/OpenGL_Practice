#version 330 core

in vec4 vertexPosition;
out vec4 FragColor;

void main() {
	FragColor = (vertexPosition+1.0f)/2.0f;
}