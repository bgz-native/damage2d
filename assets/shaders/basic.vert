#version 330 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 color;

uniform mat4 u_ProjMat;
uniform mat4 u_ViewMat = mat4(1.0);
uniform mat4 u_ModelMat = mat4(1.0);

out DATA
{
	vec4 position;
	vec4 color;
} vs_out;


void main()
{
	gl_Position = u_ProjMat * u_ViewMat * u_ModelMat * position;
	vs_out.position = u_ModelMat * position;
	vs_out.color = color;
}