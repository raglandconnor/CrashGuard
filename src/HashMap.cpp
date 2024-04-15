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
    if (_loadFactor > MAX_LOAD_FACTOR) {
        int tempCapacity = _maxCapacity;  // Store old capacity
        _maxCapacity *= 2;

        vector<vector<pair<T, AttributeData>>> newHashMap;
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
        // Reference: https://stackoverflow.com/questions/3413470/what-is-stdmove-and-when-should-it-be-used
    }
}


// Initializer
template<typename T>
HashMap<T>::HashMap() {
    hashMap.resize(INITIAL_CAPACITY);
    _maxCapacity = INITIAL_CAPACITY;
    _currentCapacity = 0;
    _loadFactor = 0;
}


template<typename T>
void HashMap<T>::insert(T key, const DataNode& dataObject) {
    int hashKey = hash(key);

    // If the key is already present in the hash map
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
    AttributeData attributeObject{};
    attributeObject.numCrashes = 1;
    attributeObject.totalSeverity = dataObject.severity;
    attributeObject.averageSeverity = (float)dataObject.severity;
    pair<T, AttributeData> pair = make_pair(key, attributeObject);

    hashMap[hashKey].push_back(pair);

    // Update the load factor only if a new object is being added
    _currentCapacity++;
    updateLoadFactor();
}


template<typename T>
void HashMap<T>::find(T key) {
    int hashKey = hash(key);

    // Iterate through all until found, then print
    for (int i = 0; i < hashMap[hashKey].size(); i++) {
        if (hashMap[hashKey][i].first == key) {
            AttributeData attribute = hashMap[hashKey][i].second;
            cout << key << ':' << endl;
            cout << attribute.numCrashes << " total crashes" << endl;
            cout << attribute.averageSeverity << "average severity" << endl;
            cout << endl;
        }
    }
}


template<typename T>
vector<pair<T, AttributeData>> HashMap<T>::getTopK(int k) {
    vector<pair<T, AttributeData>> dataVector;
    for (auto bucket : hashMap) {
        dataVector.insert(dataVector.end(), bucket.begin(), bucket.end());
    }

    // Sort using std::sort and a lambda function for comparing.
    // Reference: https://stackoverflow.com/questions/5122804/how-to-sort-with-a-lambda
    sort(dataVector.begin(), dataVector.end(), [](const pair<T, AttributeData> &a, const pair<T, AttributeData> &b) {
        return a.second.numCrashes > b.second.numCrashes;
    });

    dataVector.resize(k);  // Only keep top k elements.

    return dataVector;
}


template<typename T>
vector<pair<T, AttributeData>> HashMap<T>::getBottomK(int k) {
    vector<pair<T, AttributeData>> dataVector;
    for (auto bucket : hashMap) {
        dataVector.insert(dataVector.end(), bucket.begin(), bucket.end());
    }

    // Sort using std::sort and a lambda function for comparing.
    // Reference: https://stackoverflow.com/questions/5122804/how-to-sort-with-a-lambda
    sort(dataVector.begin(), dataVector.end(), [](const pair<T, AttributeData> &a, const pair<T, AttributeData> &b) {
        return a.second.numCrashes < b.second.numCrashes;
    });

    dataVector.resize(k);  // Only keep top k elements.

    return dataVector;
}