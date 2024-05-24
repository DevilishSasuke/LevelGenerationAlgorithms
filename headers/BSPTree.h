#pragma once

#include "LevelGenerator.h"
#include "Leaf.h"

class BSPTree : public LevelGenerator {
public:
	BSPTree() : LevelGenerator() {};
	BSPTree(unsigned int roomSize, unsigned int seed) : LevelGenerator(roomSize, seed) {};
	virtual std::vector<bool>& Algorithm() override;
	std::vector<Leaf*>& CreateLeafs();

	// Collect walls that need to be placed
	// walls that cross halls deleted
	std::vector<std::vector<bool>> GetWalls(std::vector<Leaf*>& leafs);

	// Collect room floors that need to be placed
	std::vector<std::vector<bool>> GetFloor(std::vector<Leaf*>& leafs);

	// Collect halls positions
	std::vector<std::vector<bool>> GetHalls(std::vector<Leaf*>& leafs);

	// Show scheme of objects that need to be placed
	void ShowPositions(std::vector<std::vector<bool>>& vec);
};