#ifndef ITEM_H
#define ITEM_H

#include "Date.h"
#include "Location.h"
#include <string>

class Item {
protected:
    std::string title;
    int genre; // Dewey decimal system
    Date created;
    Location location;

public:
    Item(std::string title = "Unknown", int genre = 0, Date created = Date(), Location location = Location());
    virtual void print() const;

    // Getters
    std::string getTitle() const;
    int getGenre() const;
    Date getCreated() const;
    Location getLocation() const;
};

#endif