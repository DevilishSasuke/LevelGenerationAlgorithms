#pragma once
#include "LevelGenerator.h"

class Prim : public LevelGenerator {
public:
	Prim();
	Prim(unsigned int roomSize, unsigned int seed) : LevelGenerator(roomSize, seed) {};
	virtual std::vector<std::pair<int, int>>& Algorithm() override;
};