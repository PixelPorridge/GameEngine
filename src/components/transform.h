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

	int layer = 0;

	Vector2 get_global_position() const;
	float get_global_rotation() const;
	Vector2 get_global_scale() const;

	void inherit(const Shared<Transform>& transform);

	const Weak<Transform>& _get_parent() const;
	std::vector<Shared<Transform>> _get_parent_chain() const;
	Matrix4 _get_matrix() const;

	int _pre_calculated_layer = 0;
	void _pre_calculate_layer();

private:
	Weak<Transform> parent;
};