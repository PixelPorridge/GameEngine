#pragma once

#include "glad/glad.h"

#include <vector>

class ElementBuffer {
private:
	unsigned int id = 0;

public:
	ElementBuffer(const std::vector<int>& indices);
	~ElementBuffer();

	unsigned int get_id() const;
};