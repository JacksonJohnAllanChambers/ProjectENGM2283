#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : start(NULL), count(0) {}


void LinkedList::store(Item* item) {
    Node* newNode = new Node;
    newNode->data = item;
    newNode->next = start;
    start = newNode;
    count++;
}

Item* LinkedList::retrieve(string title) {
    Node* current = start;
    while (current != NULL) {
        if (current->data->getTitle() == title) {
            return current->data;
        }
        current = current->next;
    }
    return NULL; // Not found
}

void LinkedList::sort() {
    sortList();
}

bool LinkedList::remove(string title) {
    Node* current = start;
    Node* previous = NULL;

    while (current != NULL) {
        if (current->data->getTitle() == title) {
            if (previous == NULL) {
                // Removing the start
                start = current->next;
            } else {
                previous->next = current->next;
            }
            delete current->data;
            delete current;
            count--;
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false; // Not found
}

int LinkedList::countItems() const {
    return count;
}

bool LinkedList::isEmpty() const {
    return start == NULL;
}

void LinkedList::clear() {
    Node* current = start;
    while (current != NULL) {
        Node* next = current->next;
        delete current->data;
        delete current;
        current = next;
    }
    start = NULL;
    count = 0;
}

void LinkedList::sortList() {
    // This is Bubble Sort:
    if (start == NULL || start->next == NULL) {
        return; // Already sorted or empty
    }

    bool swapped = true;
    while (swapped) {
        swapped = false;
        Node* current = start;
        Node* previous = NULL;

        while (current != NULL && current->next != NULL) {
            if (current->data->getTitle() > current->next->data->getTitle()) {
                // Swap nodes
                Node* nextNode = current->next;
                current->next = nextNode->next;
                nextNode->next = current;

                if (previous == NULL) {
                    // Swapping the start
                    start = nextNode;
                } else {
                    previous->next = nextNode;
                }

                previous = nextNode;
                swapped = true;
            } else {
                previous = current;
                current = current->next;
            }
        }
    }
}
void LinkedList::printAllItems() const {
    Node* current = start;
    while (current != NULL) {
        current->data->print();
        cout << endl;
        current = current->next;
    }
}