#pragma once

#include <glad/glad.h>
#include <vector>

/*
*	Vertex Buffer Layout
* 
*	Vertex buffer layouts help to structure the data within a vertex buffer.
*	It does so by pushing attributes into a vector which stores information about the structure of the data.
*	This object can then be provided to a vertex array to tell it about how a vertex buffer is structured.
*/

struct VertexBufferAttribute {
	int size;
	unsigned int type;
	bool normalised;
	int offset;
};

class VertexBufferLayout {
private:
	std::vector<VertexBufferAttribute> attributes;
	int stride = 0;

public:
	template<typename T>
	void push(int size);

	template<>
	void push<float>(int size) {
		attributes.push_back({size, GL_FLOAT, GL_FALSE, stride});
		stride += size * sizeof(float);
	}

	template<>
	void push<int>(int size) {
		attributes.push_back({size, GL_INT, GL_FALSE, stride});
		stride += size * sizeof(int);
	}

	inline const std::vector<VertexBufferAttribute>& get_attributes() const {
		return attributes;
	}

	inline const int get_stride() const {
		return stride;
	}
};