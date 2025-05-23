#pragma once

#include "glad/glad.h"
#include "shader.h"
#include "maths/matrix4.h"
#include "core/debug.h"

#include <string>

class Program {
private:
	unsigned int id = 0;

public:
	Program(const Shader& vertex, const Shader& fragment);
	~Program();

	unsigned int get_id() const;
	void use() const;

	void set_mat4(const std::string& name, const Matrix4& matrix) const;
};