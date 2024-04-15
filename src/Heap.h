//
// Created by Connor Ragland on 4/14/24.
//

#ifndef PROJECT3_CRASHGUARD_HEAP_H
#define PROJECT3_CRASHGUARD_HEAP_H
#include <vector>
#include "DataNode.h"
using namespace std;



class Heap {
    private:
        vector<DataNode> heap;
        int _size;
        void heapifyUp();
        void heapifyDown();
    public:
        Heap();
        bool empty();
        int size();
        DataNode top();
            // i.e, print data.numCrashes;
            // data.whateverElse
        void pop();
};


#endif //PROJECT3_CRASHGUARD_HEAP_H
