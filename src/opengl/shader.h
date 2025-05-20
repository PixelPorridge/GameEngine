#pragma once

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>

class Shader {
private:
	unsigned int id = 0;

	Shader() {}

public:
	~Shader();

	static Shader from_path(const std::string& path);
	static Shader from_string_vertex(const std::string& source);
	static Shader from_string_fragment(const std::string& source);

	unsigned int get_id() const;
};