#include "Leaf.h"
#include <iostream>

bool Leaf::Split() {
	if (leftChild != NULL && rightChild != NULL) return false;

	bool splitH = static_cast<double>(rng()) / rng.max() > 0.5;
	if (width > height && static_cast<double>(width) / height >= 1.25)
		splitH = false;
	else if (height > width && static_cast<double>(height) / width >= 1.25)
		splitH = true;

	int maxH = splitH ? height : width;

	if (maxH <= MIN_LEAF_SIZE) return false;

	dis.param(std::uniform_int_distribution<int>::param_type(MIN_LEAF_SIZE, maxH));
	int split = dis(rng);

	if (splitH) {
		leftChild = new Leaf(x, y, width, split, rng);
		maxH = rng() % 100 + 100;
		for (int i = 0; i < maxH; ++i) rng();
		rightChild = new Leaf(x, y + split, width, height - split, rng);
	}
	else {
		leftChild = new Leaf(x, y, split, height, rng);
		maxH = rng() % 100 + 100;
		for (int i = 0; i < maxH; ++i) rng();
		rightChild = new Leaf(x + split, y, width - split, height, rng);
	}

	return true;
};

void Leaf::CreateRooms() {
	if (leftChild != NULL || rightChild != NULL) {
		if (leftChild != NULL) leftChild->CreateRooms();
		if (rightChild != NULL) rightChild->CreateRooms();
	}
	else {
		int roomWidth, roomHeight, roomPosX, roomPosY;
		
		dis.param(std::uniform_int_distribution<int>::param_type(TILESIZE, width - 2));
		roomWidth = dis(rng);
		dis.param(std::uniform_int_distribution<int>::param_type(TILESIZE, height - 2));
		roomHeight = dis(rng);
		dis.param(std::uniform_int_distribution<int>::param_type(1, width - roomWidth - 1));
		roomPosX = x + dis(rng);
		dis.param(std::uniform_int_distribution<int>::param_type(1, height - roomHeight - 1));
		roomPosY = y + dis(rng);

		room = Rectangle(roomPosX, roomPosY, roomWidth, roomHeight);
	}
}