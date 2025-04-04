#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Item.h"

class LinkedList {
private:
    struct Node {
        Item* data;
        Node* next;
    };
    Node* head;
    int count;

public:
    LinkedList();
    ~LinkedList();

    void store(Item* item);
    Item* retrieve(string title);
    void sort();
    bool remove(string title);
    int countItems() const;
    bool isEmpty() const;
    void clear();

    void printAllItems() const;

private:
    // Helper function for sorting (you can choose an algorithm)
    void sortList();
};

#endif