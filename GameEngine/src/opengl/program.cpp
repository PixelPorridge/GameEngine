#include "program.h"

/*
*	Program
* 
*	A program is a chunk of code which runs on the GPU, consisting of multiple shaders which are linked to it.
*	The two shaders which are required to be linked are the vertex and fragment shaders, but others do exist such as the geometry shader.
*	Vertex shaders perform operations on the vertices of a rendered object, then the fragment shader is run for every pixel that covers the rendered object.
*	Shaders are created by first providing the raw shader code as a string, then compiled.
*	The compiled shaders are then attached to the program, which can later be used when rendering.
*/

static std::string read_file(const std::string& file_name) {
	std::ifstream file(file_name);

	std::stringstream buffer;
	buffer << file.rdbuf();

	return buffer.str();
}

Program::Program(const std::string& vertex_file_name, const std::string& fragment_file_name) {
	// Read shader files
	std::string vertex_source = read_file(vertex_file_name);
	std::string fragment_source = read_file(fragment_file_name);

	const char* vertex_source_c = vertex_source.c_str();
	const char* fragment_source_c = fragment_source.c_str();

	// Vertex shader
	unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vertex_source_c, nullptr);
	glCompileShader(vertex_shader);

	// Fragment shader
	unsigned int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fragment_source_c, nullptr);
	glCompileShader(fragment_shader);

	// Create program
	id = glCreateProgram();
	glAttachShader(id, vertex_shader);
	glAttachShader(id, fragment_shader);
	glLinkProgram(id);

	// Delete shaders
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
}

Program::~Program() {
	glDeleteProgram(id);
}

const unsigned int Program::get_id() const {
	return id;
}

void Program::use() const {
	glUseProgram(id);
}