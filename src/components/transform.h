#pragma once

#include "core/core.h"
#include "maths/vector2.h"

class Transform {
public:
	Vector2 position;
	float rotation = 0;
	Vector2 scale = Vector2(1, 1);

	const Weak<Transform>& get_parent() const;
	void set_parent(const Shared<Transform>& transform);

private:
	Weak<Transform> parent;
};