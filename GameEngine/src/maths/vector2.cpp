#include "vector2.h"

/*
*	Vector2
* 
*	Composed of both an x and y component.
*	Vectors can represent a direction with a magnitude, or a point in space.
*/

float Vector2::length() const {
	return std::sqrt(x * x + y * y);
}

float Vector2::length_squared() const {
	return x * x + y * y;
}

Vector2 Vector2::operator-() const {
	return Vector2(-x, -y);
}

Vector2 Vector2::operator+(const Vector2& other) const {
	return Vector2(x + other.x, y + other.y);
}

void Vector2::operator+=(const Vector2& other) {
	x += other.x;
	y += other.y;
}

Vector2 Vector2::operator-(const Vector2& other) const {
	return Vector2(x - other.x, y - other.y);
}

void Vector2::operator-=(const Vector2& other) {
	x -= other.x;
	y -= other.y;
}

Vector2 Vector2::operator*(const Vector2& other) const {
	return Vector2(x * other.x, y * other.y);
}

Vector2 Vector2::operator*(float scalar) const {
	return Vector2(x * scalar, y * scalar);
}

void Vector2::operator*=(const Vector2& other) {
	x *= other.x;
	y *= other.y;
}

void Vector2::operator*=(float scalar) {
	x *= scalar;
	y *= scalar;
}

Vector2 Vector2::operator/(const Vector2& other) const {
	return Vector2(x / other.x, y / other.y);
}

Vector2 Vector2::operator/(float scalar) const {
	return Vector2(x / scalar, y / scalar);
}

void Vector2::operator/=(const Vector2& other) {
	x /= other.x;
	y /= other.y;
}

void Vector2::operator/=(float scalar) {
	x /= scalar;
	y /= scalar;
}

bool Vector2::operator==(const Vector2& other) const {
	return x == other.x && y == other.y;
}

bool Vector2::operator!=(const Vector2& other) const {
	return x != other.x || y != other.y;
}