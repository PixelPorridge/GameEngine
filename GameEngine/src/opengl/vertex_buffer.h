#pragma once

#include <glad/glad.h>
#include <vector>

class VertexBuffer {
public:
	GLuint id;

	VertexBuffer(std::vector<GLfloat> vertices);

	void delete_();
};