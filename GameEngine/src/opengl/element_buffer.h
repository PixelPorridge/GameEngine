#pragma once

#include <glad/glad.h>
#include <vector>

class ElementBuffer {
public:
	GLuint id;

	ElementBuffer(std::vector<GLuint> indices);

	void delete_();
};