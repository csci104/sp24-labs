#include "stones.h"
#include "max_heap.h"

int lastStoneWeight(std::vector<int>& stones) {
    MaxHeap<int> heap;

    //first organize the data into a heap
    for (int i = 0; i < stones.size(); i++) {
        heap.push(stones[i]);
    }

    while (heap.size() != 0) {
        //get the top 2 values for y and x
        int y = heap.top();
        int x;
        heap.pop();

        if (heap.size() != 0) {
            x = heap.top();
        }

        else {
            return y;
        }

        //if x == y pop both stones
        if (y == x) {
            heap.pop();
        }

        //if x != y, x totally destroyed, y = y-x
        else if (y != x) {
            heap.pop();
            heap.push(y - x);
        }
    }

    if (heap.size() == 0) {
        return 0;
    }
    
    return heap.top();
    
    // TO BE COMPLETED
    
}




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