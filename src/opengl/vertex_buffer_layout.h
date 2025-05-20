#pragma once

#include <glad/glad.h>
#include <vector>

struct VertexBufferAttribute {
	int size;
	int offset;
};

class VertexBufferLayout {
private:
	std::vector<VertexBufferAttribute> attributes;
	int stride = 0;

public:
	void push(int size);

	const std::vector<VertexBufferAttribute>& get_attributes() const;
	int get_stride() const;
};