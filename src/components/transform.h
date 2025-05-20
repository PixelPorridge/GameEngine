#pragma once

#include "maths/vector2.h"

class Transform {
public:
	Vector2 position;
	float rotation = 0;
	Vector2 scale = Vector2(1, 1);
};