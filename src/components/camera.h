#pragma once

#include "maths/vector2.h"

class Camera {
public:
	Vector2 position;
	float rotation = 0;
	float zoom = 1;
};