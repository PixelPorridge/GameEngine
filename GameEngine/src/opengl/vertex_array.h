#pragma once

#include <glad/glad.h>

#include "vertex_buffer.h"
#include "element_buffer.h"
#include "vertex_buffer_layout.h"

class VertexArray {
private:
	unsigned int id;

public:
	VertexArray();
	~VertexArray();

	void link_vertex_buffer(VertexBuffer vertex_buffer, VertexBufferLayout layout) const;
	void link_element_buffer(ElementBuffer element_buffer) const;

	const unsigned int get_id() const;
	void bind() const;
};