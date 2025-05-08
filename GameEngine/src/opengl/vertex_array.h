#pragma once

#include <glad/glad.h>

#include "vertex_buffer.h"
#include "element_buffer.h"
#include "vertex_buffer_layout.h"

class VertexArray {
private:
	unsigned int id = 0;

public:
	VertexArray();
	~VertexArray();

	void link_vertex_buffer(const VertexBuffer& vertex_buffer, const VertexBufferLayout& layout) const;
	void link_element_buffer(const ElementBuffer& element_buffer) const;

	void bind() const;
	const unsigned int get_id() const;
};