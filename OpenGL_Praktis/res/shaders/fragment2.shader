#version 330 core
out vec4 FragColor;

in vec4 vertexColor;
uniform vec4 colorOffset;

void main()
{
    FragColor = (vertexColor+colorOffset);

}