
#include <iostream>
#include "polyline.cpp"

int main(void) {
	Point2D p1, p2(1, 2), p3(2, 4);
	Polyline pol(3);
	pol.addPoint(p1);
	pol.addPoint(p2);
	pol.addPoint(p3);

	printf("\nLen of Polyline = %g\n", pol.getLen());
	pol.print();

	Point2D newP = pol.getPoint(4);
	newP.print();

	newP = pol.getPoint(2);
	newP.print();
}