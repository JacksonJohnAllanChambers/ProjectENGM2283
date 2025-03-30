#ifndef MOVIE_H
#define MOVIE_H

#include "Item.h"
#include <string>
#include <vector>

class Movie : public Item {
private:
    int length; // Minutes
    std::string director;
    std::vector<std::string> cast;

public:
    Movie(std::string title = "Unknown", int genre = 0, Date created = Date(), Location location = Location(),
          int length = 0, std::string director = "Unknown", std::vector<std::string> cast = {});
    void print() const override;

    // Getters
    int getLength() const;
    std::string getDirector() const;
    std::vector<std::string> getCast() const;
};

#endif