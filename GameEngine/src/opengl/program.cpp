#include "program.h"

std::string read_file(const std::string& file_name) {
	std::ifstream file(file_name);

	std::stringstream buffer;
	buffer << file.rdbuf();

	return buffer.str();
}

Program::Program(const std::string& vertex_file_name, const std::string& fragment_file_name) {
	// Read shader files
	std::string vertex_source = read_file(vertex_file_name);
	std::string fragment_source = read_file(fragment_file_name);

	const GLchar* vertex_source_c = vertex_source.c_str();
	const GLchar* fragment_source_c = fragment_source.c_str();

	// Vertex shader
	GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vertex_source_c, nullptr);
	glCompileShader(vertex_shader);

	// Fragment shader
	GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
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

void Program::use() const {
	glUseProgram(id);
}

void Program::delete_() {
	glDeleteProgram(id);
}