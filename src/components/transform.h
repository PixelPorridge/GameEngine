#pragma once

#include "core/core.h"
#include "maths/vector2.h"
#include "maths/matrix4.h"
#include "utils/debug.h"

#include <vector>
#include <algorithm>

class Transform {
public:
	Vector2 position;
	float rotation = 0;
	Vector2 scale = Vector2(1, 1);

	Vector2 get_global_position() const;
	float get_global_rotation() const;
	Vector2 get_global_scale() const;

	void set_parent(const Shared<Transform>& transform);

	const Weak<Transform>& _get_parent() const;
	std::vector<Shared<Transform>> _get_parents() const;

	Matrix4 _get_matrix() const;

private:
	Weak<Transform> parent;
};