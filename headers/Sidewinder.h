#pragma once

#include "LevelGenerator.h"

class Sidewinder : public LevelGenerator {
public:
	Sidewinder() : LevelGenerator() {};
	Sidewinder(unsigned int roomSize, unsigned int seed) : LevelGenerator(roomSize, seed) {};
	virtual std::vector<bool>& Algorithm() override;
};