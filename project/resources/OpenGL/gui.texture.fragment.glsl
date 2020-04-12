#version 400 core

in vec2				pass_UV;
out vec4			result_color;

uniform sampler2D	uniform_texture;

void main()
{
	vec4			sampled;

	result_color = texture(uniform_texture, pass_UV);
}