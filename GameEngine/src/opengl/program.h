#pragma once

#include <glad/glad.h>

#include "shader.h"

class Program {
private:
	unsigned int id = 0;

public:
	Program(const Shader& vertex, const Shader& fragment);
	~Program();

	void use() const;
	const unsigned int get_id() const;
};