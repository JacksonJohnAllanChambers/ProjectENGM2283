#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr), count(0) {}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::store(Item* item) {
    Node* newNode = new Node;
    newNode->data = item;
    newNode->next = head;
    head = newNode;
    count++;
}

Item* LinkedList::retrieve(string title) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data->getTitle() == title) {
            return current->data;
        }
        current = current->next;
    }
    return nullptr; // Not found
}

void LinkedList::sort() {
    sortList();
}

bool LinkedList::remove(string title) {
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->data->getTitle() == title) {
            if (previous == nullptr) {
                // Removing the head
                head = current->next;
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
    return head == nullptr;
}

void LinkedList::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current->data;
        delete current;
        current = next;
    }
    head = nullptr;
    count = 0;
}

void LinkedList::sortList() {
    // Implement your sorting algorithm here (e.g., bubble sort, insertion sort)
    // This is a placeholder implementation (Bubble Sort):
    if (head == nullptr || head->next == nullptr) {
        return; // Already sorted or empty
    }

    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        Node* previous = nullptr;

        while (current->next != nullptr) {
            if (current->data->getTitle() > current->next->data->getTitle()) {
                // Swap nodes
                Node* nextNode = current->next;
                current->next = nextNode->next;
                nextNode->next = current;

                if (previous == nullptr) {
                    // Swapping the head
                    head = nextNode;
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
    } while (swapped);
}

void LinkedList::printAllItems() const {
    Node* current = head;
    while (current != nullptr) {
        current->data->print();
        cout << endl;
        current = current->next;
    }
}