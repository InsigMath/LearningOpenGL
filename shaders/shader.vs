#version 330 core

layout (location = 0) in vec3 aPos;

out vec4 vPos;
uniform float hOffset;

void main()
{
	gl_Position = vec4(aPos.x + hOffset, aPos.y, aPos.z, 1.0);
	vPos = gl_Position;
}