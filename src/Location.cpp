#include "Location.h"
#include <iostream>

Location::Location(int floor, char section, char aisle, int shelf)
    : floor(floor), section(section), aisle(aisle), shelf(shelf) {}

void Location::print() const {
    cout << "Floor: " << floor << ", Section: " << section
         << ", Aisle: " << aisle << ", Shelf: " << shelf;
}

int Location::getFloor() const {
    return floor;
}

char Location::getSection() const { // Updated return type
    return section;
}

char Location::getAisle() const { // Updated return type
    return aisle;
}

int Location::getShelf() const {
    return shelf;
}