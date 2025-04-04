#include "Movie.h"
#include <iostream>

Movie::Movie(string title, int genre, Date created, Location location,
          int length, string director, vector<string> cast)
    : Item(title, genre, created, location), length(length), director(director), cast(cast) {}

void Movie::print() const {
    Item::print();
    cout << ", Length: " << length << " minutes, Director: " << director << ", Cast: ";
    for (const auto& actor : cast) {
        cout << actor << ", ";
    }
}

int Movie::getLength() const {
    return length;
}

string Movie::getDirector() const {
    return director;
}

vector<string> Movie::getCast() const {
    return cast;
}