#include "CD.h"
#include <iostream>

CD::CD(std::string title, int genre, Date created, Location location,
       float length, std::string artist, std::string producer)
    : Item(title, genre, created, location), length(length), artist(artist), producer(producer) {}

void CD::print() const {
    Item::print();
    std::cout << ", Length: " << length << " minutes, Artist: " << artist << ", Producer: " << producer;
}

float CD::getLength() const {
    return length;
}

std::string CD::getArtist() const {
    return artist;
}

std::string CD::getProducer() const {
    return producer;
}