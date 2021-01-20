
#include <iostream>
#include <math.h>
#include <string>

class Point2D {
private:
	float x, y;
public:
	// Constructor for incerting x and y.
	Point2D(float x, float y) {
		this->x = x;
		this->y = y;
	}
	// Copy constructor.
	Point2D(const Point2D& p) {
		this->x = p.x;
		this->y = p.y;
	}
	// Empty constructor.
	Point2D() {
		this->x = 0.0f;
		this->y = 0.0f;
	}

	float distance(Point2D p) {
		// distance = sqrt((x_2-x_1)²+(y_2-y_1)²)
		return sqrt((p.getx() - this->x) * (p.getx() - this->x) + (p.gety() - this->y) * (p.gety() - this->y));
	}

	float getx() { return this->x; }
	float gety() { return this->y; }

	std::string toString() {
		std::string s = "[";
		s += std::to_string(this->x);
		s += ",";
		s += std::to_string(this->y);
		s += "]";
		return s;
	}

	Point2D operator+(const Point2D& p) {
		float xi, yi;
		xi = this->x + p.x;
		yi = this->y + p.y;
		return Point2D(xi, yi);
	}

	Point2D operator-(const Point2D& p) {
		float xi, yi;
		xi = this->x - p.x;
		yi = this->y - p.y;
		return Point2D(xi, yi);
	}

	void operator=(const Point2D& p) {
		this->x = p.x;
		this->y = p.y;
	}

	bool operator==(const Point2D& p) {
		return (this->x == p.x && this->y == p.y);
	}
	bool operator!=(const Point2D& p) {
		return !(this->x == p.x && this->y == p.y);
	}

	void print() {
		printf("x / y : %g / %g\n", this->x, this->y);
	}
};
