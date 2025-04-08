#include "Item.h"
#include <iostream>

Item::Item(string title, int genre, Date created, Location location)
    : title(title), genre(genre), created(created), location(location) {}

void Item::print() const {
    cout << "Title: " << title << ", Genre: " << genre << ", Created: ";
    created.print();
    cout << ", Location: ";
    location.print();
}

string Item::getTitle() const {
    return title;
}

int Item::getGenre() const {
    return genre;
}

Date Item::getCreated() const {
    return created;
}

Location Item::getLocation() const {
    return location;
}