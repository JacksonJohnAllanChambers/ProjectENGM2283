#include "CD.h"
#include <iostream>

CD::CD(string title, int genre, Date created, Location location,
       float length, string artist, string producer)
    : Item(title, genre, created, location), length(length), artist(artist), producer(producer) {}

void CD::print() const {
    Item::print();
    cout << ", Length: " << length << " minutes, Artist: " << artist << ", Producer: " << producer;
}

float CD::getLength() const {
    return length;
}

string CD::getArtist() const {
    return artist;
}

string CD::getProducer() const {
    return producer;
}