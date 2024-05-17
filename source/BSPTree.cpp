#include "BSPTree.h"

std::vector<bool>& BSPTree::Algorithm() {

	return resultGraph;
}

std::vector<Leaf>& BSPTree::CreateLeafs() {
	const int MAX_LEAF_SIZE = 20;

	std::vector<Leaf> leafs;
	Leaf root = Leaf(0, 0, roomSize, roomSize, rng);

	bool splited = true;
	leafs.push_back(root);

	while (splited) {
		splited = false;
		for (Leaf leaf : leafs)
			if (leaf.leftChild == NULL && leaf.rightChild == NULL)
				if (leaf.width > MAX_LEAF_SIZE || leaf.height > MAX_LEAF_SIZE ||
					(static_cast<double>(rng()) / rng.max() > 0.25))
					if (leaf.Split()) {
						leafs.push_back(*leaf.leftChild);
						leafs.push_back(*leaf.rightChild);
						splited = true;
					}
	}

	root.CreateRooms();
	return leafs;
}