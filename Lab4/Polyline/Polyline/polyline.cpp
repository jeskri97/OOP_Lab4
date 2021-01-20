
#include <iostream>
#include "point2D.cpp"

class Polyline {
private:
	// Array of points.
	Point2D* points;
	int arrLen, pointNum = 0;
public:
	Polyline(int arrLen) {
		// Dynamically allocates space for the points.
		this->points = new Point2D[arrLen];
		this->arrLen = arrLen;
	}
	~Polyline() {
		if (this->points != nullptr) {
			// Deallocates the array.
			delete[] points;
			this->points = nullptr;
		}
	}

	// Add point to array. (Return error if full)
	void addPoint(Point2D point) {
		// Add Point to array.
		if (pointNum < arrLen) {
			points[pointNum] = point;
			pointNum++;
			std::string s = point.toString();
			printf("Added point %s to list\n", s.c_str());
		}
		// Write an error.
		else
			printf("\nERROR: Allready maximum amount of Points in list.\n");
	}

	// Return point by index.
	Point2D getPoint(int index) {
		if (index > arrLen) {
			printf("\nERROR: Index exceeds the lenght of the list.\n");
			return Point2D(0.0f, 0.0f);
		}
		else if (index > pointNum) {
			printf("\nERROR: Index exceeds the amount of Points in the list.\n");
			return Point2D(0.0f, 0.0f);
		}
		else
			return points[index];
	}

	// Delete last point. (Replace with nullptr)
	void deleteLast() {
		// Check if the array contains any values.
		if (pointNum == 0)
			printf("\nERROR: List is already empty.\n");
		else {
			pointNum--;
			delete &points[pointNum];
			//points[pointNum] = nullptr;
		}
	}

	// Check if Polyline contains a point. (Return bool)
	bool containsPoint() {
		if (pointNum < 0)
			return true;
		else
			return false;
	}

	// Get total number of points.
	int numberOfPoints() {
		return pointNum;
	}

	// Get the total lenght of the Polyline.
	float getLen() {
		float len = 0;
		for (int i = 0; i < pointNum - 1; i++) {
			len += points[i].distance(points[i + 1]);
		}
		return len;
	}

	// Print the Polyline coordinates. (Use toString() in Point2D class)
	void print() {
		std::string currentPoint;
		printf("\n-----< Start of Polyline >--------------------\n");
		for (int i = 0; i < pointNum; i++) {
			currentPoint = points[i].toString();
			printf("Point %i: %s\n", i+1, currentPoint.c_str());
		}
		printf("-----< End of Polyline >----------------------\n");
	}
};