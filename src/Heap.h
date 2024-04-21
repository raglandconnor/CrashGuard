//
// Created by Connor Ragland on 4/14/24.
//

#ifndef PROJECT3_CRASHGUARD_HEAP_H
#define PROJECT3_CRASHGUARD_HEAP_H
#include <vector>
#include <iostream>
#include "DataNode.h"
#include "AttributeData.h"
#include <functional>
using namespace std;


template<typename Compare = less<int>>
class Heap {
    private:
        vector<AttributeData> heap;
        Compare comparator;
        void heapifyUp(int index);
        void heapifyDown(int index);
    public:
        Heap();
        bool empty();
        int size();
        AttributeData top();
            // i.e, print data.numCrashes;
            // data.whateverElse
        void push(AttributeData data);
        void pop();
        void topK(int k);
};


#endif //PROJECT3_CRASHGUARD_HEAP_H