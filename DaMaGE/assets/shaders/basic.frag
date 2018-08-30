#version 330 core

layout (location = 0) out vec4 color;

uniform vec4 u_Color;
uniform vec2 u_LightPos;

in vec4 outPos;

in DATA
{
	vec4 position;
	vec4 color;
} fs_in;


void main()
{
	float intensity = 1.0 / length (fs_in.position.xy - u_LightPos);
	color = fs_in.color * intensity;
}