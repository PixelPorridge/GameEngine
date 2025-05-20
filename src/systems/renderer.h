#pragma once

#include "core/core.h"
#include "utils/debug.h"
#include "maths/matrix4.h"
#include "components/sprite.h"
#include "components/camera.h"
#include "systems/window.h"
#include "opengl/program.h"
#include "opengl/shader.h"
#include "opengl/vertex_buffer.h"
#include "opengl/vertex_buffer_layout.h"
#include "opengl/element_buffer.h"
#include "opengl/vertex_array.h"

#include <vector>
#include <string>

class Renderer {
private:
	std::vector<Weak<Sprite>> sprites; // List of sprites to draw on next render call

	Unique<VertexBuffer> vertex_buffer;
	Unique<ElementBuffer> element_buffer;
	Unique<VertexArray> vertex_array;
	Unique<Program> program;

public:
	Renderer();

	void add(const Shared<Sprite>& sprite); // Adds the sprite to the queue for rendering
	void render(const Window& window, const Camera& camera); // Renders all the queued sprites then clears the list
};

const std::string default_source_vertex = "#version 460 core\n"
	"layout(location = 0) in vec4 vertex;\n"
	"uniform mat4 projection;\n"
	"uniform mat4 view;\n"
	"uniform mat4 model;\n"
	"out vec2 texture_coordinates;\n"
	"void main() {\n"
	"	gl_Position = projection * view * model * vec4(vertex.xy, 0.0, 1.0);\n"
	"	texture_coordinates = vertex.zw;\n"
	"}\0";

const std::string default_source_fragment = "#version 460 core\n"
	"in vec2 texture_coordinates;\n"
	"layout(binding = 0) uniform sampler2D texture_sampler;\n"
	"out vec4 pixel;\n"
	"void main() {\n"
	"	pixel = texture(texture_sampler, texture_coordinates);\n"
	"}\0";