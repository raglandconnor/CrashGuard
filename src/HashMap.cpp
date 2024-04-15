//
// Created by Connor Ragland on 4/8/24.
//

#include "HashMap.h"


template<typename T>
int HashMap<T>::hash(T key) {

}


template<typename T>
void HashMap<T>::updateLoadFactor() {
    _loadFactor = (float)_currentCapacity / (float)_maxCapacity;

    // Re-hash
    if (_loadFactor > _maxCapacity) {
        int tempCapacity = _maxCapacity;  // Store old capacity
        _maxCapacity *= 2;

        vector<vector<pair<T, DataNode>>> newHashMap;
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

}


template<typename T>
void HashMap<T>::find(T key) {

}


template<typename T>
vector<pair<T, DataNode>> HashMap<T>::getTopK(int k) {

}


template<typename T>
vector<pair<T, DataNode>> HashMap<T>::getBottomK(int k) {

}