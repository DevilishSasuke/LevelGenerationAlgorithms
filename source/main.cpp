#include <iostream>
#include "Prim.h"
#include "BinaryTree.h"
#include "Sidewinder.h"
#include "AldousBroder.h"
#include "BSPTree.h"

int main()
{
	unsigned int roomSize = 11;
	unsigned int seed = 1;
	
	for (int i = 0; i < 100; i++) {
		auto algo = BSPTree(30, i);
		std::vector<bool> list = algo.Algorithm();
		std::cout << std::endl;
	}
} 
