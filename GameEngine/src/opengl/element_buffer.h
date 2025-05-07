#pragma once

#include <glad/glad.h>
#include <vector>

class ElementBuffer {
private:
	unsigned int id;

public:
	ElementBuffer(std::vector<int> indices);
	~ElementBuffer();

	const unsigned int get_id() const;
};