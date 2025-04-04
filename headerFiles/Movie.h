#ifndef MOVIE_H
#define MOVIE_H

#include "Item.h"
#include <string>
#include <vector>

class Movie : public Item {
private:
    int length;
    string director;
    vector<string> cast;

public:
    Movie(string title = "Unknown", int genre = 0, Date created = Date(), Location location = Location(),
          int length = 0, string director = "Unknown", vector<string> cast = {});
    void print() const override;

    int getLength() const;
    string getDirector() const;
    vector<string> getCast() const;
};

#endif