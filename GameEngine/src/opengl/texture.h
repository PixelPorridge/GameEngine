#pragma once

#include <glad/glad.h>
#include <stb/stb_image.h>
#include <string>

class Texture {
private:
	unsigned int id = 0;

public:
	Texture(const std::string& path);
	~Texture();

	void bind(int unit) const;
	const unsigned int get_id() const;
};