#include "Prim.h"

std::vector<bool>& Prim::Algorithm() {
	if (graph.empty())
		graph = GetRandomGraph(roomSize, rng);

	std::vector<bool> selected(roomSizeSqr);
	int x, y, edgeNum = 0;
	selected[0] = true;

	while (edgeNum < roomSizeSqr - 1) {
		int min = INT_MAX;
		x = 0;
		y = 0;

		for (int i = 0; i < roomSizeSqr; ++i) {
			if (selected[i]) {
				for (int j = 0; j < roomSizeSqr; ++j) {
					if (!selected[j] && graph[i][j]) {
						if (min > graph[i][j]) {
							min = graph[i][j];
							x = i;
							y = j;
		}	}	}	}	}

		DeleteWall(x, y);
		selected[y] = true;
		edgeNum++;
	}

	return resultGraph;
}
