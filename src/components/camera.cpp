#include "camera.h"

Vector2 Camera::get_mouse_world_position(const Window& window) const {
	return _get_inverse_matrix(window) * window.get_mouse_viewport_position();
}

Matrix4 Camera::_get_matrix(const Window& window) const {
	Vector2 viewport_size = window.get_viewport_size();

	Matrix4 view = Matrix4::identity();

	// This could be changed so that the offset is translated when the camera position is translated
	// We'll see how this method goes first, centered property would remain here though if I change it
	Vector2 view_offset = -offset * zoom;

	if (centered) {
		view_offset.x += viewport_size.width / 2;
		view_offset.y += viewport_size.height / 2;
	}

	view.translate(Vector3(view_offset, 0));

	view.rotate(-rotation, Vector3(0, 0, 1));
	view.scale(Vector3(zoom, 1));
	view.translate(Vector3(-position, 0));

	return view;
}

Matrix4 Camera::_get_inverse_matrix(const Window& window) const {
	Vector2 viewport_size = window.get_viewport_size();

	Matrix4 inverse_view = Matrix4::identity();

	inverse_view.translate(Vector3(position, 0));
	inverse_view.scale(Vector3(1 / zoom.x, 1 / zoom.y, 1));
	inverse_view.rotate(rotation, Vector3(0, 0, 1));

	Vector2 inverse_view_offset = -offset * zoom;

	if (centered) {
		inverse_view_offset.x += viewport_size.width / 2.0f;
		inverse_view_offset.y += viewport_size.height / 2.0f;
	}

	inverse_view.translate(Vector3(-inverse_view_offset, 0));

	return inverse_view;
}