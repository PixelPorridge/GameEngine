#include "shader.h"

/*
*	Shader
* 
*	A shader is a program which runs on the GPU.
*	Vertex shaders perform operations on the vertices of a rendered object. (.vert)
*	Fragment shaders run for every pixel that covers the rendered object. (.frag)
*	Shaders are created by first providing the raw shader code as a string, then compiled.
*/

Shader Shader::from_path(const std::string& path) {
	Shader shader;

	std::ifstream file(path);
	std::stringstream buffer;
	buffer << file.rdbuf();

	std::string source = buffer.str();
	const char* source_c = source.c_str();

	std::string type = path.substr(path.find_last_of('.') + 1);

	if (type == "vert") {
		shader.id = glCreateShader(GL_VERTEX_SHADER);
	} else if (type == "frag") {
		shader.id = glCreateShader(GL_FRAGMENT_SHADER);
	}

	glShaderSource(shader.id, 1, &source_c, nullptr);
	glCompileShader(shader.id);

	return shader;
}

Shader Shader::from_string_vertex(const std::string& source) {
	Shader shader;
	const char* source_c = source.c_str();

	shader.id = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(shader.id, 1, &source_c, nullptr);
	glCompileShader(shader.id);

	return shader;
}

Shader Shader::from_string_fragment(const std::string& source) {
	Shader shader;
	const char* source_c = source.c_str();

	shader.id = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(shader.id, 1, &source_c, nullptr);
	glCompileShader(shader.id);

	return shader;
}

Shader::~Shader() {
	glDeleteShader(id);
}

unsigned int Shader::get_id() const {
	return id;
}