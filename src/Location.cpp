#include "Location.h"
#include <iostream>

Location::Location(int floor, string section, string aisle, int shelf)
    : floor(floor), section(section), aisle(aisle), shelf(shelf) {}

void Location::print() const {
    cout << "Floor: " << floor << ", Section: " << section
              << ", Aisle: " << aisle << ", Shelf: " << shelf;
}

int Location::getFloor() const {
    return floor;
}

string Location::getSection() const {
    return section;
}

string Location::getAisle() const {
    return aisle;
}

int Location::getShelf() const {
    return shelf;
}