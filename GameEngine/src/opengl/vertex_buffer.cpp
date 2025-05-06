#include "vertex_buffer.h"

VertexBuffer::VertexBuffer(std::vector<GLfloat> vertices) {
	glCreateBuffers(1, &id);
	glNamedBufferData(id, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer() {
	glDeleteBuffers(1, &id);
}

const GLuint VertexBuffer::get_id() const {
	return id;
}