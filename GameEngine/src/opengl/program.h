#pragma once

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Program {
private:
	unsigned int id;

public:
	Program(const std::string& vertex_file, const std::string& fragment_file);
	~Program();

	const unsigned int get_id() const;
	void use() const;
};