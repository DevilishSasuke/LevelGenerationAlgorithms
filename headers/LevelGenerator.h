#pragma once

#include "vector"
#include <random>
#include <utility>

class LevelGenerator {
protected:
	unsigned int seed;
	unsigned int roomSize;
	unsigned int roomSizeSqr;
	std::vector<std::vector<int>> graph;
	std::vector<std::pair<int, int>> resultGraph;
	std::mt19937 rng;

public:
	LevelGenerator() {};
	LevelGenerator(unsigned int roomSize, unsigned int seed) : seed(seed), roomSize(roomSize), roomSizeSqr(roomSize* roomSize), rng(seed) {}
	virtual ~LevelGenerator() {};

	virtual std::vector<std::pair<int, int>>& Algorithm() = 0;
	virtual void GetRandomGraph() {
		int dif = 0;
		graph.resize(roomSizeSqr);

		for (int i = 0; i < roomSizeSqr; ++i)
			graph[i].resize(roomSizeSqr);

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
};