#include "element_buffer.h"

ElementBuffer::ElementBuffer(std::vector<GLuint> indices) {
	glCreateBuffers(1, &id);
	glNamedBufferData(id, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);
}

ElementBuffer::~ElementBuffer() {
	glDeleteBuffers(1, &id);
}

const GLuint ElementBuffer::get_id() const {
	return id;
}