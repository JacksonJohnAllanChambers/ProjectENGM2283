#ifndef CD_H
#define CD_H

#include "Item.h"
#include <string>

class CD : public Item {
private:
    float length; // in minutes
    std::string artist;
    std::string producer;

public:
    CD(std::string title = "Unknown", int genre = 0, Date created = Date(), Location location = Location(),
       float length = 0.0f, std::string artist = "Unknown", std::string producer = "Unknown");
    void print() const override;

    // Getters
    float getLength() const;
    std::string getArtist() const;
    std::string getProducer() const;
};

#endif