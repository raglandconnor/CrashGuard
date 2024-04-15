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
    struct Attribute {  // Stores values pertaining to a specific attribute
        int numCrashes;
        int totalSeverity;  // For average severity: totalSeverity / numCrashes
        float averageSeverity;
    };

    const float MAX_LOAD_FACTOR = 0.75;
    const int INITIAL_CAPACITY = 256;

    float _loadFactor;  // (currentCapacity / maxCapacity)
    int _maxCapacity;
    int _currentCapacity;

    vector<vector<pair<T, Attribute>>> hashMap;  // Stores <key, DataNode>

    int hash(T key);  // Returns reduced hash key
    void updateLoadFactor();  // Re-hashes the hash map

public:
    HashMap();

    void insert(T key, DataNode dataObject);
    void find(T key);  // May change to accommodate specific uses

    vector<pair<T, int>> getTopK(int k);  // Gets top k values
    vector<pair<T, int>> getBottomK(int k);  // Gets k lowest values
};


#endif //PROJECT3_CRASHGUARD_HASHMAP_H
