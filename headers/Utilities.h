#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <random>

int Randomize(std::mt19937& gen, int min, int max);
std::vector<std::vector<int>> GetRandomGraph(int roomSize, std::mt19937& gen);
