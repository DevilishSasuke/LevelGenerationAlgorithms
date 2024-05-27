#pragma once

#include "Utilities.h"

class LevelGenerator {
protected:
	int seed;
	int roomSize;
	int roomSizeSqr;
	std::vector<std::vector<int>> graph;
	std::vector<bool> resultGraph;
	std::mt19937 rng;

public:
	LevelGenerator() : seed(0), roomSize(0), roomSizeSqr(0), rng(seed) {}
	LevelGenerator(int roomSize, int seed) : LevelGenerator(roomSize, seed, true) {};
	LevelGenerator(int roomSize, int seed, bool initValue) : 
		seed(seed), rng(seed),
		roomSize(roomSize), roomSizeSqr(roomSize* roomSize) {
		resultGraph.resize(roomSizeSqr * roomSizeSqr);

		if (initValue) {
			for (int i = 0; i < roomSizeSqr; ++i) {
				int index = i * roomSizeSqr;
				int otherRoom = i - 1;
				if (IsValid(otherRoom) && i % roomSize != 0)
					resultGraph[index + otherRoom] = true;
				otherRoom = i + 1;
				if (IsValid(otherRoom) && (i + 1) % roomSize != 0)
					resultGraph[index + otherRoom] = true;
				otherRoom = i - roomSize;
				if (IsValid(otherRoom))
					resultGraph[index + otherRoom] = true;
				otherRoom = i + roomSize;
				if (IsValid(otherRoom))
					resultGraph[index + otherRoom] = true;
			}
		}
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

	bool IsValid(int x) { return x >= 0 && x < roomSizeSqr; }
};