#include <iostream>
#include <string>

#include "LinkedList.h"
#include "Book.h"
#include "CD.h"
#include "Movie.h"
#include "Date.h"
#include "Location.h"

using namespace std;

int main() {
    LinkedList library;
    char choice;

    do {
        cout << "---------------------Library Menu-------------------" << endl;
        cout << "1. Store Item" << endl;
        cout << "2. Retrieve Item" << endl;
        cout << "3. Sort Items" << endl;
        cout << "4. Remove Item" << endl;
        cout << "5. Count Items" << endl;
        cout << "6. Is Empty?" << endl;
        cout << "7. Clear Library" << endl;
        cout << "8. Print All Items" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                int itemType;
                do {
                    cout << "'\n'---------------------Item Menu-------------------";
                    cout << "1. Book" << endl;
                    cout << "2. CD" << endl;
                    cout << "3. Movie" << endl;
                    cin >> itemType;

                    if (cin.fail() || (itemType < 1 || itemType > 3)) {
                        cout << "Invalid input. Please enter an integer between 1 and 3.\n";
                        cin.clear(); // Clear the error flag
                        cin.ignore(1000, '\n'); // Discard invalid input
                    } else {
                        break; // Valid input, exit the loop
                    }
                } while (true);

                string title, author, publisher, artist, producer, director;
                int genre, lengthInPages, length;
                int month, day, year, floor, shelf;
                char section, aisle;
                vector<string> cast;
                string actor;

                cout << "Enter title: ";
                cin.ignore(); // Ignore leftover newline
                getline(cin, title);

                do {
                    cout << "Enter genre (Dewey decimal system): ";
                    cin >> genre;
                    if (cin.fail() || genre < 0 || genre > 999){
                        cout << "Invalid input. Please enter an integer between 0 - 999.\n";
                        cin.clear();
                        cin.ignore(1000, '\n'); // Clear invalid input
                    } else {
                        break;
                    }
                } while (true);
                
                do{
                    cout << "Enter publishing date (month day year): ";
                    cin >> month >> day >> year;
                    if (cin.fail() || month < 1 || month > 12 || day < 1 ||
                     day > 31 || year < 1 || year > 2025){
                        cout << "Invalid input. Please enter a integers; month(1-12), day(1-31), year(0-2025)." << endl;
                        cin.clear();
                        cin.ignore(1000, '\n'); // Clear invalid input
                    } else {
                        break;
                    }
                } while (true);

                do {
                    cout << "Enter location (floor section aisle shelf): ";
                    cin >> floor >> section >> aisle >> shelf;

                    // Validate input
                    if (cin.fail() || floor < 1 || floor > 30 || section < 'A' || section > 'Z' || aisle < 'A' || aisle > 'Z' || shelf < 1 || shelf > 6) {
                        cout << "Invalid input. Please enter; floor(1-30), section(A-Z), aisle(A-Z), shelf(1-6)." << endl;
                        cin.clear();
                        cin.ignore(1000, '\n'); // Clear invalid input
                    } else {
                        break;
                    }
                } while (true);

                Date created(month, day, year);
                Location location(floor, section, aisle, shelf);

                Item* newItem = nullptr;
                switch (itemType) {
                    case 1: {
                        
                        do {
                            cout << "Enter length in pages: ";
                            cin >> lengthInPages;
                            if (cin.fail()) {
                                cout << "Invalid input. Please enter an integer." << endl;
                                cin.clear();
                                cin.ignore(1000, '\n'); // Clear invalid input
                            } else{
                                break;
                            }
                        } while (true);

                        do {
                            cout << "Enter author: ";
                            cin.ignore(); // Ignore leftover newline
                            getline(cin, author);
                            if (cin.fail()) {
                                cout << "Invalid input. Please enter a name.\n";
                                cin.clear();
                                cin.ignore(1000, '\n'); // Clear invalid input
                            } else {
                                break;
                            }
                        } while (true);
                        do {
                            cout << "Enter publisher: ";
                            getline(cin, publisher);
                            if (cin.fail()) {
                                cout << "Invalid input. Please enter a name.\n";
                                cin.clear();
                                cin.ignore(1000, '\n'); // Clear invalid input
                            } else {
                                break;
                            }
                        } while (true);
                        newItem = new Book(title, genre, created, location, lengthInPages, author, publisher);
                        break; // Add this
                    }
                    case 2: {
                        float lengthFloat;
                        
                        do {
                            cout << "Enter length in minutes: ";
                            cin >> lengthFloat;
                            if (cin.fail()) {
                                cout << "Invalid input. Please enter a number.\n";
                                cin.clear();
                                cin.ignore(1000, '\n'); // Clear invalid input
                            } else {
                                break;
                            }
                        } while (true);

                        do {
                            cout << "Enter artist: ";
                            cin.ignore(); // Ignore leftover newline
                            getline(cin, artist);
                            if(cin.fail()){
                                cout << "Invalid input. Please enter a name.\n";
                                cin.clear();
                                cin.ignore(1000, '\n'); // Clear invalid input
                            } else {
                                break;
                            }
                        } while (true);

                        do{
                            cout << "Enter producer: ";
                            getline(cin, producer);
                            if(cin.fail()){
                                cout << "Invalid input. Please enter a name.\n";
                                cin.clear();
                                cin.ignore(1000, '\n'); // Clear invalid input
                            } else {
                                break;
                            }
                        } while (true);
                        newItem = new CD(title, genre, created, location, lengthFloat, artist, producer);
                        break;
                    }
                    case 3: {
                        do{
                            cout << "Enter length in minutes: ";
                            cin >> length;
                            if (cin.fail()) {
                                cout << "Invalid input. Please enter in integers.\n";
                                cin.clear();
                                cin.ignore(1000, '\n'); // Clear invalid input
                            } else {
                                break;
                            }
                        } while (true);

                        do {
                            cout << "Enter director: ";
                            cin.ignore(); // Ignore leftover newline
                            getline(cin, director);
                            if (cin.fail()) {
                                cout << "Invalid input. Please enter a name.\n";
                                cin.clear();
                                cin.ignore(1000, '\n'); // Clear invalid input
                            } else {
                                break;
                            }
                        } while (true);
                        vector<string> cast; // Vector to store cast members
                        do {
                            cout << "Enter cast (type 'done' to finish): ";
                            string actor; // Temporary variable to store input
                            getline(cin, actor);
                            if (actor == "done") {
                                break; // Exit the loop when the user types "done"
                            }
                            cast.push_back(actor); // Add the actor to the cast list
                        } while (true);
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
            case '2': {
                string searchTitle;
                
                do {
                    cout << "Enter title to search: ";
                    cin.ignore(); // Ignore leftover newline
                    getline(cin, searchTitle);
                    if (cin.fail()) {
                        cout << "Invalid input. Please enter a title.\n";
                        cin.clear();
                        cin.ignore(1000, '\n'); // Clear invalid input
                    } else {
                        break;
                    }
                } while (true);
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
            case '3': {
                library.sort();
                cout << "Library sorted.\n";
                break;
            }
            case '4': {
                string removeTitle;
                cout << "Enter title to remove: ";
                cin.ignore(); // Ignore leftover newline
                getline(cin, removeTitle);
                if (library.remove(removeTitle)) {
                    cout << "Item removed successfully.\n";
                } else {
                    cout << "Item not found.\n";
                }
                break;
            }
            case '5': {
                cout << "Number of items: " << library.countItems() << endl;
                break;
            }
            case '6': {
                if (library.isEmpty()) {
                    cout << "Library is empty.\n";
                } else {
                    cout << "Library is not empty.\n";
                }
                break;
            }
            case '7': {
                library.clear();
                cout << "Library cleared.\n";
                break;
            }
            case '8': {
                cout << "All items in the library:\n";
                library.printAllItems();
                break;
            }
            case '0': {
                cout << "Exiting program.\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
            }
        }
    } while (choice != '0');

    return 0;
}