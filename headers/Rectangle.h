#pragma once

#include <cmath>

struct Rectangle {
public:
	int x1, y1, x2, y2;
	int width, height;

	Rectangle() : x1(0), y1(0), x2(0), y2(0), width(0), height(0) {};
	Rectangle(int x1, int y1, int width, int height) : x1(x1), y1(y1), width(width), height(height) {
		x2 = x1 + width - 1;
		y2 = y1 + height - 1;
	}

	bool Exists() { return width > 0 && height > 0; }
};