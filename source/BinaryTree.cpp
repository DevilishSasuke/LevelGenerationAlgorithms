#include "BinaryTree.h"

std::vector<bool>& BinaryTree::Algorithm() {
    int bias = 0;
    for (int y = 0; y < roomSize; ++y) {
        bias = y * roomSize;
        for (int x = 0; x < roomSize; ++x) {
            if (y > 0)
                if (rng() % 2 == 0)
                    if (x != roomSize - 1) DeleteWall(bias + x, bias + x + 1);
                    else DeleteWall(bias - roomSize + x, bias + x);
                else DeleteWall(bias - roomSize + x, bias + x);
            else
                if (x != roomSize - 1) DeleteWall(bias + x, bias + x + 1);
        }
    }

    return resultGraph;
}
