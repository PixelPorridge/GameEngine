#pragma once

#include "maths/vector2.h"

class Camera {
public:
	Vector2 position;
	float rotation = 0;
	Vector2 zoom = Vector2(1, 1);

	bool centered = true;
	Vector2 offset;
};