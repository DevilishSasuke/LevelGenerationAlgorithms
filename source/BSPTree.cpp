#include "BSPTree.h"

std::vector<bool>& BSPTree::Algorithm() {
	CreateLeafs();

	return resultGraph;
}

std::vector<Leaf*>& BSPTree::CreateLeafs() {
	int vectorSize = 0, vectorCapacity = 150;
	const int MAX_LEAF_SIZE = 5;

	std::vector<Leaf*> leafs;
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
	auto halls = GetHalls(leafs);
	ShowPositions(halls);
	std::cout << std::endl;
	auto walls = GetWalls(leafs);
	ShowPositions(walls);
	return leafs;
}

std::vector<std::vector<bool>> BSPTree::GetWalls(std::vector<Leaf*>& leafs) {
	std::vector<std::vector<bool>> vec(roomSize, std::vector<bool>(roomSize));

	std::vector<std::vector<bool>> hallsVec = GetHalls(leafs);

	Rectangle room;
	for (Leaf* leaf : leafs) {
		if (leaf->room.Exists()) {
			room = leaf->room;
			for (int i = room.x1; i <= room.x2; i++) {
				vec[room.y1][i] = true;
				vec[room.y2][i] = true;
			}
			for (int i = room.y1; i <= room.y2; i++) {
				vec[i][room.x1] = true;
				vec[i][room.x2] = true;
			}
		}
	}

	for (int i = 0; i < roomSize; ++i)
		for (int j = 0; j < roomSize; ++j)
			if (vec[i][j] && hallsVec[i][j]) vec[i][j] = false;

	return vec;
}



std::vector<std::vector<bool>> BSPTree::GetFloor(std::vector<Leaf*>& leafs) {
	std::vector<std::vector<bool>> vec(roomSize, std::vector<bool>(roomSize));

	Rectangle room;
	for (Leaf* leaf : leafs) {
		if (leaf->room.Exists()) {
			room = leaf->room;
			for (int i = room.x1; i <= room.x2; ++i)
				for (int j = room.y1; j <= room.y2; ++j)
					vec[j][i] = true;
		}
	}

	return vec;
}

std::vector<std::vector<bool>> BSPTree::GetHalls(std::vector<Leaf*>& leafs) {
	std::vector<std::vector<bool>> vec(roomSize, std::vector<bool>(roomSize));

	Rectangle room;
	for (Leaf* leaf : leafs) {
		if (leaf->halls.size() > 0) {
			for (Rectangle* hall : leaf->halls)
				for (int i = hall->x1; i <= hall->x2; ++i)
					for (int j = hall->y1; j <= hall->y2; ++j)
						vec[j][i] = true;
		}
	}

	return vec;
}

void BSPTree::ShowPositions(std::vector<std::vector<bool>>& vec) {
	for (std::vector<bool> part : vec) {
		for (bool flag : part) std::cout << (flag ? "=" : "0") << " ";
		std::cout << std::endl;
	}
}