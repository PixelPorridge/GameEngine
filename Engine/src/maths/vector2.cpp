#include "vector2.h"

/*
*	Vector2
* 
*	Composed of an x and y component.
*	Represents a direction or point in 2D space.
*/

float Vector2::length() const {
	return Maths::sqrt(x * x + y * y);
}

float Vector2::length_squared() const {
	return x * x + y * y;
}

void Vector2::normalise() {
	float length = Maths::sqrt(x * x + y * y);

	x /= length;
	y /= length;
}

Vector2 Vector2::normalised() const {
	float length = Maths::sqrt(x * x + y * y);

	return Vector2(x / length, y / length);
}

float Vector2::dot(const Vector2& other) const {
	return x * other.x + y * other.y;
}

const float& Vector2::operator[](int index) const {
	return axis[index];
}

float& Vector2::operator[](int index) {
	return axis[index];
}

Vector2 Vector2::operator+() const {
	return Vector2(x, y);
}

Vector2 Vector2::operator-() const {
	return Vector2(-x, -y);
}

Vector2 Vector2::operator+(const Vector2& other) const {
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator+(float scalar) const {
	return Vector2(x + scalar, y + scalar);
}

void Vector2::operator+=(const Vector2& other) {
	x += other.x;
	y += other.y;
}

void Vector2::operator+=(float scalar) {
	x += scalar;
	y += scalar;
}

Vector2 Vector2::operator-(const Vector2& other) const {
	return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator-(float scalar) const {
	return Vector2(x - scalar, y - scalar);
}

void Vector2::operator-=(const Vector2& other) {
	x -= other.x;
	y -= other.y;
}

void Vector2::operator-=(float scalar) {
	x -= scalar;
	y -= scalar;
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