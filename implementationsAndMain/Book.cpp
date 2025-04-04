#include "Book.h"
#include <iostream>

Book::Book(string title, int genre, Date created, Location location,
         int lengthInPages, string author, string publisher)
    : Item(title, genre, created, location), lengthInPages(lengthInPages), author(author), publisher(publisher) {}

void Book::print() const {
    Item::print();
    cout << ", Length: " << lengthInPages << " pages, Author: " << author << ", Publisher: " << publisher;
}

int Book::getLengthInPages() const {
    return lengthInPages;
}

string Book::getAuthor() const {
    return author;
}

string Book::getPublisher() const {
    return publisher;
}