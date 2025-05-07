#include "vertex_buffer.h"

/*
*	Vertex Buffer
* 
*	A vertex buffer is responsible for storing vertex data on the GPU.
*	It does so by create a buffer on the GPU, which is then provided with the vertex data.
*	Vertex data doesn't have to just be coordinates. It can also be normals, colours, etc.
*	It's important to note that buffers do not store information about the structure of the data.
*	The structure of the data is configured in a vertex array.
*/

VertexBuffer::VertexBuffer(const std::vector<float>& vertices) {
	glCreateBuffers(1, &id);
	glNamedBufferData(id, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer() {
	glDeleteBuffers(1, &id);
}

const unsigned int VertexBuffer::get_id() const {
	return id;
}