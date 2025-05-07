#pragma once

#include <glad/glad.h>
#include <vector>

class VertexBuffer {
private:
	unsigned int id;

public:
	VertexBuffer(std::vector<float> vertices);
	~VertexBuffer();

	const unsigned int get_id() const;
};