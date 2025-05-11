#pragma once

#include <cmath>
#include <limits>

namespace Maths {
	// Definitions

	constexpr float PI = 3.14159265358979323846f;
	constexpr float TAU = 6.28318530717958647692f;
	constexpr float EPSILON = std::numeric_limits<float>::epsilon();
	constexpr float INF = std::numeric_limits<float>::infinity();

	// Trigonometric

	inline float sin(float value) {
		return std::sin(value);
	}

	inline float cos(float value) {
		return std::cos(value);
	}

	inline float tan(float value) {
		return std::tan(value);
	}

	inline float degrees_to_radians(float degrees) {
		return degrees * Maths::PI / 180;
	}

	inline float radians_to_degrees(float radians) {
		return radians * 180 / Maths::PI;
	}

	// Exponential & Logarithmic

	inline float exp(float value) {
		return std::exp(value);
	}

	inline float log(float value) {
		return std::log(value);
	}

	// Power

	inline float pow(float base, float exponent) {
		return std::pow(base, exponent);
	}

	inline float sqrt(float value) {
		return std::sqrt(value);
	}

	// Rounding

	inline float ceil(float value) {
		return std::ceil(value);
	}

	inline float floor(float value) {
		return std::floor(value);
	}

	inline float round(float value) {
		return std::round(value);
	}

	// Approximations

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

	// Other

	inline float abs(float value) {
		return std::abs(value);
	}
}