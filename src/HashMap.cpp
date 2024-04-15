//
// Created by Connor Ragland on 4/8/24.
//

#include "HashMap.h"


template<typename T>
int HashMap<T>::hash(T key) {
    std::hash<T> hash;

    return hash(key) % _maxCapacity;  // Reduce and return
}


template<typename T>
void HashMap<T>::updateLoadFactor() {
    _loadFactor = (float)_currentCapacity / (float)_maxCapacity;

    // Re-hash
    if (_loadFactor > _maxCapacity) {
        int tempCapacity = _maxCapacity;  // Store old capacity
        _maxCapacity *= 2;

        vector<vector<pair<T, AttributeObject>>> newHashMap;
        newHashMap.resize(_maxCapacity);

        for (int i = 0; i < tempCapacity; i++) {
            for (auto pair : hashMap[i]) {
                // Push each pair into their respective row
                int idx = hash(pair.first);
                newHashMap[idx].push_back(pair);
            }
        }

        // Update load factor
        _loadFactor = (float)_currentCapacity / (float)_maxCapacity;

        hashMap.clear();
        hashMap.resize(_maxCapacity);
        hashMap = move(newHashMap);  // std::move to avoid copies
    }
}


// Initializer
template<typename T>
HashMap<T>::HashMap() {
    hashMap.resize(INITIAL_CAPACITY);
    _maxCapacity = INITIAL_CAPACITY;
    _currentCapacity = 0;
}


template<typename T>
void HashMap<T>::insert(T key, DataNode dataObject) {
    int hashKey = hash(key);

    for (int i = 0; i < hashMap[hashKey].size(); i++) {
        if (hashMap[hashKey][i].first == key) {
            hashMap[hashKey][i].second.numCrashes++;
            hashMap[hashKey][i].second.totalSeverity += dataObject.severity;
            int numCrashes = hashMap[hashKey][i].second.numCrashes;
            int totalSeverity = hashMap[hashKey][i].second.totalSeverity;
            hashMap[hashKey][i].second.averageSeverity = (float)totalSeverity / (float)numCrashes;

            return;
        }
    }

    // Existing object not found
    AttributeObject attributeObject;
    attributeObject.numCrashes = 1;
    attributeObject.totalSeverity = dataObject.severity;
    attributeObject.averageSeverity = dataObject.severity;
    pair<T, AttributeObject> pair = make_pair(key, attributeObject);

    hashMap[hashKey].push_back(pair);
}


template<typename T>
void HashMap<T>::find(T key) {
    int hashKey = hash(key);

    for (int i = 0; i < hashMap[hashKey].size(); i++) {
        if (hashMap[hashKey][i].first == key) {
            AttributeObject attribute = hashMap[hashKey][i].second;
            cout << key << ':' << endl;
            cout << attribute.numCrashes << " total crashes" << endl;
            cout << attribute.averageSeverity << "average severity" << endl;
            cout << endl;
        }
    }
}


template<typename T>
vector<pair<T, int>> HashMap<T>::getTopK(int k) {

}


template<typename T>
vector<pair<T, int>> HashMap<T>::getBottomK(int k) {

}