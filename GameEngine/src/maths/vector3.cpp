#include "vector3.h"

/*
*	Vector3
*
*	Composed of an x, y, and z component.
*	Represents a direction or point in 3D space.
*/

float Vector3::length() const {
	return std::sqrt(x * x + y * y + z * z);
}

float Vector3::length_squared() const {
	return x * x + y * y + z * z;
}

void Vector3::normalise() {
	float length = std::sqrt(x * x + y * y + z * z);

	x /= length;
	y /= length;
	z /= length;
}

Vector3 Vector3::normalised() const {
	float length = std::sqrt(x * x + y * y + z * z);

	return Vector3(x / length, y / length, z / length);
}

float Vector3::dot(const Vector3& other) const {
	return x * other.x + y * other.y + z * other.z;
}

Vector3 Vector3::cross(const Vector3& other) const {
	return Vector3(
		y * other.z - z * other.y,
		z * other.x - x * other.z,
		x * other.y - y * other.x
	);
}

const float& Vector3::operator[](int index) const {
	return axis[index];
}

float& Vector3::operator[](int index) {
	return axis[index];
}

Vector3 Vector3::operator+() const {
	return Vector3(x, y, z);
}

Vector3 Vector3::operator-() const {
	return Vector3(-x, -y, -z);
}

Vector3 Vector3::operator+(const Vector3& other) const {
	return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator+(float scalar) const {
	return Vector3(x + scalar, y + scalar, z + scalar);
}

void Vector3::operator+=(const Vector3& other) {
	x += other.x;
	y += other.y;
	z += other.z;
}

void Vector3::operator+=(float scalar) {
	x += scalar;
	y += scalar;
	z += scalar;
}

Vector3 Vector3::operator-(const Vector3& other) const {
	return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator-(float scalar) const {
	return Vector3(x - scalar, y - scalar, z - scalar);
}

void Vector3::operator-=(const Vector3& other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
}

void Vector3::operator-=(float scalar) {
	x -= scalar;
	y -= scalar;
	z -= scalar;
}

Vector3 Vector3::operator*(const Vector3& other) const {
	return Vector3(x * other.x, y * other.y, z * other.z);
}

Vector3 Vector3::operator*(float scalar) const {
	return Vector3(x * scalar, y * scalar, z * scalar);
}

void Vector3::operator*=(const Vector3& other) {
	x *= other.x;
	y *= other.y;
	z *= other.z;
}

void Vector3::operator*=(float scalar) {
	x *= scalar;
	y *= scalar;
	z *= scalar;
}

Vector3 Vector3::operator/(const Vector3& other) const {
	return Vector3(x / other.x, y / other.y, z / other.z);
}

Vector3 Vector3::operator/(float scalar) const {
	return Vector3(x / scalar, y / scalar, z / scalar);
}

void Vector3::operator/=(const Vector3& other) {
	x /= other.x;
	y /= other.y;
	z /= other.z;
}

void Vector3::operator/=(float scalar) {
	x /= scalar;
	y /= scalar;
	z /= scalar;
}

bool Vector3::operator==(const Vector3& other) const {
	return x == other.x && y == other.y && z == other.z;
}

bool Vector3::operator!=(const Vector3& other) const {
	return x != other.x || y != other.y || z != other.z;
}