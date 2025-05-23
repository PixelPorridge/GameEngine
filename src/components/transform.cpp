#include "transform.h"

Vector2 Transform::get_global_position() const {
	std::vector<Shared<Transform>> parents = _get_transform_chain();

	Matrix4 transformation = Matrix4::identity();

	for (int i = parents.size() - 1; i >= 0; i--) {
		Shared<Transform> shared_parent = parents[i];
		transformation *= shared_parent->_get_matrix();
	}

	return transformation * _get_matrix() * Vector2(0, 0);
}

float Transform::get_global_rotation() const {
	std::vector<Shared<Transform>> parents = _get_transform_chain();

	float global_rotation = 0;

	for (int i = parents.size() - 1; i >= 0; i--) {
		Shared<Transform> shared_parent = parents[i];
		global_rotation += shared_parent->rotation;
	}

	return global_rotation + rotation;
}

Vector2 Transform::get_global_scale() const {
	std::vector<Shared<Transform>> parents = _get_transform_chain();

	Vector2 global_scale = Vector2(1, 1);

	for (int i = parents.size() - 1; i >= 0; i--) {
		Shared<Transform> shared_parent = parents[i];
		global_scale *= shared_parent->scale;
	}

	return global_scale * scale;
}

void Transform::link_to(const Shared<Transform>& transform) {
	Weak<Transform> weak_transform = transform;

	while (!weak_transform.expired()) {
		Shared<Transform> shared_transform = weak_transform.lock();

		if (shared_transform.get() == this) {
			Debug::log("Cycle found while attempting to set transform parent!", Debug::ERROR);
			return;
		}

		weak_transform = shared_transform->_get_linked_transform();
	}

	linked_transform = transform;
}

const Weak<Transform>& Transform::_get_linked_transform() const {
	return linked_transform;
}

std::vector<Shared<Transform>> Transform::_get_transform_chain() const {
	std::vector<Shared<Transform>> chain;
	Weak<Transform> weak_transform = linked_transform;

	while (!weak_transform.expired()) {
		Shared<Transform> shared_transform = weak_transform.lock();
		chain.push_back(shared_transform);
		weak_transform = shared_transform->_get_linked_transform();
	}

	return chain;
}

Matrix4 Transform::_get_matrix() const {
	Matrix4 matrix = Matrix4::identity();

	matrix.translate(Vector3(position, 0));
	matrix.rotate(rotation, Vector3(0, 0, 1));
	matrix.scale(Vector3(scale, 1));

	return matrix;
}