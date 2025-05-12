#include "matrix4.h"

/*
*	Matrix4
* 
*	Represents a 4x4 matrix.
*	Stored in column-major order.
*	E.g.
*		     [0] [1] [2] [3]
*	[i][0]	| S | 0 | 0 | T |
*	[i][1]	| 0 | S | 0 | T |
*	[i][2]	| 0 | 0 | S | T |
*	[i][3]	| 0 | 0 | 0 | 1 |
*/

void Matrix4::set_identity() {
	x = Vector4(1, 0, 0, 0);
	y = Vector4(0, 1, 0, 0);
	z = Vector4(0, 0, 1, 0);
	w = Vector4(0, 0, 0, 1);
}

void Matrix4::translate(const Vector3& translation) {
	Matrix4 translate_matrix = identity();

	translate_matrix.w.x = translation.x;
	translate_matrix.w.y = translation.y;
	translate_matrix.w.z = translation.z;

	set_matrix(*this * translate_matrix);
}

void Matrix4::rotate(float angle, const Vector3& axis) {
	// Formula from https://www.songho.ca/opengl/gl_rotate.html
	Vector3 axis_normalised = axis.normalised();

	float sin_theta = Maths::sin(angle);
	float cos_theta = Maths::cos(angle);

	Matrix4 rotate_matrix = identity();

	rotate_matrix.x.x = Maths::zero_if_almost((1 - cos_theta) * axis_normalised.x * axis_normalised.x + cos_theta);
	rotate_matrix.x.y = Maths::zero_if_almost((1 - cos_theta) * axis_normalised.x * axis_normalised.y + sin_theta * axis_normalised.z);
	rotate_matrix.x.z = Maths::zero_if_almost((1 - cos_theta) * axis_normalised.x * axis_normalised.z - sin_theta * axis_normalised.y);

	rotate_matrix.y.x = Maths::zero_if_almost((1 - cos_theta) * axis_normalised.y * axis_normalised.x - sin_theta * axis_normalised.z);
	rotate_matrix.y.y = Maths::zero_if_almost((1 - cos_theta) * axis_normalised.y * axis_normalised.y + cos_theta);
	rotate_matrix.y.z = Maths::zero_if_almost((1 - cos_theta) * axis_normalised.y * axis_normalised.z + sin_theta * axis_normalised.x);

	rotate_matrix.z.x = Maths::zero_if_almost((1 - cos_theta) * axis_normalised.z * axis_normalised.x + sin_theta * axis_normalised.y);
	rotate_matrix.z.y = Maths::zero_if_almost((1 - cos_theta) * axis_normalised.z * axis_normalised.y - sin_theta * axis_normalised.x);
	rotate_matrix.z.z = Maths::zero_if_almost((1 - cos_theta) * axis_normalised.z * axis_normalised.z + cos_theta);

	set_matrix(*this * rotate_matrix);
}

void Matrix4::scale(const Vector3& factor) {
	Matrix4 scale_matrix = identity();

	scale_matrix.x.x = factor.x;
	scale_matrix.y.y = factor.y;
	scale_matrix.z.z = factor.z;

	set_matrix(*this * scale_matrix);
}

void Matrix4::object_look_at(const Vector3& target) {
	// Formula from https://www.songho.ca/opengl/gl_lookattoaxes.html
	Vector3 position(w.x, w.y, w.z);
	Vector3 left, up, forward;

	forward = target - position;
	forward.normalise();

	if (Maths::is_almost_zero(Maths::abs(forward.x)) && Maths::is_almost_zero(Maths::abs(forward.z))) {
		if (forward.y > 0) {
			up = Vector3(0, 0, -1);
		} else {
			up = Vector3(0, 0, 1);
		}
	} else {
		up = Vector3(0, 1, 0);
	}

	left = up.cross(forward);
	left.normalise();

	up = forward.cross(left);

	Matrix4 object_look_at_matrix = identity();

	object_look_at_matrix.x.x = left.x;
	object_look_at_matrix.x.y = left.y;
	object_look_at_matrix.x.z = left.z;

	object_look_at_matrix.y.x = up.x;
	object_look_at_matrix.y.y = up.y;
	object_look_at_matrix.y.z = up.z;

	object_look_at_matrix.z.x = forward.x;
	object_look_at_matrix.z.y = forward.y;
	object_look_at_matrix.z.z = forward.z;

	set_matrix(*this * object_look_at_matrix);
}

void Matrix4::camera_look_at(const Vector3& target) {
	// Formula from https://www.songho.ca/opengl/gl_camera.html
	Vector3 position(w.x, w.y, w.z);
	Vector3 left, up, forward;

	forward = position - target;
	forward.normalise();

	up = Vector3(0, 1, 0);

	left = up.cross(forward);
	left.normalise();

	up = forward.cross(left);

	Matrix4 camera_look_at_matrix = identity();

	camera_look_at_matrix.x.x = left.x;
	camera_look_at_matrix.x.y = up.x;
	camera_look_at_matrix.x.z = forward.x;

	camera_look_at_matrix.y.x = left.y;
	camera_look_at_matrix.y.y = up.y;
	camera_look_at_matrix.y.z = forward.y;

	camera_look_at_matrix.z.x = left.z;
	camera_look_at_matrix.z.y = up.z;
	camera_look_at_matrix.z.z = forward.z;

	set_matrix(*this * camera_look_at_matrix);
}

const float* Matrix4::get_pointer() const {
	return &(x.x);
}

const Vector4& Matrix4::operator[](int index) const {
	return columns[index];
}

Vector4& Matrix4::operator[](int index) {
	return columns[index];
}

Matrix4 Matrix4::operator*(const Matrix4& other) const {
	Matrix4 new_matrix;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			float value = 0;

			for (int k = 0; k < 4; k++) {
				value += columns[k][j] * other[i][k];
			}

			new_matrix[i][j] = value;
		}
	}

	return new_matrix;
}

void Matrix4::operator*=(const Matrix4& other) {
	set_matrix(*this * other);
}

bool Matrix4::operator==(const Matrix4& other) const {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (columns[i][j] != other[i][j]) {
				return false;
			}
		}
	}

	return true;
}

bool Matrix4::operator!=(const Matrix4& other) const {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (columns[i][j] != other[i][j]) {
				return true;
			}
		}
	}

	return false;
}

void Matrix4::set_matrix(const Matrix4& matrix) {
	x = matrix.x;
	y = matrix.y;
	z = matrix.z;
	w = matrix.w;
}