#pragma once

#include "maths.h"

class Vector3 {
public:
	union {
		struct { float x, y, z; };
		float axis[3];
	};

	Vector3() : x(0), y(0), z(0) {}
	Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

	float length() const;
	float length_squared() const;

	void normalise();
	Vector3 normalised() const;

	float dot(const Vector3& other) const;
	Vector3 cross(const Vector3& other) const;

	const float& operator[](int index) const;
	float& operator[](int index);

	Vector3 operator+() const;
	Vector3 operator-() const;

	Vector3 operator+(const Vector3& other) const;
	Vector3 operator+(float scalar) const;
	void operator+=(const Vector3& other);
	void operator+=(float scalar);

	Vector3 operator-(const Vector3& other) const;
	Vector3 operator-(float scalar) const;
	void operator-=(const Vector3& other);
	void operator-=(float scalar);

	Vector3 operator*(const Vector3& other) const;
	Vector3 operator*(float scalar) const;
	void operator*=(const Vector3& other);
	void operator*=(float scalar);

	Vector3 operator/(const Vector3& other) const;
	Vector3 operator/(float scalar) const;
	void operator/=(const Vector3& other);
	void operator/=(float scalar);

	bool operator==(const Vector3& other) const;
	bool operator!=(const Vector3& other) const;

	friend Vector3 operator+(float scalar, const Vector3& vector) {
		return vector + scalar;
	}

	friend Vector3 operator*(float scalar, const Vector3& vector) {
		return vector * scalar;
	}
};