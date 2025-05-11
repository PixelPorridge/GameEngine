#include "program.h"

/*
*	Program
* 
*	A program is a chunk of code which runs on the GPU, consisting of multiple shaders which are linked to it.
*	The two shaders which are required to be linked are the vertex and fragment shaders, but others do exist such as the geometry shader.
*	Shaders are attached to the program, allowing it to later be used when rendering.
*/

Program::Program(const Shader& vertex, const Shader& fragment) {
	id = glCreateProgram();

	glAttachShader(id, vertex.get_id());
	glAttachShader(id, fragment.get_id());

	glLinkProgram(id);
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

void Program::set_mat4(const std::string& name, const Matrix4& matrix) const {
	glProgramUniformMatrix4fv(id, glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, matrix.get_pointer());
}