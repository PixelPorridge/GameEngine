#pragma once

#include "vertex_buffer.h"
#include "element_buffer.h"

#include <glad/glad.h>

class VertexArray {

public:
	GLuint id;

	VertexArray();

	void link_vertex_buffer(VertexBuffer vertex_buffer) const;
	void link_element_buffer(ElementBuffer element_buffer) const;

	void bind() const;

	void delete_();
};