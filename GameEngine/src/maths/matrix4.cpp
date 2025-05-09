#include "matrix4.h"

/*
*	Matrix4
* 
*	Represents a 4x4 matrix.
*/

const Vector4& Matrix4::operator[](int index) const {
	return column[index];
}

Vector4& Matrix4::operator[](int index) {
	return column[index];
}

Matrix4 Matrix4::operator*(const Matrix4& other) const {
	Matrix4 new_matrix;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			float value = 0;

			for (int k = 0; k < 4; k++) {
				value += column[k][j] * other[i][k];
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
			value += column[j][i] * vector[j];
		}

		new_vector[i] = value;
	}

	return new_vector;
}

bool Matrix4::operator==(const Matrix4& other) const {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (column[i][j] != other[i][j]) {
				return false;
			}
		}
	}

	return true;
}

bool Matrix4::operator!=(const Matrix4& other) const {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (column[i][j] != other[i][j]) {
				return true;
			}
		}
	}

	return false;
}