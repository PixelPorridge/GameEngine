#pragma once

#include "maths.h"
#include "vector3.h"
#include "vector4.h"

#include <iostream>

class Matrix4 {
public:
	union {
		struct { Vector4 x, y, z, w; };
		Vector4 columns[4];
	};
	
	Matrix4() : x(1, 0, 0, 0), y(0, 1, 0, 0), z(0, 0, 1, 0), w(0, 0, 0, 1) {}

	void translate(const Vector3& translation);
	void rotate(float angle, const Vector3& axis);
	void scale(const Vector3& factor);

	const float* get_pointer() const;

	const Vector4& operator[](int index) const;
	Vector4& operator[](int index);

	Matrix4 operator*(const Matrix4& other) const;
	Vector4 operator*(const Vector4& vector) const;
	void operator*=(const Matrix4& other);

	bool operator==(const Matrix4& other) const;
	bool operator!=(const Matrix4& other) const;
};