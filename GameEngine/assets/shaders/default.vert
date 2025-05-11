#version 460 core

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec2 in_texture_coords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec2 texture_coords;

void main() {
	gl_Position = projection * view * model * vec4(in_position, 1.0);
	texture_coords = in_texture_coords;
}