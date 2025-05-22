#include "sprite.h"

Sprite::Sprite(const std::string& path) {
	transform = create_shared<Transform>();
	texture = create_unique<Texture>(path);
}

Matrix4 Sprite::_get_matrix() const {
	Matrix4 model = Matrix4::identity();

	model.translate(Vector3(transform->position, 0));
	model.rotate(transform->rotation, Vector3(0, 0, 1));
	model.scale(Vector3(
		texture->get_width() * transform->scale.x,
		texture->get_height() * transform->scale.y,
		1
	));

	Vector2 model_offset(
		offset.x / texture->get_width(),
		offset.y / texture->get_height()
	);

	if (centered) {
		model_offset -= 0.5f;
	}

	model.translate(Vector3(model_offset, 0));

	return model;
}