#pragma once

#include "Utilities.h"

class LevelGenerator {
protected:
	unsigned int seed;
	unsigned int roomSize;
	unsigned int roomSizeSqr;
	std::vector<std::vector<int>> graph;
	std::vector<bool> resultGraph;
	std::mt19937 rng;

public:
	LevelGenerator() : seed(0), roomSize(0), roomSizeSqr(0), rng(seed) {}
	LevelGenerator(unsigned int roomSize, unsigned int seed) : LevelGenerator(roomSize, seed, true) {};
	LevelGenerator(unsigned int roomSize, unsigned int seed, bool initValue) : 
		seed(seed), rng(seed),
		roomSize(roomSize), roomSizeSqr(roomSize* roomSize) {
		resultGraph.resize(roomSizeSqr * roomSizeSqr, initValue);
	}
	virtual ~LevelGenerator() {};

	virtual std::vector<bool>& Algorithm() = 0;

	inline void SetWall(int x, int y) {
		resultGraph[x * roomSizeSqr + y] = true;
		resultGraph[y * roomSizeSqr + x] = true;
	}

	inline void DeleteWall(int x, int y) {
		resultGraph[x * roomSizeSqr + y] = false;
		resultGraph[y * roomSizeSqr + x] = false;
	}
};