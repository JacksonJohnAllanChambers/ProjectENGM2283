#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Item.h"

class Node {
public:
    Item* data;
    Node* next;

    Node(Item* item = nullptr, Node* nextNode = nullptr) : data(item), next(nextNode) {}
};

class LinkedList {
private:
    Node* start;
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
    void sortList();
};

#endif