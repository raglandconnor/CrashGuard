//
// Created by Connor Ragland on 4/10/24.
//

#ifndef PROJECT3_CRASHGUARD_DATANODE_H
#define PROJECT3_CRASHGUARD_DATANODE_H

#include <string>

struct DataNode {
    unsigned long int ID;
    int severity;  // 1 to 4, where 1 is low and 4 is high
    float distance;  // Length of road affected by accident in miles
    std::string startTime, endTime, streetName, city, county, state, zipcode, timezone, weatherCondition, dayNight;
};

#endif //PROJECT3_CRASHGUARD_DATANODE_H
