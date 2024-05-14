#pragma once
#include "LevelGenerator.h"

class BinaryTree : public LevelGenerator {
public:
	BinaryTree() : LevelGenerator() {};
	BinaryTree(unsigned int roomSize, unsigned int seed) : LevelGenerator(roomSize, seed) {};
	virtual std::vector<bool>& Algorithm() override;
};