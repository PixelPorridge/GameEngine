#version 460 core

layout(location = 0) in vec4 vertex;

uniform mat4 projection;
uniform mat4 model;

out vec2 texture_coordinate;

void main() {
	gl_Position = model * vec4(vertex.xy, 0.0, 1.0);
	texture_coordinate = vertex.zw;
}