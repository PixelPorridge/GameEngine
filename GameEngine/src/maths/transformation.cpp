#include "transformation.h"

/*
*	Transformation
* 
*	Represents a 4x4 transformation matrix.
*	Stored in column-major order.
*	E.g.
*		     [0] [1] [2] [3]
*	[i][0]	| S | 0 | 0 | T |
*	[i][1]	| 0 | S | 0 | T |
*	[i][2]	| 0 | 0 | S | T |
*	[i][3]	| 0 | 0 | 0 | 1 |
*/

void Transformation::translate(const Vector3& translation) {
	w += x * translation.x + y * translation.y + z * translation.z;
}

void Transformation::rotate(float angle, const Vector3& axis) {
	Vector3 axis_normalised = axis.normalised();

	float sin_theta = Maths::sin(angle);
	float cos_theta = Maths::cos(angle);

	Transformation rotation;

	// Formula from https://learnopengl.com/Getting-started/Transformations
	rotation.x.x = Maths::zero_if_almost(cos_theta + Maths::pow(axis_normalised.x, 2.0f) * (1 - cos_theta));
	rotation.x.y = Maths::zero_if_almost(axis_normalised.y * axis_normalised.x * (1 - cos_theta) + axis_normalised.z * sin_theta);
	rotation.x.z = Maths::zero_if_almost(axis_normalised.z * axis_normalised.x * (1 - cos_theta) - axis_normalised.y * sin_theta);

	rotation.y.x = Maths::zero_if_almost(axis_normalised.x * axis_normalised.y * (1 - cos_theta) - axis_normalised.z * sin_theta);
	rotation.y.y = Maths::zero_if_almost(cos_theta + Maths::pow(axis_normalised.y, 2.0f) * (1 - cos_theta));
	rotation.y.z = Maths::zero_if_almost(axis_normalised.z * axis_normalised.y * (1 - cos_theta) + axis_normalised.x * sin_theta);

	rotation.z.x = Maths::zero_if_almost(axis_normalised.x * axis_normalised.z * (1 - cos_theta) + axis_normalised.y * sin_theta);
	rotation.z.y = Maths::zero_if_almost(axis_normalised.y * axis_normalised.z * (1 - cos_theta) - axis_normalised.x * sin_theta);
	rotation.z.z = Maths::zero_if_almost(cos_theta + Maths::pow(axis_normalised.z, 2.0f) * (1 - cos_theta));

	Transformation new_transformation = (*this) * rotation;

	x = new_transformation.x;
	y = new_transformation.y;
	z = new_transformation.z;
	w = new_transformation.w;
}

void Transformation::scale(const Vector3& factor) {
	x *= factor.x;
	y *= factor.y;
	z *= factor.z;
}

const Vector4& Transformation::operator[](int index) const {
	return columns[index];
}

Vector4& Transformation::operator[](int index) {
	return columns[index];
}

Transformation Transformation::operator*(const Transformation& other) const {
	Transformation new_transformation;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			float value = 0;

			for (int k = 0; k < 4; k++) {
				value += columns[k][j] * other[i][k];
			}

			new_transformation[i][j] = value;
		}
	}

	return new_transformation;
}

Vector4 Transformation::operator*(const Vector4& vector) const {
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

void Transformation::operator*=(const Transformation& other) {
	Transformation new_transformation = *this * other;

	x = new_transformation.x;
	y = new_transformation.y;
	z = new_transformation.z;
	w = new_transformation.w;
}

bool Transformation::operator==(const Transformation& other) const {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (columns[i][j] != other[i][j]) {
				return false;
			}
		}
	}

	return true;
}

bool Transformation::operator!=(const Transformation& other) const {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (columns[i][j] != other[i][j]) {
				return true;
			}
		}
	}

	return false;
}