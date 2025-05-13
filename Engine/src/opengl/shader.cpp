#include "shader.h"

/*
*	Shader
* 
*	A shader is a program which runs on the GPU.
*	Vertex shaders perform operations on the vertices of a rendered object. (.vert)
*	Fragment shaders run for every pixel that covers the rendered object. (.frag)
*	Shaders are created by first providing the raw shader code as a string, then compiled.
*/

static std::string read_file(const std::string& path) {
	std::ifstream file(path);

	std::stringstream buffer;
	buffer << file.rdbuf();

	return buffer.str();
}

Shader::Shader(const std::string& path) {
	std::string source = read_file(path);
	const char* source_c = source.c_str();

	std::string type = path.substr(path.find_last_of('.') + 1);

	if (type == "vert") {
		id = glCreateShader(GL_VERTEX_SHADER);
	} else if (type == "frag") {
		id = glCreateShader(GL_FRAGMENT_SHADER);
	}

	glShaderSource(id, 1, &source_c, nullptr);
	glCompileShader(id);
}

Shader::~Shader() {
	glDeleteShader(id);
}

const unsigned int Shader::get_id() const {
	return id;
}