#ifndef ITEM_H
#define ITEM_H

#include "Date.h"
#include "Location.h"
#include <string>
using namespace std;

class Item {
protected:
    string title;
    int genre; // Dewey decimal system
    Date created;
    Location location;

public:
    Item(string title = "Unknown", int genre = 0, Date created = Date(), Location location = Location());
    virtual void print() const;

    // Getters
    string getTitle() const;
    int getGenre() const;
    Date getCreated() const;
    Location getLocation() const;
};

#endif