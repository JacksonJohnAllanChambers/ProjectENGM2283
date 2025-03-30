#include "Book.h"
#include <iostream>

Book::Book(std::string title, int genre, Date created, Location location,
         int lengthInPages, std::string author, std::string publisher)
    : Item(title, genre, created, location), lengthInPages(lengthInPages), author(author), publisher(publisher) {}

void Book::print() const {
    Item::print();
    std::cout << ", Length: " << lengthInPages << " pages, Author: " << author << ", Publisher: " << publisher;
}

int Book::getLengthInPages() const {
    return lengthInPages;
}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getPublisher() const {
    return publisher;
}