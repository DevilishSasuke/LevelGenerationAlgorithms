#pragma once

#include <cmath>

class Rectangle {
public:
	int x1, y1, x2, y2;
	int width, height;

	Rectangle() : x1(0), y1(0), x2(0), y2(0) {};
	Rectangle(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {
		width = abs(x1 - x2);
		height = abs(y1 - y2);
	}
};