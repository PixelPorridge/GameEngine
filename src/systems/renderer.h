#pragma once

#include "core/core.h"
#include "opengl/program.h"
#include "opengl/shader.h"
#include "opengl/vertex_array.h"
#include "opengl/vertex_buffer.h"
#include "opengl/vertex_buffer_layout.h"
#include "opengl/element_buffer.h"
#include "systems/window.h"
#include "components/camera.h"
#include "components/sprite.h"
#include "maths/matrix4.h"
#include "maths/vector2.h"

#include <string>
#include <vector>

class Renderer {
private:
	std::vector<Weak<Sprite>> sprites;

	Unique<VertexBuffer> vertex_buffer;
	Unique<ElementBuffer> element_buffer;
	Unique<VertexArray> vertex_array;
	Unique<Program> program;

public:
	Renderer();

	void add(const Shared<Sprite>& sprite);
	void render(const Window& window, const Camera& camera = Camera());
};

const std::string default_vertex_source = "#version 460 core\n"
	"layout(location = 0) in vec4 vertex;\n"
	"uniform mat4 projection;\n"
	"uniform mat4 view;\n"
	"uniform mat4 model;\n"
	"out vec2 texture_coordinates;\n"
	"void main() {\n"
	"	gl_Position = projection * view * model * vec4(vertex.xy, 0.0, 1.0);\n"
	"	texture_coordinates = vertex.zw;\n"
	"}\0";

const std::string default_fragment_source = "#version 460 core\n"
	"in vec2 texture_coordinates;\n"
	"layout(binding = 0) uniform sampler2D texture_sampler;\n"
	"out vec4 pixel;\n"
	"void main() {\n"
	"	pixel = texture(texture_sampler, texture_coordinates);\n"
	"}\0";