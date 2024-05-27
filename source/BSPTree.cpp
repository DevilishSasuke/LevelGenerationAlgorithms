#include "BSPTree.h"

std::vector<bool>& BSPTree::Algorithm() {
	CreateLeafs();
	resultGraph = GetFloor();

	return resultGraph;
}

void BSPTree::CreateLeafs() {
	int vectorSize = 0, vectorCapacity = 150;
	const int MAX_LEAF_SIZE = 5;
	Leaf root = Leaf(0, 0, roomSize, roomSize, rng);

	bool splited = true;
	leafs.reserve(vectorCapacity);
	leafs.push_back(&root);
	vectorSize++;

	while (splited && vectorSize + 2 < vectorCapacity) {
		splited = false;
		for (Leaf* leaf : leafs) {
			if (leaf->leftChild == NULL && leaf->rightChild== NULL)
				if (leaf->width> MAX_LEAF_SIZE || leaf->height > MAX_LEAF_SIZE ||
					(static_cast<double>(rng()) / rng.max() > 0.25))
					if (leaf->Split()) {
						leafs.push_back(leaf->leftChild);
						leafs.push_back(leaf->rightChild);
						vectorSize += 2;
						splited = true;
					}
		}
	}

	root.CreateRooms(roomSize);
}

std::vector<bool> BSPTree::GetFloor() {
	std::vector<bool> vec(roomSize * roomSize);

	Rectangle room;
	for (Leaf* leaf : leafs) {
		if (leaf->room.Exists()) {
			room = leaf->room;
			for (int i = room.x1; i <= room.x2; ++i)
				for (int j = room.y1; j <= room.y2; ++j)
					vec[j * roomSize + i] = true;
		}
		if (leaf->halls.size() > 0) {
			for (Rectangle* hall : leaf->halls)
				for (int i = hall->x1; i <= hall->x2; ++i)
					for (int j = hall->y1; j <= hall->y2; ++j)
						vec[j * roomSize + i] = true;
		}
	}

	return vec;
}

/* void BSPTree::ShowPositions(std::vector<std::vector<bool>>&vec) {
	for (std::vector<bool> part : vec) {
		for (bool flag : part) std::cout << (flag ? "=" : "0") << " ";
		std::cout << std::endl;
	}
} */