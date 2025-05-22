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

bool Vector3::is_any_zero() const {
	return x == 0 || y == 0 || z == 0;
}

bool Vector3::is_any_almost_zero() const {
	return std::abs(x) < EPSILON || std::abs(y) < EPSILON || std::abs(z) < EPSILON;
}

bool Vector3::is_almost_zero() const {
	return std::abs(x) < EPSILON && std::abs(y) < EPSILON && std::abs(z) < EPSILON;
}

void Vector3::zero_if_almost() {
	if (std::abs(x) < EPSILON && std::abs(y) < EPSILON && std::abs(z) < EPSILON) {
		x = 0;
		y = 0;
		z = 0;
	}
}

std::string Vector3::to_string() const {
	return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
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