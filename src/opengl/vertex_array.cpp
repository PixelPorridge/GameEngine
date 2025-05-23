#include "vertex_array.h"

#include "glad/glad.h"

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

unsigned int VertexArray::get_id() const {
	return id;
}

void VertexArray::link_vertex_buffer(const VertexBuffer& buffer, const VertexBufferLayout& layout) const {
	glVertexArrayVertexBuffer(id, 0, buffer.get_id(), 0, layout.get_stride());

	const std::vector<VertexBufferAttribute>& attributes = layout.get_attributes();

	for (int index = 0; index < attributes.size(); index++) {
		const VertexBufferAttribute& attribute = attributes[index];

		glVertexArrayAttribFormat(id, index, attribute.size, GL_FLOAT, GL_FALSE, attribute.offset);
		glVertexArrayAttribBinding(id, index, 0);
		glEnableVertexArrayAttrib(id, index);
	}
}

void VertexArray::link_element_buffer(const ElementBuffer& buffer) const {
	glVertexArrayElementBuffer(id, buffer.get_id());
}

void VertexArray::bind() const {
	glBindVertexArray(id);
}