#include "colour.h"

/*
*	Colour
*
*	Represents a colour based on RGBA values.
*/

const float& Colour::operator[](int index) const {
	return channels[index];
}

float& Colour::operator[](int index) {
	return channels[index];
}

Colour Colour::operator+() const {
	return Colour(r, g, b, a);
}

Colour Colour::operator-() const {
	return Colour(-r, -g, -b, -a);
}

Colour Colour::operator+(const Colour& other) const {
	return Colour(r + other.r, g + other.g, b + other.b, a + other.a);
}

Colour Colour::operator+(float scalar) const {
	return Colour(r + scalar, g + scalar, b + scalar, a + scalar);
}

void Colour::operator+=(const Colour& other) {
	r += other.r;
	g += other.g;
	b += other.b;
	a += other.a;
}

void Colour::operator+=(float scalar) {
	r += scalar;
	g += scalar;
	b += scalar;
	a += scalar;
}

Colour Colour::operator-(const Colour& other) const {
	return Colour(r - other.r, g - other.g, b - other.b, a - other.a);
}

Colour Colour::operator-(float scalar) const {
	return Colour(r - scalar, g - scalar, b - scalar, a - scalar);
}

void Colour::operator-=(const Colour& other) {
	r -= other.r;
	g -= other.g;
	b -= other.b;
	a -= other.a;
}

void Colour::operator-=(float scalar) {
	r -= scalar;
	g -= scalar;
	b -= scalar;
	a -= scalar;
}

Colour Colour::operator*(const Colour& other) const {
	return Colour(r * other.r, g * other.g, b * other.b, a * other.a);
}

Colour Colour::operator*(float scalar) const {
	return Colour(r * scalar, g * scalar, b * scalar, a * scalar);
}

void Colour::operator*=(const Colour& other) {
	r *= other.r;
	g *= other.g;
	b *= other.b;
	a *= other.a;
}

void Colour::operator*=(float scalar) {
	r *= scalar;
	g *= scalar;
	b *= scalar;
	a *= scalar;
}

Colour Colour::operator/(const Colour& other) const {
	return Colour(r / other.r, g / other.g, b / other.b, a / other.a);
}

Colour Colour::operator/(float scalar) const {
	return Colour(r / scalar, g / scalar, b / scalar, a / scalar);
}

void Colour::operator/=(const Colour& other) {
	r /= other.r;
	g /= other.g;
	b /= other.b;
	a /= other.a;
}

void Colour::operator/=(float scalar) {
	r /= scalar;
	g /= scalar;
	b /= scalar;
	a /= scalar;
}

bool Colour::operator==(const Colour& other) const {
	return r == other.r && g == other.g && b == other.b && a == other.a;
}

bool Colour::operator!=(const Colour& other) const {
	return r != other.r || g != other.g || b != other.b || a != other.a;
}