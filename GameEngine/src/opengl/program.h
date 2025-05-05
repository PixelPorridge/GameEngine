#pragma once

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Program {
public:
	GLuint id;

	Program(const std::string& vertex_file, const std::string& fragment_file);

	void use() const;
	void delete_();
};