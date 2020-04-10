#version 400 core

out vec4			result_color;

uniform vec4		uniform_color;

void				main()
{
	vec4			sampled;

	result_color = uniform_color;
}