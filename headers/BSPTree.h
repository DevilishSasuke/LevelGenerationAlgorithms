#pragma once

#include "LevelGenerator.h"
#include "Leaf.h"

class BSPTree : public LevelGenerator {
public:
	BSPTree() : LevelGenerator() {};
	BSPTree(unsigned int roomSize, unsigned int seed) : LevelGenerator(roomSize, seed) {};
	virtual std::vector<bool>& Algorithm() override;
	std::vector<Leaf>& CreateLeafs();
};