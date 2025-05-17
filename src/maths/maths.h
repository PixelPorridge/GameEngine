#pragma once

#include <cmath>
#include <limits>

constexpr float PI = 3.14159265358979323846f;
constexpr float TAU = 6.28318530717958647692f;
constexpr float EPSILON = std::numeric_limits<float>::epsilon();
constexpr float INF = std::numeric_limits<float>::infinity();

inline float degrees_to_radians(float degrees) {
	return degrees * PI / 180;
}

inline float radians_to_degrees(float radians) {
	return radians * 180 / PI;
}

inline bool is_almost_zero(float value) {
	if (std::abs(value) < EPSILON) {
		return true;
	}

	return false;
}

inline float zero_if_almost(float value) {
	if (std::abs(value) < EPSILON) {
		return 0;
	}

	return value;
}