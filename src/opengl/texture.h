#pragma once

#include "glad/glad.h"
#include "stb/stb_image.h"
#include "core/debug.h"

#include <string>

class Texture {
private:
	unsigned int id = 0;

	int width = 0;
	int height = 0;

public:
	Texture(const std::string& path);
	~Texture();

	unsigned int get_id() const;

	int get_width() const;
	int get_height() const;

	void bind(int unit) const;
};