#version 400 core

layout (location = 0) in vec3	in_position;

uniform mat4					uniform_projection;
uniform mat4					uniform_view;

void							main()
{
	gl_Position = uniform_projection * uniform_view * vec4(in_position, 1.f);
}