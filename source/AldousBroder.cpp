#include "AldousBroder.h"

std::vector<bool>& AldousBroder::Algorithm() {
	enum Direction { Up = 0, Down = 1, Left = 2, Right = 3 };
	Direction direction;
	int unvisitedRooms = roomSizeSqr;
	int ix = rng() % roomSize;
	int iy = rng() % roomSize;

	std::vector<std::vector<bool>> visited(roomSize, std::vector<bool>(roomSize));
	visited[iy][ix] = true;

	while (unvisitedRooms > 0) {
		direction = static_cast<Direction>(rng() % 4);

    switch (direction) {
    case Up:
      HandleUp(ix, iy);
      unvisitedRooms--;
      break;
    case Dowrn:
      HandleDown(ix, iy);
      unvisitedRooms--;
      break;
    case Left:
      HandleLeft(ix, iy);
      unvisitedRooms--;
      break;
    case Right:
      HandleUp(ix, iy);
      unvisitedRooms--;
      break;
    }
  }

  return resultGraph;
}


