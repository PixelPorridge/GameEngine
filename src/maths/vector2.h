#pragma once

#include "maths.h"

class Vector2 {
public:
	union {
		struct { float x, y; };
		struct { float width, height; };
		float axis[2];
	};

	Vector2() : x(0), y(0) {}
	Vector2(float x, float y) : x(x), y(y) {}

	float length() const;
	float length_squared() const;

	void normalise();
	Vector2 normalised() const;

	float dot(const Vector2& other) const;

	bool is_any_zero() const;
	bool is_any_almost_zero() const;
	bool is_almost_zero() const;
	void zero_if_almost();

	const float& operator[](int index) const;
	float& operator[](int index);

	Vector2 operator+() const;
	Vector2 operator-() const;

	Vector2 operator+(const Vector2& other) const;
	Vector2 operator+(float scalar) const;
 	void operator+=(const Vector2& other);
	void operator+=(float scalar);

	Vector2 operator-(const Vector2& other) const;
	Vector2 operator-(float scalar) const;
	void operator-=(const Vector2& other);
	void operator-=(float scalar);

	Vector2 operator*(const Vector2& other) const;
	Vector2 operator*(float scalar) const;
	void operator*=(const Vector2& other);
	void operator*=(float scalar);

	Vector2 operator/(const Vector2& other) const;
	Vector2 operator/(float scalar) const;
	void operator/=(const Vector2& other);
	void operator/=(float scalar);

	bool operator==(const Vector2& other) const;
	bool operator!=(const Vector2& other) const;

	friend Vector2 operator+(float scalar, const Vector2& vector) {
		return vector + scalar;
	}

	friend Vector2 operator*(float scalar, const Vector2& vector) {
		return vector * scalar;
	}
};