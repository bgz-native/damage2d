#version 330 core

layout (location = 0) out vec4 color;

uniform vec4 u_Color;
uniform vec2 u_LightPos;

in vec4 outPos;

void main()
{
	float intensity = 1.0 / length (outPos.xy - u_LightPos);
	color = u_Color * intensity;
}