#pragma once

#include "core/core.h"
#include "opengl/texture.h"
#include "transform.h"
#include "maths/matrix4.h"

#include <string>

class Sprite {
public:
	Shared<Transform> transform;
	Unique<Texture> texture;

	bool centered = true;
	Vector2 offset;

	Sprite(const std::string& path);

	Matrix4 _get_matrix() const;
};