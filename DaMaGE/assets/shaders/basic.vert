#version 330 core

layout (location = 0) in vec4 position;

uniform mat4 u_ProjMat;
uniform mat4 u_ViewMat = mat4(1.0);
uniform mat4 u_ModelMat = mat4(1.0);

out vec4 outPos;

void main()
{
	gl_Position = u_ProjMat * u_ViewMat * u_ModelMat * position;
	outPos = position;

}