#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include "DataNode.h"
#include "HashMap.h"
#include "Heap.h"
#include <chrono>

using namespace std;


bool parseCSV(int attribute, HashMap &hashmap, Heap<less<int>> &heap) {
    /*
     * Attribute: 1 = County, 2 = City, 3 = State
     *
    * ID [1], severity [3], startTime [4], endTime [5], distance [10], streetName [12], city [13], county [14],
    * state [15], zipcode [16], timezone [18], weatherCondition [29], relativeTime [43]
    */

    // Open file:
    cout << "Working directory: " << filesystem::current_path() << endl;
    string pathname = "resources/US_Accidents_March23.csv";
    ifstream file{pathname};

    if (!file.is_open()) {
        cout << "File not open" << endl;
        return false;
    }

    string line;
    getline(file, line);  // Skip first line

    int count = 0;  // Use for percentage count

    while (getline(file, line)) {
        DataNode dataObject;

        stringstream ss(line);
        int indexCount = 1;
        string dataPoint;



        while (getline(ss, dataPoint, ',')) {
            if (indexCount == 1) {
                dataPoint = dataPoint.substr(2, dataPoint.size()-2);
                dataObject.ID = stoi(dataPoint);
            }
            else if (indexCount == 3) {dataObject.severity = stoi(dataPoint);}
//            else if (indexCount == 4) {dataObject.startTime = dataPoint;}
//            else if (indexCount == 5) {dataObject.endTime = dataPoint;}
//            else if (indexCount == 10) {dataObject.distance = stof(dataPoint);}
            else if (indexCount == 12) {dataObject.streetName = dataPoint;}
            else if (indexCount == 13) {dataObject.city = dataPoint;}
            else if (indexCount == 14) {dataObject.county = dataPoint;}
            else if (indexCount == 15) {dataObject.state = dataPoint;}
            else if (indexCount == 16) {dataObject.zipcode = dataPoint;}
//            else if (indexCount == 18) {dataObject.timezone = dataPoint;}
//            else if (indexCount == 29) {dataObject.weatherCondition = dataPoint;}
//            else if (indexCount == 43) {dataObject.dayNight = dataPoint;}

            indexCount++;

            cout << count << endl;
        }

        // Insert into hashmap:
        if (attribute == 1) {  // County
            hashmap.insert(dataObject.county, dataObject);
        }
        else if (attribute == 2) {  // City
            hashmap.insert(dataObject.city, dataObject);
        }
        else if (attribute == 3) {  // State
            hashmap.insert(dataObject.state, dataObject);
        }
        else {
            cout << "Invalid attribute" << endl;
            cout << "Insertion into hashmap/heap unsuccessful." << endl;

            return false;
        }

        count++;
    }

    // Insert all items from the hashmap into the heap
    hashmap.transferToHeap(heap);  // Not working currently. Something wrong with heap template instantiation. Help

    return true;  // Items successfully added to data structures
}


int main() {
    // GUI:
    bool attribute = true;
    while (attribute) {
        HashMap hashmap;
        Heap<less<int>> heap;

        bool running = false;

        cout << "Choose an attribute: " << endl;
        cout << "1. County" << endl;
        cout << "2. City" << endl;
        cout << "3. State" << endl;
        string inputAttribute;
        cin >> inputAttribute;

        string attributeOption;

        if (inputAttribute == "1") {  // County
            if (parseCSV(1, hashmap, heap)) {  // Successful
                cout << "Heap and hash map have been initialized\n\n";
                running = true;
                attributeOption = "county";
            }
        }
        else if (inputAttribute == "2") {  // City
            if (parseCSV(2, hashmap, heap)) {  // Successful
                cout << "Heap and hash map have been initialized\n\n";
                running = true;
                attributeOption = "city";
            }
        }
        else if (inputAttribute == "3") {  // State
            if (parseCSV(3, hashmap, heap)) {  // Successful
                cout << "Heap and hash map have been initialized\n\n";
                running = true;
                attributeOption = "state";
            }
        }
        else {
            cout << "Incorrect input" << endl;
            running = false;
        }

        while (running) {
            cout << "Menu: " << endl;
            cout << "1. Top 5" << endl;
            cout << "2. Top k" << endl;
            cout << "3. Find" << endl;
            cout << "4. Change attribute" << endl;
            cout << "5. Exit" << endl;

            string inputOption;
            cin >> inputOption;
            if (inputOption == "1") {
                cout << "Top 5 most crashes:" << endl;

                // Hashmap
                auto startHashmap = chrono::high_resolution_clock::now();
                vector<pair<string, AttributeData>> list = hashmap.getTopK(5);
                cout << "Hashmap:\n";
                for (const auto& pair : list) {
                    cout << pair.first << ": " << pair.second.numCrashes << " total crashes" << endl;
                }
                cout << endl;
                auto stopHashmap = chrono::high_resolution_clock::now();
                auto durationHashmap = chrono::duration_cast<chrono::nanoseconds>(stopHashmap - startHashmap);

                // Heap
                auto startHeap = chrono::high_resolution_clock::now();
                cout << "Heap:\n";
                heap.topK(5);
                cout << endl;
                auto stopHeap = chrono::high_resolution_clock::now();
                auto durationHeap = chrono::duration_cast<chrono::nanoseconds>(stopHeap - startHeap);

                cout << "Time for HashMap: " << durationHashmap.count() << " nanoseconds" << endl;
                cout << "Time for Heap: " << durationHeap.count() << " nanoseconds" << endl;

                cout << "\n";
            }
            else if (inputOption == "2") {
                cout << "Enter a number: ";
                int k;
                cin >> k;
                cout << "\nTop " << k << " most crashes:"<< endl;

                if (k > 0) {
                    // Hashmap
                    auto startHashmap = chrono::high_resolution_clock::now();
                    vector<pair<string, AttributeData>> list = hashmap.getTopK(k);
                    cout << "Hashmap:\n";
                    for (const auto& pair : list) {
                        cout << pair.first << ": " << pair.second.numCrashes << " total crashes" << endl;
                    }
                    cout << endl;
                    auto stopHashmap = chrono::high_resolution_clock::now();
                    auto durationHashmap = chrono::duration_cast<chrono::nanoseconds>(stopHashmap - startHashmap);

                    // Heap
                    auto startHeap = chrono::high_resolution_clock::now();
                    cout << "Heap:\n";
                    heap.topK(k);
                    cout << endl;
                    auto stopHeap = chrono::high_resolution_clock::now();
                    auto durationHeap = chrono::duration_cast<chrono::nanoseconds>(stopHeap - startHeap);

                    cout << "Time for HashMap: " << durationHashmap.count() << " nanoseconds" << endl;
                    cout << "Time for Heap: " << durationHeap.count() << " nanoseconds" << endl;

                    cout << "\n";
                }

            }
            else if (inputOption == "3") {
                if (inputAttribute == "3") {
                    cout << "Use a two letter abbreviation" << endl;
                }
                cout << "Enter a " << attributeOption << ": ";
                string attributeInput;
                cin >> attributeInput;

                hashmap.find(attributeInput);
            }
            else if (inputOption == "4") {
                running = false;
                cout << "\n";
            }
            else if (inputOption == "5") {
                running = false;
                attribute = false;
            }
            else {
                cout << "Incorrect input" << endl;
            }
        }
    }

    return 0;
}