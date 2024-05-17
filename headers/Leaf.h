#pragma once

constexpr int TILESIZE = 3;

#include <vector>
#include <random>
#include <iostream>
#include "Rectangle.h"


class Leaf {
private:
	const int MIN_LEAF_SIZE = 6;
	std::mt19937 rng;
	std::uniform_int_distribution<> dis;

public:
	int x, y;
	int width, height;
	Leaf* leftChild;
	Leaf* rightChild;
	Rectangle room;
	std::vector<int> halls;

	Leaf() : x(0), y(0), width(0), height(0) {};
	Leaf(int x, int y, int width, int height, std::mt19937 generator) : x(x), y(y), width(width), height(height), rng(generator) {};

	bool Split();
	void CreateRooms();
};