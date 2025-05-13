#pragma once

#include "vector2.h"
#include "vector3.h"

class Vector4 {
public:
	union {
		struct { float x, y, z, w; };
		float axis[4];
	};
	
	Vector4() : x(0), y(0), z(0), w(0) {}
	Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
	Vector4(const Vector2& xy, float z, float w) : x(xy.x), y(xy.y), z(z), w(w) {}
	Vector4(const Vector3& xyz, float w) : x(xyz.x), y(xyz.y), z(xyz.z), w(w) {}

	const float& operator[](int index) const;
	float& operator[](int index);

	Vector4 operator+() const;
	Vector4 operator-() const;

	Vector4 operator+(const Vector4& other) const;
	Vector4 operator+(float scalar) const;
	void operator+=(const Vector4& other);
	void operator+=(float scalar);

	Vector4 operator-(const Vector4& other) const;
	Vector4 operator-(float scalar) const;
	void operator-=(const Vector4& other);
	void operator-=(float scalar);

	Vector4 operator*(const Vector4& other) const;
	Vector4 operator*(float scalar) const;
	void operator*=(const Vector4& other);
	void operator*=(float scalar);

	Vector4 operator/(const Vector4& other) const;
	Vector4 operator/(float scalar) const;
	void operator/=(const Vector4& other);
	void operator/=(float scalar);

	bool operator==(const Vector4& other) const;
	bool operator!=(const Vector4& other) const;

	friend Vector4 operator+(float scalar, const Vector4& vector) {
		return vector + scalar;
	}

	friend Vector4 operator*(float scalar, const Vector4& vector) {
		return vector * scalar;
	}
};