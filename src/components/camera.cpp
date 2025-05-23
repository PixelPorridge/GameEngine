#include "camera.h"

Vector2 Camera::get_mouse_world_position(const Window& window) const {
	return _get_inverse_matrix(window) * window.get_mouse_viewport_position();
}

Matrix4 Camera::_get_matrix(const Window& window) const {
	Vector2 viewport_size = window.get_viewport_size();

	Matrix4 matrix = Matrix4::identity();

	// This could be changed so that the offset is translated when the camera position is translated
	// We'll see how this method goes first, centered property would remain here though if I change it
	Vector2 origin = -offset * zoom;

	if (centered) {
		origin.x += viewport_size.width / 2;
		origin.y += viewport_size.height / 2;
	}

	matrix.translate(Vector3(origin, 0));

	matrix.rotate(-rotation, Vector3(0, 0, 1));
	matrix.scale(Vector3(zoom, 1));
	matrix.translate(Vector3(-position, 0));

	return matrix;
}

Matrix4 Camera::_get_inverse_matrix(const Window& window) const {
	Vector2 viewport_size = window.get_viewport_size();

	Matrix4 matrix = Matrix4::identity();

	// Inverse is found by reversing operations and inverting multiply/division in some parts
	matrix.translate(Vector3(position, 0));
	matrix.scale(Vector3(1 / zoom.x, 1 / zoom.y, 1));
	matrix.rotate(rotation, Vector3(0, 0, 1));

	Vector2 origin = -offset * zoom;

	if (centered) {
		origin.x += viewport_size.width / 2.0f;
		origin.y += viewport_size.height / 2.0f;
	}

	matrix.translate(Vector3(-origin, 0));

	return matrix;
}