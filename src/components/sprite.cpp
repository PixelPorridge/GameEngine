#include "sprite.h"

Sprite::Sprite(const std::string& path) {
	transform = create_shared<Transform>();
	texture = create_unique<Texture>(path);
}

Matrix4 Sprite::_get_matrix() const {
	Matrix4 matrix = transform->_get_matrix();

	matrix.scale(Vector3(
		texture->get_width(),
		texture->get_height(),
		1
	));

	Vector2 origin(
		offset.x / texture->get_width(),
		offset.y / texture->get_height()
	);

	if (centered) {
		origin -= 0.5f;
	}

	matrix.translate(Vector3(origin, 0));

	return matrix;
}