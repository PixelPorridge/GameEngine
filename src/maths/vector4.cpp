#include "vector4.h"

/*
*	Vector4
*
*	Composed of an x, y, z, and w component.
*	This vector type is not typically used to represent a point in space.
*/

std::string Vector4::to_string() const {
	return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w) + ")";
}

const float& Vector4::operator[](int index) const {
	return axis[index];
}

float& Vector4::operator[](int index) {
	return axis[index];
}

Vector4 Vector4::operator+() const {
	return Vector4(x, y, z, w);
}

Vector4 Vector4::operator-() const {
	return Vector4(-x, -y, -z, -w);
}

Vector4 Vector4::operator+(const Vector4& other) const {
	return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
}

Vector4 Vector4::operator+(float scalar) const {
	return Vector4(x + scalar, y + scalar, z + scalar, w + scalar);
}

void Vector4::operator+=(const Vector4& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
}

void Vector4::operator+=(float scalar) {
	x += scalar;
	y += scalar;
	z += scalar;
	w += scalar;
}

Vector4 Vector4::operator-(const Vector4& other) const {
	return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
}

Vector4 Vector4::operator-(float scalar) const {
	return Vector4(x - scalar, y - scalar, z - scalar, w - scalar);
}

void Vector4::operator-=(const Vector4& other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;
}

void Vector4::operator-=(float scalar) {
	x -= scalar;
	y -= scalar;
	z -= scalar;
	w -= scalar;
}

Vector4 Vector4::operator*(const Vector4& other) const {
	return Vector4(x * other.x, y * other.y, z * other.z, w * other.w);
}

Vector4 Vector4::operator*(float scalar) const {
	return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
}

void Vector4::operator*=(const Vector4& other) {
	x *= other.x;
	y *= other.y;
	z *= other.z;
	w *= other.w;
}

void Vector4::operator*=(float scalar) {
	x *= scalar;
	y *= scalar;
	z *= scalar;
	w *= scalar;
}

Vector4 Vector4::operator/(const Vector4& other) const {
	return Vector4(x / other.x, y / other.y, z / other.z, w / other.w);
}

Vector4 Vector4::operator/(float scalar) const {
	return Vector4(x / scalar, y / scalar, z / scalar, w / scalar);
}

void Vector4::operator/=(const Vector4& other) {
	x /= other.x;
	y /= other.y;
	z /= other.z;
	w /= other.w;
}

void Vector4::operator/=(float scalar) {
	x /= scalar;
	y /= scalar;
	z /= scalar;
	w /= scalar;
}

bool Vector4::operator==(const Vector4& other) const {
	return x == other.x && y == other.y && z == other.z && w == other.w;
}

bool Vector4::operator!=(const Vector4& other) const {
	return x != other.x || y != other.y || z != other.z || w != other.w;
}