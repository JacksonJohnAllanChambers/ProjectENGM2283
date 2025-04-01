#include <iostream>
#include <string>
#include <limits> // Required for numeric_limits

#include "LinkedList.h"
#include "Book.h"
#include "CD.h"
#include "Movie.h"
#include "Date.h"
#include "Location.h"

using namespace std;

// Function to clear the input buffer
void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    LinkedList library;
    int choice;

    do {
        cout << "\nLibrary Menu:\n";
        cout << "1. Store Item\n";
        cout << "2. Retrieve Item\n";
        cout << "3. Sort Items\n";
        cout << "4. Remove Item\n";
        cout << "5. Count Items\n";
        cout << "6. Is Empty?\n";
        cout << "7. Clear Library\n";
        cout << "8. Print All Items\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Validate that the input is an integer
        if (cin.fail()) {
            cout << "Invalid input. Please enter an integer.\n";
            cin.clear(); // Clear error flags
            clearInputBuffer(); // Discard invalid input
            choice = -1;       // Force the loop to repeat
        } else {
            clearInputBuffer(); // Clear any remaining characters from the input buffer
        }

        switch (choice) {
            case 1: {
                int itemType;
                cout << "Enter item type (1: Book, 2: CD, 3: Movie): ";
                cin >> itemType;

                if (cin.fail()) {
                    cout << "Invalid input. Please enter an integer.\n";
                    cin.clear();
                    clearInputBuffer();
                    break;
                }
                clearInputBuffer();

                string title, author, publisher, artist, producer, director;
                int genre, lengthInPages, length;
                int month, day, year, floor, shelf;
                string section, aisle;
                vector<string> cast;
                string actor;

                cout << "Enter title: ";
                getline(cin, title);
                cout << "Enter genre (Dewey decimal system): ";
                cin >> genre;

                if (cin.fail()) {
                    cout << "Invalid input. Please enter an integer.\n";
                    cin.clear();
                    clearInputBuffer();
                    break;
                }
                clearInputBuffer();

                cout << "Enter creation date (month day year): ";
                cin >> month >> day >> year;

                if (cin.fail()) {
                    cout << "Invalid input. Please enter integers.\n";
                    cin.clear();
                    clearInputBuffer();
                    break;
                }
                clearInputBuffer();

                cout << "Enter location (floor section aisle shelf): ";
                cin >> floor;
                getline(cin, section, ' '); // Read until space
                getline(cin, aisle, ' ');   // Read until space
                cin >> shelf;

                if (cin.fail()) {
                    cout << "Invalid input. Please enter valid values.\n";
                    cin.clear();
                    clearInputBuffer();
                    break;
                }
                clearInputBuffer();

                Date created(month, day, year);
                Location location(floor, section, aisle, shelf);

                Item* newItem = nullptr;
                switch (itemType) {
                    case 1: {
                        cout << "Enter length in pages: ";
                        cin >> lengthInPages;

                        if (cin.fail()) {
                            cout << "Invalid input. Please enter an integer.\n";
                            cin.clear();
                            clearInputBuffer();
                            break;
                        }
                        clearInputBuffer();

                        cout << "Enter author: ";
                        getline(cin, author);
                        cout << "Enter publisher: ";
                        getline(cin, publisher);
                        newItem = new Book(title, genre, created, location, lengthInPages, author, publisher);
                        break;
                    }
                    case 2: {
                        float lengthFloat;
                        cout << "Enter length in minutes: ";
                        cin >> lengthFloat;

                        if (cin.fail()) {
                            cout << "Invalid input. Please enter a number.\n";
                            cin.clear();
                            clearInputBuffer();
                            break;
                        }
                        clearInputBuffer();

                        cout << "Enter artist: ";
                        getline(cin, artist);
                        cout << "Enter producer: ";
                        getline(cin, producer);
                        newItem = new CD(title, genre, created, location, lengthFloat, artist, producer);
                        break;
                    }
                    case 3: {
                        cout << "Enter length in minutes: ";
                        cin >> length;

                        if (cin.fail()) {
                            cout << "Invalid input. Please enter an integer.\n";
                            cin.clear();
                            clearInputBuffer();
                            break;
                        }
                        clearInputBuffer();

                        cout << "Enter director: ";
                        getline(cin, director);
                        cout << "Enter cast (enter 'done' when finished):\n";
                        while (true) {
                            cout << "Enter actor: ";
                            getline(cin, actor);
                            if (actor == "done") {
                                break;
                            }
                            cast.push_back(actor);
                        }
                        newItem = new Movie(title, genre, created, location, length, director, cast);
                        break;
                    }
                    default:
                        cout << "Invalid item type.\n";
                        break;
                }

                if (newItem != nullptr) {
                    library.store(newItem);
                    cout << "Item stored successfully!\n";
                }
                break;
            }
            case 2: {
                string searchTitle;
                cout << "Enter title to search: ";
                getline(cin, searchTitle);
                Item* retrievedItem = library.retrieve(searchTitle);
                if (retrievedItem != nullptr) {
                    cout << "Item found:\n";
                    retrievedItem->print();
                    cout << endl;
                } else {
                    cout << "Item not found.\n";
                }
                break;
            }
            case 3:
                library.sort();
                cout << "Library sorted.\n";
                break;
            case 4: {
                string removeTitle;
                cout << "Enter title to remove: ";
                getline(cin, removeTitle);
                if (library.remove(removeTitle)) {
                    cout << "Item removed successfully.\n";
                } else {
                    cout << "Item not found.\n";
                }
                break;
            }
            case 5:
                cout << "Number of items: " << library.countItems() << endl;
                break;
            case 6:
                if (library.isEmpty()) {
                    cout << "Library is empty.\n";
                } else {
                    cout << "Library is not empty.\n";
                }
                break;
            case 7:
                library.clear();
                cout << "Library cleared.\n";
                break;
            case 8:
                cout << "All items in the library:\n";
                library.printAllItems();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}