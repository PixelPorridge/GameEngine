#include "vertex_array.h"

VertexArray::VertexArray() {
	glCreateVertexArrays(1, &id);
}

void VertexArray::link_vertex_buffer(VertexBuffer vertex_buffer) const {
	glEnableVertexArrayAttrib(id, 0);
	glVertexArrayAttribBinding(id, 0, 0);
	glVertexArrayAttribFormat(id, 0, 3, GL_FLOAT, GL_FALSE, 0);
	glVertexArrayVertexBuffer(id, 0, vertex_buffer.id, 0, 3 * sizeof(GLfloat));
}

void VertexArray::link_element_buffer(ElementBuffer element_buffer) const {
	glVertexArrayElementBuffer(id, element_buffer.id);
}

void VertexArray::bind() const {
	glBindVertexArray(id);
}

void VertexArray::delete_() {
	glDeleteVertexArrays(1, &id);
}