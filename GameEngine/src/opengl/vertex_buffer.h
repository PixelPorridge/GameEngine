#pragma once

#include <glad/glad.h>
#include <vector>

class VertexBuffer {
private:
	GLuint id;

public:
	VertexBuffer(std::vector<GLfloat> vertices);
	~VertexBuffer();

	const GLuint get_id() const;
};