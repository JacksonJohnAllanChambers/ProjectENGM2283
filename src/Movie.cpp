#include "Movie.h"
#include <iostream>

Movie::Movie(std::string title, int genre, Date created, Location location,
          int length, std::string director, std::vector<std::string> cast)
    : Item(title, genre, created, location), length(length), director(director), cast(cast) {}

void Movie::print() const {
    Item::print();
    std::cout << ", Length: " << length << " minutes, Director: " << director << ", Cast: ";
    for (const auto& actor : cast) {
        std::cout << actor << ", ";
    }
}

int Movie::getLength() const {
    return length;
}

std::string Movie::getDirector() const {
    return director;
}

std::vector<std::string> Movie::getCast() const {
    return cast;
}