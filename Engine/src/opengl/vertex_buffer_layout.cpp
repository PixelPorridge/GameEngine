#include "vertex_buffer_layout.h"

/*
*	Vertex Buffer Layout
*
*	Vertex buffer layouts help to structure the data within a vertex buffer.
*	It does so by pushing attributes into a vector which stores information about the structure of the data.
*	This object can then be provided to a vertex array to tell it about how a vertex buffer is structured.
*/

void VertexBufferLayout::push(int size) {
	attributes.push_back({ size, stride });
	stride += size * sizeof(float);
}

const std::vector<VertexBufferAttribute>& VertexBufferLayout::get_attributes() const {
	return attributes;
}

const int VertexBufferLayout::get_stride() const {
	return stride;
}