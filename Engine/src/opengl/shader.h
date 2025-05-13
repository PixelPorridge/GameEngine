#pragma once

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>

class Shader {
private:
	unsigned int id = 0;

public:
	Shader(const std::string& path);
	~Shader();

	const unsigned int get_id() const;
};