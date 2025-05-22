#pragma once

#include "maths/vector2.h"
#include "maths/matrix4.h"
#include "systems/window.h"

class Camera {
public:
	Vector2 position;
	float rotation = 0;
	Vector2 zoom = Vector2(1, 1);

	bool centered = false;
	Vector2 offset;

	Vector2 get_mouse_world_position(const Window& window) const;

	Matrix4 _get_matrix(const Window& window) const;
	Matrix4 _get_inverse_matrix(const Window& window) const;
};