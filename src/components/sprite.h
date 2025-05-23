#pragma once

#include "core/memory.h"
#include "opengl/texture.h"
#include "transform.h"
#include "maths/matrix4.h"

#include <string>

class Sprite {
public:
	Shared<Transform> transform;
	Shared<Texture> texture;

	bool centered = true;
	Vector2 offset;

	Sprite(const std::string& path);
	Sprite(const Shared<Texture>& texture);

	Matrix4 _get_matrix() const;
};