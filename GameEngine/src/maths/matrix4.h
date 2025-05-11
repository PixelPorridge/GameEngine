#pragma once

#include "maths.h"
#include "vector3.h"
#include "vector4.h"

class Matrix4 {
public:
	union {
		struct { Vector4 x, y, z, w; };
		Vector4 columns[4];
	};
	
	Matrix4() : x(0, 0, 0, 0), y(0, 0, 0, 0), z(0, 0, 0, 0), w(0, 0, 0, 0) {}
	Matrix4(const Vector4& x, const Vector4& y, const Vector4& z, const Vector4& w) : x(x), y(y), z(z), w(w) {}

	static inline Matrix4 identity() {
		return Matrix4(
			Vector4(1, 0, 0, 0),
			Vector4(0, 1, 0, 0),
			Vector4(0, 0, 1, 0),
			Vector4(0, 0, 0, 1)
		);
	}

	static inline Matrix4 perspective(float fov, float aspect_ratio, float near, float far) {
		// Formula from https://www.songho.ca/opengl/gl_projectionmatrix.html
		float tangent = Maths::tan(fov / 2);
		float top = near * tangent;
		float right = top * aspect_ratio;

		return Matrix4(
			Vector4(near / right, 0, 0, 0),
			Vector4(0, near / top, 0, 0),
			Vector4(0, 0, -(far + near) / (far - near), -1),
			Vector4(0, 0, -2 * far * near / (far - near), 0)
		);
	}

	static inline Matrix4 orthographic(float left, float right, float bottom, float top, float near, float far) {
		// Formula from https://www.songho.ca/opengl/gl_projectionmatrix.html
		return Matrix4(
			Vector4(2 / (right - left), 0, 0, 0),
			Vector4(0, 2 / (top - bottom), 0, 0),
			Vector4(0, 0, -2 / (far - near), 0),
			Vector4(-(right + left) / (right - left), -(top + bottom) / (top - bottom), -(far + near) / (far - near), 1)
		);
	}

	void set_identity();

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