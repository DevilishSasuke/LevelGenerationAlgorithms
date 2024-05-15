#pragma once
#include "LevelGenerator.h"

class AldousBroder : public LevelGenerator {
public:
	AldousBroder() : LevelGenerator() {};
	AldousBroder(unsigned int roomSize, unsigned int seed) : LevelGenerator(roomSize, seed) {};
	virtual std::vector<bool>& Algorithm() override;
};