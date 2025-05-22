#pragma once

#include "glad/glad.h"
#include "vertex_buffer.h"
#include "vertex_buffer_layout.h"
#include "element_buffer.h"

class VertexArray {
private:
	unsigned int id = 0;

public:
	VertexArray();
	~VertexArray();

	unsigned int get_id() const;

	void link_vertex_buffer(const VertexBuffer& buffer, const VertexBufferLayout& layout) const;
	void link_element_buffer(const ElementBuffer& buffer) const;

	void bind() const;
};