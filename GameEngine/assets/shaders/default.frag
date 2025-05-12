#version 460 core

in vec3 colour;
in vec2 texture_coords;

layout(binding = 0) uniform sampler2D texture1;
layout(binding = 1) uniform sampler2D texture2;

out vec4 out_colour;

void main() {
	out_colour = mix(texture(texture1, texture_coords), texture(texture2, texture_coords), 0.2) * vec4(colour, 1.0);
}