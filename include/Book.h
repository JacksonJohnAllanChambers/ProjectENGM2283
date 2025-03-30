#ifndef BOOK_H
#define BOOK_H

#include "Item.h"
#include <string>

class Book : public Item {
private:
    int lengthInPages;
    std::string author;
    std::string publisher;

public:
    Book(std::string title = "Unknown", int genre = 0, Date created = Date(), Location location = Location(),
         int lengthInPages = 0, std::string author = "Unknown", std::string publisher = "Unknown");
    void print() const override;

    // Getters
    int getLengthInPages() const;
    std::string getAuthor() const;
    std::string getPublisher() const;
};

#endif