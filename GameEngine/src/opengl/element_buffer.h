#pragma once

#include <glad/glad.h>
#include <vector>

class ElementBuffer {
private:
	GLuint id;

public:
	ElementBuffer(std::vector<GLuint> indices);
	~ElementBuffer();

	const GLuint get_id() const;
};