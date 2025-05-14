#pragma once

#include <glad/glad.h>
#include <vector>

class VertexBuffer {
private:
	unsigned int id = 0;

public:
	VertexBuffer(const std::vector<float>& vertices);
	~VertexBuffer();

	const unsigned int get_id() const;
};