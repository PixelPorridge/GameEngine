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

	void link_vertex_buffer(const VertexBuffer& vertex_buffer, const VertexBufferLayout& layout) const;
	void link_element_buffer(const ElementBuffer& element_buffer) const;

	const unsigned int get_id() const;
	void bind() const;
};