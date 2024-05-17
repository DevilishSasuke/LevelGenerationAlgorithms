#pragma once

#include <iostream>
#include "vector"
#include <random>

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
	LevelGenerator(unsigned int roomSize, unsigned int seed, bool initValue) : seed(seed), roomSize(roomSize), roomSizeSqr(roomSize* roomSize), rng(seed) {
		resultGraph.resize(roomSizeSqr * roomSizeSqr, initValue);
	}
	virtual ~LevelGenerator() {};

	virtual std::vector<bool>& Algorithm() = 0;
	virtual void GetRandomGraph() {
		int dif = 0;
		graph.resize(roomSizeSqr, std::vector<int>(roomSizeSqr));

		for (int i = 0; i < roomSizeSqr; ++i) {
			for (int j = 0; j < roomSizeSqr; ++j) {
				if (j > i) break;
				dif = abs(i - j);
				if (dif != 1 &&
					dif != roomSize ||
					(dif == 1 && (i % roomSize == 0)))
					continue;

				if (graph[j][i] != 0)
					graph[i][j] = graph[j][i];
				else {
					graph[i][j] = rng() % 100 + 1;
					graph[j][i] = graph[i][j];
				}
			}
		}
	}

	inline bool IsValid(int x, int y) const {
		return (x >= 0 && x < roomSizeSqr) && (y >= 0 && y < roomSizeSqr);
	}

	inline void SetWall(int x, int y) {
		std::cout << "Setted: " << x << " " << y << std::endl;
		resultGraph[x * roomSizeSqr + y] = true;
		resultGraph[y * roomSizeSqr + x] = true;
	}

	inline void DeleteWall(int x, int y) {
		std::cout << "Deleted: " << x << " " << y << std::endl;
		resultGraph[x * roomSizeSqr + y] = false;
		resultGraph[y * roomSizeSqr + x] = false;
	}
};