//
// Created by Connor Ragland on 4/8/24.
//

#ifndef PROJECT3_CRASHGUARD_HASHMAP_H
#define PROJECT3_CRASHGUARD_HASHMAP_H

#include <iostream>
#include <vector>
#include "DataNode.h"

using namespace std;


template <typename T>
class HashMap {
private:
    const float MAX_LOAD_FACTOR = 0.75;
    const int INITIAL_CAPACITY = 256;

    float _loadFactor;  // (currentCapacity / maxCapacity)
    int _maxCapacity;
    int _currentCapacity;

    vector<vector<pair<T, DataNode>>> hashMap;  // Stores <key, DataNode>

    int hash(T key);  // Returns hash key
    void updateLoadFactor();  // Re-hashes the hash map

public:
    HashMap();

    void insert(T key, DataNode dataObject);
    void find(T key);  // May change to accommodate specific uses

    vector<pair<T, DataNode>> getTopK(int k);  // Gets top k values
    vector<pair<T, DataNode>> getBottomK(int k);  // Gets k lowest values
};


#endif //PROJECT3_CRASHGUARD_HASHMAP_H
