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

	Matrix4 new_matrix = *this * translate_matrix;

	x = new_matrix.x;
	y = new_matrix.y;
	z = new_matrix.z;
	w = new_matrix.w;
}

void Matrix4::rotate(float angle, const Vector3& axis) {
	Vector3 axis_normalised = axis.normalised();

	float sin_theta = Maths::sin(angle);
	float cos_theta = Maths::cos(angle);

	Matrix4 rotate_matrix = identity();

	// Formula from https://www.songho.ca/opengl/gl_rotate.html
	rotate_matrix.x.x = Maths::zero_if_almost((1 - cos_theta) * axis_normalised.x * axis_normalised.x + cos_theta);
	rotate_matrix.x.y = Maths::zero_if_almost((1 - cos_theta) * axis_normalised.x * axis_normalised.y + sin_theta * axis_normalised.z);
	rotate_matrix.x.z = Maths::zero_if_almost((1 - cos_theta) * axis_normalised.x * axis_normalised.z - sin_theta * axis_normalised.y);

	rotate_matrix.y.x = Maths::zero_if_almost((1 - cos_theta) * axis_normalised.y * axis_normalised.x - sin_theta * axis_normalised.z);
	rotate_matrix.y.y = Maths::zero_if_almost((1 - cos_theta) * axis_normalised.y * axis_normalised.y + cos_theta);
	rotate_matrix.y.z = Maths::zero_if_almost((1 - cos_theta) * axis_normalised.y * axis_normalised.z + sin_theta * axis_normalised.x);

	rotate_matrix.z.x = Maths::zero_if_almost((1 - cos_theta) * axis_normalised.z * axis_normalised.x + sin_theta * axis_normalised.y);
	rotate_matrix.z.y = Maths::zero_if_almost((1 - cos_theta) * axis_normalised.z * axis_normalised.y - sin_theta * axis_normalised.x);
	rotate_matrix.z.z = Maths::zero_if_almost((1 - cos_theta) * axis_normalised.z * axis_normalised.z + cos_theta);

	Matrix4 new_matrix = *this * rotate_matrix;

	x = new_matrix.x;
	y = new_matrix.y;
	z = new_matrix.z;
	w = new_matrix.w;
}

void Matrix4::scale(const Vector3& factor) {
	Matrix4 scale_matrix = identity();

	scale_matrix.x.x = factor.x;
	scale_matrix.y.y = factor.y;
	scale_matrix.z.z = factor.z;

	Matrix4 new_matrix = *this * scale_matrix;

	x = new_matrix.x;
	y = new_matrix.y;
	z = new_matrix.z;
	w = new_matrix.w;
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

Vector4 Matrix4::operator*(const Vector4& vector) const {
	Vector4 new_vector;

	for (int i = 0; i < 4; i++) {
		float value = 0;

		for (int j = 0; j < 4; j++) {
			value += columns[j][i] * vector[j];
		}

		new_vector[i] = value;
	}

	return new_vector;
}

void Matrix4::operator*=(const Matrix4& other) {
	Matrix4 new_matrix = *this * other;

	x = new_matrix.x;
	y = new_matrix.y;
	z = new_matrix.z;
	w = new_matrix.w;
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