#include "element_buffer.h"

#include "glad/glad.h"

/*
*	Element Buffer
*
*	An element buffer is responsible for storing indices that denote duplicate vertex points which should be shared across multiple triangles.
*	Much like a vertex buffer, it creates the data on a buffer which is stored on the GPU.
*	The vertex array that is using an element buffer does not need to know anything about the structure of the data.
*/

ElementBuffer::ElementBuffer(const std::vector<int>& indices) {
	glCreateBuffers(1, &id);
	glNamedBufferData(id, indices.size() * sizeof(int), indices.data(), GL_STATIC_DRAW);
}

ElementBuffer::~ElementBuffer() {
	glDeleteBuffers(1, &id);
}

unsigned int ElementBuffer::get_id() const {
	return id;
}