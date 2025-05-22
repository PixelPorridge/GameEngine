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

	check_compile_status(shader);

	return shader;
}

Shader Shader::from_string_vertex(const std::string& source) {
	Shader shader;
	const char* source_c = source.c_str();

	shader.id = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(shader.id, 1, &source_c, nullptr);
	glCompileShader(shader.id);

	check_compile_status(shader);

	return shader;
}

Shader Shader::from_string_fragment(const std::string& source) {
	Shader shader;
	const char* source_c = source.c_str();

	shader.id = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(shader.id, 1, &source_c, nullptr);
	glCompileShader(shader.id);

	check_compile_status(shader);

	return shader;
}

Shader::~Shader() {
	glDeleteShader(id);
}

void Shader::check_compile_status(const Shader& shader) {
	int success;
	char info_log[512];
	glGetShaderiv(shader.id, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(shader.id, 512, nullptr, info_log);
		Debug::log("Failed to compile shader: " + std::string(info_log), Debug::ERROR);
	}
}

unsigned int Shader::get_id() const {
	return id;
}