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

    bool attribute = true;
    while (attribute) {
        bool running = true;

        cout << "Choose an attribute: " << endl;
        cout << "1. County" << endl;
        cout << "2. City" << endl;
        cout << "3. State" << endl;
        string input1;
        cin >> input1;

        if (input1 == "1") {
            // county is key
        } else if (input1 == "2") {
            // city is key
        } else if (input1 == "3") {
            // state is key
        } else {
            cout << "Incorrect input" << endl;
            running = false;
        }

        while (running) {
            cout << "Menu: " << endl;
            cout << "1. Top k" << endl;
            cout << "2. Bottom k" << endl;
            cout << "3. Find" << endl;
            cout << "4. Change attribute" << endl;
            cout << "5. Exit" << endl;

            string input;
            cin >> input;
            if (input == "1") {
                cout << "Enter a number from 1 to 10." << endl;
                string k;
                cin >> k;
                if (stoi(k)) {
                    int num = stoi(k);
                    if (num < 0 || num > 10) {
                        cout << "Make sure number is between 1 and 10." << endl;
                    }
                    // do comparison using num
                } else {
                    cout << "Please enter a correct digit" << endl;
                }
            } else if (input == "2") {
                cout << "Enter a number from 1 to 10." << endl;
                string k;
                cin >> k;
                if (stoi(k)) {
                    int num = stoi(k);
                    if (num < 0 || num > 10) {
                        cout << "Make sure number is between 1 and 10." << endl;
                    }
                    // do comparison using num
                } else {
                    cout << "Please enter a correct digit" << endl;
                }
            } else if (input == "3") {

            } else if (input == "4") {
                running = false;
            }
            else if (input == "5") {
                running = false;
                attribute = false;
            }
            else {
                cout << "Incorrect input" << endl;
            }
        }
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