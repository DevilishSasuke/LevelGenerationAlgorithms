#include "Utilities.h"

int Randomize(std::mt19937& gen, int min, int max) {
	if (max < min) max = min;
	return min + gen() % (max - min + 1);
}

std::vector<std::vector<int>> GetRandomGraph(int roomSize, std::mt19937& gen) {
	unsigned int roomSizeSqr = roomSize * roomSize;
	std::vector<std::vector<int>> graph(roomSizeSqr, std::vector<int>(roomSizeSqr));
	int dif = 0;

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
				graph[i][j] = gen() % 100 + 1;
				graph[j][i] = graph[i][j];
			}
		}
	}

	return graph;
}
