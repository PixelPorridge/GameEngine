#pragma once

#include <cmath>
#include <iostream>

#include "vector4.h"
#include "vector3.h"

class Transformation {
public:
	union {
		struct { Vector4 x, y, z, w; };
		Vector4 columns[4];
	};

	Transformation() : x(1, 0, 0, 0), y(0, 1, 0, 0), z(0, 0, 1, 0), w(0, 0, 0, 1) {}

	void translate(const Vector3& translation);
	void rotate(float angle, const Vector3& axis);
	void scale(const Vector3& factor);

	const Vector4& operator[](int index) const;
	Vector4& operator[](int index);

	Transformation operator*(const Transformation& other) const;
	Vector4 operator*(const Vector4& vector) const;
	void operator*=(const Transformation& other);

	bool operator==(const Transformation& other) const;
	bool operator!=(const Transformation& other) const;

	friend std::ostream& operator<<(std::ostream& os, const Transformation& transformation) {
		os << transformation.x.x << ' ' << transformation.y.x << ' ' << transformation.z.x << ' ' << transformation.w.x << std::endl;
		os << transformation.x.y << ' ' << transformation.y.y << ' ' << transformation.z.y << ' ' << transformation.w.y << std::endl;
		os << transformation.x.z << ' ' << transformation.y.z << ' ' << transformation.z.z << ' ' << transformation.w.z << std::endl;
		os << transformation.x.w << ' ' << transformation.y.w << ' ' << transformation.z.w << ' ' << transformation.w.w << std::endl;

		return os;
	}
};