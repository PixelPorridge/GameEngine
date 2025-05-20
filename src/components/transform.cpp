#include "transform.h"

const Weak<Transform>& Transform::get_parent() const {
	return parent;
}

void Transform::set_parent(const Shared<Transform>& transform) {
	parent = transform;
}