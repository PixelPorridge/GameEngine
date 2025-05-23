#pragma once

#include <vector>

class VertexBuffer {
private:
	unsigned int id = 0;

public:
	VertexBuffer(const std::vector<float>& vertices);
	~VertexBuffer();

	unsigned int get_id() const;
};