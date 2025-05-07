#include "vertex_array.h"

/*
*	Vertex Array
* 
*	A vertex array is able to store multiple attributes of vertices from vertex and element buffers.
*	We tell it the structure of the data within these buffers so that it can later reference the data during render calls.
*	The data from a vertex array is passed to the vertex shader for rendering.
*/

VertexArray::VertexArray() {
	glCreateVertexArrays(1, &id);
}

VertexArray::~VertexArray() {
	glDeleteVertexArrays(1, &id);
}

void VertexArray::link_vertex_buffer(const VertexBuffer& vertex_buffer, const VertexBufferLayout& layout) const {
	glVertexArrayVertexBuffer(id, 0, vertex_buffer.get_id(), 0, layout.get_stride());

	const std::vector<VertexBufferAttribute>& attributes = layout.get_attributes();

	for (int index = 0; index < attributes.size(); index++) {
		const VertexBufferAttribute& attribute = attributes[index];

		glVertexArrayAttribFormat(id, index, attribute.size, attribute.type, attribute.normalised, attribute.offset);
		glVertexArrayAttribBinding(id, index, 0);
		glEnableVertexArrayAttrib(id, index);
	}
}

void VertexArray::link_element_buffer(const ElementBuffer& element_buffer) const {
	glVertexArrayElementBuffer(id, element_buffer.get_id());
}

const unsigned int VertexArray::get_id() const {
	return id;
}

void VertexArray::bind() const {
	glBindVertexArray(id);
}