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
	Program(const std::string& vertex_path, const std::string& fragment_path);
	~Program();

	const unsigned int get_id() const;
	void use() const;
};