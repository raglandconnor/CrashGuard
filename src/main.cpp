#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include "DataNode.h"

using namespace std;


int main() {
    cout << "Working directory: " << filesystem::current_path() << endl;
    string pathname = "resources/US_Accidents_March23.csv";
    ifstream file{pathname};

    if (!file.is_open()) {
        cout << "File not open" << endl;
        return 1;
    }

    /*
     * ID [1], severity [3], startTime [4], endTime [5], distance [10], streetName [12], city [13], county [14],
     * state [15], zipcode [16], timezone [18], weatherCondition [29], relativeTime [43]
     */

    string line;
    getline(file, line);  // Skip first line
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
            else if (indexCount == 4) {dataObject.startTime = dataPoint;}
            else if (indexCount == 5) {dataObject.endTime = dataPoint;}
            else if (indexCount == 10) {dataObject.distance = stof(dataPoint);}
            else if (indexCount == 12) {dataObject.streetName = dataPoint;}
            else if (indexCount == 13) {dataObject.city = dataPoint;}
            else if (indexCount == 14) {dataObject.county = dataPoint;}
            else if (indexCount == 15) {dataObject.state = dataPoint;}
            else if (indexCount == 16) {dataObject.zipcode = dataPoint;}
            else if (indexCount == 18) {dataObject.timezone = dataPoint;}
            else if (indexCount == 29) {dataObject.weatherCondition = dataPoint;}
            else if (indexCount == 43) {dataObject.dayNight = dataPoint;}

            indexCount++;
        }

        // TODO: Insert dataObject into red-black tree and hashmap
    }
    return 0;
}