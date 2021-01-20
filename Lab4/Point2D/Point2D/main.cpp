
#include <iostream>
#include "point2D.cpp"

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