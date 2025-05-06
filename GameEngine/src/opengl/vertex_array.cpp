#include "vertex_array.h"

VertexArray::VertexArray() {
	glCreateVertexArrays(1, &id);
}

VertexArray::~VertexArray() {
	glDeleteVertexArrays(1, &id);
}

void VertexArray::link_vertex_buffer(VertexBuffer vertex_buffer, VertexBufferLayout layout) const {
	glVertexArrayVertexBuffer(id, 0, vertex_buffer.get_id(), 0, layout.get_stride());

	const std::vector<VertexBufferAttribute>& attributes = layout.get_attributes();

	for (GLuint index = 0; index < attributes.size(); index++) {
		const VertexBufferAttribute& attribute = attributes[index];

		glVertexArrayAttribFormat(id, index, attribute.size, attribute.type, attribute.normalised, attribute.offset);
		glVertexArrayAttribBinding(id, index, 0);
		glEnableVertexArrayAttrib(id, index);
	}
}

void VertexArray::link_element_buffer(ElementBuffer element_buffer) const {
	glVertexArrayElementBuffer(id, element_buffer.get_id());
}

const GLuint VertexArray::get_id() const {
	return id;
}

void VertexArray::bind() const {
	glBindVertexArray(id);
}