#version 400 core

layout (location = 0) in vec2	coordinate;

uniform mat4					uniform_projection;

void							main()
{
	gl_Position = uniform_projection * vec4(coordinate, 0, 1);
}