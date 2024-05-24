#pragma once

#include "LevelGenerator.h"

class Prim : public LevelGenerator {
public:
	Prim() : LevelGenerator() {};
	Prim(unsigned int roomSize, unsigned int seed) : LevelGenerator(roomSize, seed) {};
	virtual std::vector<bool>& Algorithm() override;
};