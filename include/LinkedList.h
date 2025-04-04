#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Item.h"

class LinkedList {
private:
    struct Node {
        Item* data;
        Node* next;
    };
    Node* start;
    int count;

public:
    LinkedList();

    void store(Item* item);
    Item* retrieve(string title);
    void sort();
    bool remove(string title);
    int countItems() const;
    bool isEmpty() const;
    void clear();

    void printAllItems() const;

private:
    void sortList();
};

#endif