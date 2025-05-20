#pragma once

#include "core/core.h"
#include "transform.h"
#include "opengl/texture.h"

#include <string>

class Sprite {
public:
	Transform transform;
	Unique<Texture> texture;

	bool centered = true;
	Vector2 offset;

	Sprite(const std::string& path);
};