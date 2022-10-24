#version 330 core

in vec2 texCoords;
out vec4 FragColor;

uniform sampler2D textureImage1;
uniform sampler2D textureImage2;
uniform float mixRatio;

void main()
{

    FragColor = mix(texture(textureImage1, texCoords), texture(textureImage2, texCoords), mixRatio);
}