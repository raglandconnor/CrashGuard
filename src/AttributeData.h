//
// Created by Connor Ragland on 4/15/24.
//

#ifndef PROJECT3_CRASHGUARD_ATTRIBUTEDATA_H
#define PROJECT3_CRASHGUARD_ATTRIBUTEDATA_H

/*
 * Stores values pertaining to a specific attribute
 * Ex:
 * AttributeData MiamiObject;
 * (stores the total number of crashes in miami and other data points.
*/

struct AttributeData {
    int numCrashes;
    long int totalSeverity;  // For average severity: totalSeverity / numCrashes
    double averageSeverity;
};

#endif //PROJECT3_CRASHGUARD_ATTRIBUTEDATA_H
