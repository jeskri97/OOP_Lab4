
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
	Point2D(const Point2D &p) {
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
		return sqrt( (p.getx() - this->x)*(p.getx() - this->x) + (p.gety() - this->y)* (p.gety() - this->y) );
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

int main(void) {
	// Part 1
	Point2D p1(5.5, 3), p2(11, 2.4);
	std::string dist = std::to_string(p1.distance(p2)), p1s = p1.toString(), p2s = p2.toString();
	printf("\ndist %s->%s = %s\n", p1s.c_str(), p2s.c_str(), dist.c_str());

	// Part 2
	Point2D p3(p1);
	// // alt
	// Point2D p3 = p1;

	// Part 3
	std::string p3s = p3.toString();
	printf("\nNew Point3: %s", p3s.c_str());
	bool same = p3 == p1;
	printf("\nPoint3 == Point1: %i\n", same);
	same = p3 == p2;
	printf("Point3 == Point2: %i\n", same);

	// Part 4
	Point2D p4 = p1 + p2;

	// Part 5
	std::string p4s = p4.toString();
	printf("\nNew Point4: %s", p4s.c_str());
	dist = std::to_string(p4.distance(p2));
	printf("\ndist %s->%s = %s\n", p4s.c_str(), p2s.c_str(), dist.c_str());

	// Part 6
	same = p4 == p1;
	printf("\nPoint4 == Point1: %i\n", same);
	same = p4 == p2;
	printf("Point4 == Point2: %i\n", same);
	same = p4 == p3;
	printf("Point4 == Point3: %i\n", same);
}