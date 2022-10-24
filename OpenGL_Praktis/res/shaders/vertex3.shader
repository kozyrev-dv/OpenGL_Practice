#version 330 core
layout(location = 0) in vec3 aPos;

uniform float angle;
out vec4 vertexPosition;

void main() {
	gl_Position = vec4(aPos.x * cos(angle), aPos.y * sin(angle*2), aPos.z, 1.0f);
	vertexPosition = gl_Position;
}