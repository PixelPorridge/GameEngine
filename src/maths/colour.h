#pragma once

class Colour {
public:
	union {
		struct { float r, g, b, a;  };
		float channels[4];
	};

	Colour() : r(0), g(0), b(0), a(1) {}
	Colour(float r, float g, float b, float a = 1) : r(r), g(g), b(b), a(a) {}

	const float& operator[](int index) const;
	float& operator[](int index);

	Colour operator+() const;
	Colour operator-() const;

	Colour operator+(const Colour& other) const;
	Colour operator+(float scalar) const;
	void operator+=(const Colour& other);
	void operator+=(float scalar);

	Colour operator-(const Colour& other) const;
	Colour operator-(float scalar) const;
	void operator-=(const Colour& other);
	void operator-=(float scalar);

	Colour operator*(const Colour& other) const;
	Colour operator*(float scalar) const;
	void operator*=(const Colour& other);
	void operator*=(float scalar);

	Colour operator/(const Colour& other) const;
	Colour operator/(float scalar) const;
	void operator/=(const Colour& other);
	void operator/=(float scalar);

	bool operator==(const Colour& other) const;
	bool operator!=(const Colour& other) const;

	friend Colour operator+(float scalar, const Colour& colour) {
		return colour + scalar;
	}

	friend Colour operator*(float scalar, const Colour& colour) {
		return colour * scalar;
	}
};