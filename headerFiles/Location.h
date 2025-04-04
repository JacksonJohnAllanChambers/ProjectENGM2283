#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
using namespace std;

class Location {
private:
    int floor;
    char section;
    char aisle;
    int shelf;

public:
    Location(int floor = 1, char section = 'A', char aisle = 'A', int shelf = 1);
    void print() const;

    int getFloor() const;
    char getSection() const;
    char getAisle() const;
    int getShelf() const;
};

#endif