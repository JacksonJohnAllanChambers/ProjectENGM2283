#include "Location.h"
#include <iostream>

Location::Location(int floor, std::string section, std::string aisle, int shelf)
    : floor(floor), section(section), aisle(aisle), shelf(shelf) {}

void Location::print() const {
    std::cout << "Floor: " << floor << ", Section: " << section
              << ", Aisle: " << aisle << ", Shelf: " << shelf;
}

int Location::getFloor() const {
    return floor;
}

std::string Location::getSection() const {
    return section;
}

std::string Location::getAisle() const {
    return aisle;
}

int Location::getShelf() const {
    return shelf;
}