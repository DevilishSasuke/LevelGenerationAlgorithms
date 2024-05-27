#include "Sidewinder.h"

std::vector<bool>& Sidewinder::Algorithm() {
    int bias = 0, wallToDelete = 0, cx = 0;

    for (int y = 0; y < roomSize; ++y) {
        bias = y * roomSize;
        for (int x = 0; x < roomSize; ++x) {
            if (y > 0)
                if (rng() % 2 == 0 && x != roomSize - 1)
                    DeleteWall(bias + x, bias + x + 1);
                else {
                    wallToDelete = Randomize(rng, cx, x);
                    DeleteWall(bias - roomSize + wallToDelete, bias + wallToDelete);

                    if (x != roomSize - 1)
                        cx = x + 1;
                    else cx = 0;
                }
            else
                if (x != roomSize - 1) DeleteWall(bias + x, bias + x + 1);
        }
    }

    return resultGraph;
}
