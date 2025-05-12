#version 460 core

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec3 in_colour;
layout(location = 2) in vec2 in_texture_coords;

uniform mat4 model;

out vec3 colour;
out vec2 texture_coords;

void main() {
	gl_Position = model * vec4(in_position, 1.0);
	colour = in_colour;
	texture_coords = in_texture_coords;
}