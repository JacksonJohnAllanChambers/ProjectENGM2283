#ifndef CD_H
#define CD_H

#include "Item.h"
#include <string>

class CD : public Item {
private:
    float length; // in minutes
    string artist;
    string producer;

public:
    CD(string title = "Unknown", int genre = 0, Date created = Date(), Location location = Location(),
       float length = 0.0f, string artist = "Unknown", string producer = "Unknown");
    void print() const override;

    float getLength() const;
    string getArtist() const;
    string getProducer() const;
};

#endif