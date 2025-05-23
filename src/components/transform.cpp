#include "transform.h"

Vector2 Transform::get_global_position() const {
	Matrix4 transformation = Matrix4::identity();
	
	std::vector<Shared<Transform>> chain = _get_parent_chain();

	for (int i = chain.size() - 1; i >= 0; i--) {
		transformation *= chain[i]->_get_matrix();
	}

	return transformation * position;
}

float Transform::get_global_rotation() const {
	float global_rotation = 0;

	std::vector<Shared<Transform>> chain = _get_parent_chain();

	for (int i = chain.size() - 1; i >= 0; i--) {
		global_rotation += chain[i]->rotation;
	}

	return global_rotation + rotation;
}

Vector2 Transform::get_global_scale() const {
	Vector2 global_scale = Vector2(1, 1);

	std::vector<Shared<Transform>> chain = _get_parent_chain();

	for (int i = chain.size() - 1; i >= 0; i--) {
		global_scale *= chain[i]->scale;
	}

	return global_scale * scale;
}

void Transform::inherit(const Shared<Transform>& transform) {
	Weak<Transform> weak_transform = transform;

	while (!weak_transform.expired()) {
		Shared<Transform> shared_transform = weak_transform.lock();

		if (shared_transform.get() == this) {
			Debug::log("Cycle found while attempting to set transform parent!", Debug::ERROR);
			return;
		}

		weak_transform = shared_transform->_get_parent();
	}

	parent = transform;
}

const Weak<Transform>& Transform::_get_parent() const {
	return parent;
}

std::vector<Shared<Transform>> Transform::_get_parent_chain() const {
	std::vector<Shared<Transform>> chain;
	Weak<Transform> weak_transform = parent;

	while (!weak_transform.expired()) {
		Shared<Transform> shared_transform = weak_transform.lock();
		chain.push_back(shared_transform);
		weak_transform = shared_transform->_get_parent();
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

void Transform::_pre_calculate_layer() {
	_pre_calculated_layer = layer;

	std::vector<Shared<Transform>> chain = _get_parent_chain();

	for (int i = 0; i < chain.size(); i++) {
		Shared<Transform> transform = chain[i];
		_pre_calculated_layer += transform->layer;
	}
}