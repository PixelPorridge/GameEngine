#pragma once

#include <cmath>

class Vector2 {
public:
	float x, y;

	Vector2(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

	float length() const;
	float length_squared() const;

	void normalise();
	Vector2 normalised() const;

	float dot(const Vector2& other) const;

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
};

Vector2 operator+(float scalar, const Vector2& vector) {
	return Vector2(vector.x + scalar, vector.y + scalar);
}

Vector2 operator*(float scalar, const Vector2& vector) {
	return Vector2(vector.x * scalar, vector.y * scalar);
}