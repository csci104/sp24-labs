#ifndef STONES_H
#define STONES_H

#include <string>
#include <vector>

/*
	Takes a vector of the weights of stones.
	Returns the weight of the last stone after smashes have happened,
	or 0 if no stones remain.
*/
int lastStoneWeight(std::vector<int>& stones);

#endif