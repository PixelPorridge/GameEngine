#include "transform.h"

Vector2 Transform::get_global_position() const {
	std::vector<Shared<Transform>> parents = _get_parents();

	Matrix4 transformation = Matrix4::identity();

	for (int i = parents.size() - 1; i >= 0; i--) {
		Shared<Transform> shared_parent = parents[i];
		transformation *= shared_parent->_get_matrix();
	}

	return transformation * _get_matrix() * Vector2(0, 0);
}

float Transform::get_global_rotation() const {
	std::vector<Shared<Transform>> parents = _get_parents();

	float global_rotation = 0;

	for (int i = parents.size() - 1; i >= 0; i--) {
		Shared<Transform> shared_parent = parents[i];
		global_rotation += shared_parent->rotation;
	}

	return global_rotation + rotation;
}

Vector2 Transform::get_global_scale() const {
	std::vector<Shared<Transform>> parents = _get_parents();

	Vector2 global_scale = Vector2(1, 1);

	for (int i = parents.size() - 1; i >= 0; i--) {
		Shared<Transform> shared_parent = parents[i];
		global_scale *= shared_parent->scale;
	}

	return global_scale * scale;
}

void Transform::set_parent(const Shared<Transform>& transform) {
	parent = transform;
}

const Weak<Transform>& Transform::_get_parent() const {
	return parent;
}

std::vector<Shared<Transform>> Transform::_get_parents() const {
	std::vector<Shared<Transform>> parents;
	Weak<Transform> weak_parent = parent;

	while (!weak_parent.expired()) {
		Shared<Transform> shared_parent = weak_parent.lock();

		auto iterator = std::find_if(parents.begin(), parents.end(),
			[shared_parent](Shared<Transform> check_parent) {
				return shared_parent.get() == check_parent.get();
			}
		);

		if (iterator != parents.end() || shared_parent.get() == this) {
			Debug::log("Transform parent chain contains cycle!", Debug::ERROR);
			break;
		}

		parents.push_back(shared_parent);
		weak_parent = shared_parent->_get_parent();
	}

	return parents;
}

Matrix4 Transform::_get_matrix() const {
	Matrix4 model = Matrix4::identity();

	model.translate(Vector3(position, 0));
	model.rotate(rotation, Vector3(0, 0, 1));
	model.scale(Vector3(scale, 1));

	return model;
}