//
// Created by Connor Ragland on 4/8/24.
//

#ifndef PROJECT3_CRASHGUARD_HASHMAP_H
#define PROJECT3_CRASHGUARD_HASHMAP_H

#include <iostream>
#include <vector>
#include "DataNode.h"
#include "AttributeData.h"

using namespace std;


class HashMap {
private:
    const float MAX_LOAD_FACTOR = 0.75;
    const int INITIAL_CAPACITY = 256;

    float _loadFactor;  // (currentCapacity / maxCapacity)
    int _maxCapacity;
    int _currentCapacity;

    vector<vector<pair<string, AttributeData>>> hashMap;  // Stores <key, AttributeData>

    int hash(const string& key);  // Returns reduced hash key
    void updateLoadFactor();  // Re-hashes the hash map

public:
    HashMap();

    void insert(string key, const DataNode& dataObject);
    void find(string key);  // May change to accommodate specific uses

    vector<pair<string, AttributeData>> getTopK(int k);  // Gets top k values
    vector<pair<string, AttributeData>> getBottomK(int k);  // Gets k lowest values
};


#endif //PROJECT3_CRASHGUARD_HASHMAP_H
