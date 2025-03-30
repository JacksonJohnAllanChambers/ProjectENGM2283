#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <iostream>

class Location {
private:
    int floor;
    std::string section;
    std::string aisle;
    int shelf;

public:
    Location(int floor = 1, std::string section = "General", std::string aisle = "A", int shelf = 1);
    void print() const;

    // Getters
    int getFloor() const;
    std::string getSection() const;
    std::string getAisle() const;
    int getShelf() const;
};

#endif