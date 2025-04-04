#ifndef BOOK_H
#define BOOK_H

#include "Item.h"
#include <string>

class Book : public Item {
private:
    int lengthInPages;
    string author;
    string publisher;

public:
    Book(string title = "Unknown", int genre = 0, Date created = Date(), Location location = Location(),
         int lengthInPages = 0, string author = "Unknown", string publisher = "Unknown");
    void print() const override;

    // Getters
    int getLengthInPages() const;
    string getAuthor() const;
    string getPublisher() const;
};

#endif