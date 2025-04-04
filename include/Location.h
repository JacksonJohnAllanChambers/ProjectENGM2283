#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <iostream>
using namespace std;

class Location {
private:
    int floor;
    string section;
    string aisle;
    int shelf;

public:
    Location(int floor = 1, string section = "General", string aisle = "A", int shelf = 1);
    void print() const;

    // Getters
    int getFloor() const;
    string getSection() const;
    string getAisle() const;
    int getShelf() const;
};

#endif