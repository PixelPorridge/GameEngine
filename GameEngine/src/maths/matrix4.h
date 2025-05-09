#pragma once

#include "vector4.h"

class Matrix4 {
public:
	union {
		struct { Vector4 x, y, z, w; };
		Vector4 column[4];
	};

	Matrix4() : x(1, 0, 0, 0), y(0, 1, 0, 0), z(0, 0, 1, 0), w(0, 0, 0, 1) {}

	const Vector4& operator[](int index) const;
	Vector4& operator[](int index);

	Matrix4 operator*(const Matrix4& other) const;
	Vector4 operator*(const Vector4& vector) const;

	bool operator==(const Matrix4& other) const;
	bool operator!=(const Matrix4& other) const;
};