#pragma once

#include <glad/glad.h>
#include <stb/stb_image.h>
#include <string>

class Texture {
private:
	unsigned int id;

public:
	Texture(const std::string& path);
	~Texture();

	const unsigned int get_id() const;
	void bind(int unit) const;
};