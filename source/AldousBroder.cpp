#include "AldousBroder.h"

std::vector<bool>& AldousBroder::Algorithm() {
	enum Direction { Up = 0, Down = 1, Left = 2, Right = 3 };
	Direction direction;
	int unvisitedRooms = roomSizeSqr;
	int ix = rng() % roomSize;
	int iy = rng() % roomSize;

	std::vector<std::vector<bool>> visited(roomSize, std::vector<bool>(roomSize));
	visited[iy][ix] = true;

	while (unvisitedRooms != 1) {
		direction = static_cast<Direction>(rng() % 4);

		if (direction == Up) {
			if (iy - 1 >= 0) {
				--iy;
				if (!visited[iy][ix]) {
					visited[iy][ix] = true;
					DeleteWall(iy * roomSize + ix, (iy + 1) * roomSize + ix);
					unvisitedRooms--;
				}
			}
		}
		if (direction == Down) {
			if (iy + 1 < roomSize) {
				++iy;
				if (!visited[iy][ix]) {
					visited[iy][ix] = true;
					DeleteWall(iy * roomSize + ix, (iy - 1) * roomSize + ix);
					unvisitedRooms--;
				}
			}
		}
		if (direction == Left) {
			if (ix - 1 >= 0) {
				--ix;
				if (!visited[iy][ix]) {
					visited[iy][ix] = true;
					DeleteWall(iy * roomSize + ix, iy * roomSize + ix + 1);
					unvisitedRooms--;
				}
			}
		}
		if (direction == Right) {
			if (ix + 1 < roomSize) {
				++ix;
				if (!visited[iy][ix]) {
					visited[iy][ix] = true;
					DeleteWall(iy * roomSize + ix, iy * roomSize + ix - 1);
					unvisitedRooms--;
				}
			}
		}
	}

	

	if (roomSize > 1) {
		for (int y = 0; y < roomSize; ++y) {
			for (int x = 0; x < roomSize; ++x) {
				if (!visited[y][x]) {
					iy = y;
					ix = x;
					break;
		}	}	}

		if (iy + 1 < roomSize) DeleteWall(iy * roomSize + ix, (iy + 1) * roomSize + ix);
		else DeleteWall(iy * roomSize + ix, (iy - 1) * roomSize + ix);
		if (ix + 1 < roomSize) DeleteWall(iy * roomSize + ix, iy * roomSize + ix + 1);
		else DeleteWall(iy * roomSize + ix, iy * roomSize + ix - 1);
	}

	return resultGraph;
}

