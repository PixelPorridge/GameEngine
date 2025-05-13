#version 460 core

in vec2 texture_coordinate;

layout(binding = 0) uniform sampler2D texture_sampler;

out vec4 pixel;

void main() {
	pixel = texture(texture_sampler, texture_coordinate);
}