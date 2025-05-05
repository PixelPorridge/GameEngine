#include "element_buffer.h"

ElementBuffer::ElementBuffer(std::vector<GLuint> indices) {
	glCreateBuffers(1, &id);
	glNamedBufferData(id, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);
}

void ElementBuffer::delete_() {
	glDeleteBuffers(1, &id);
}