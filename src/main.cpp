#include <iostream>
#include <string>
#include <limits> // Required for std::numeric_limits

#include "LinkedList.h"
#include "Book.h"
#include "CD.h"
#include "Movie.h"
#include "Date.h"
#include "Location.h"

// Function to clear the input buffer
void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    LinkedList library;
    int choice;

    do {
        std::cout << "\nLibrary Menu:\n";
        std::cout << "1. Store Item\n";
        std::cout << "2. Retrieve Item\n";
        std::cout << "3. Sort Items\n";
        std::cout << "4. Remove Item\n";
        std::cout << "5. Count Items\n";
        std::cout << "6. Is Empty?\n";
        std::cout << "7. Clear Library\n";
        std::cout << "8. Print All Items\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Validate that the input is an integer
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter an integer.\n";
            std::cin.clear(); // Clear error flags
            clearInputBuffer(); // Discard invalid input
            choice = -1;       // Force the loop to repeat
        } else {
            clearInputBuffer(); // Clear any remaining characters from the input buffer
        }

        switch (choice) {
            case 1: {
                int itemType;
                std::cout << "Enter item type (1: Book, 2: CD, 3: Movie): ";
                std::cin >> itemType;

                if (std::cin.fail()) {
                    std::cout << "Invalid input. Please enter an integer.\n";
                    std::cin.clear();
                    clearInputBuffer();
                    break;
                }
                clearInputBuffer();

                std::string title, author, publisher, artist, producer, director;
                int genre, lengthInPages, length;
                int month, day, year, floor, shelf;
                std::string section, aisle;
                std::vector<std::string> cast;
                std::string actor;

                std::cout << "Enter title: ";
                std::getline(std::cin, title);
                std::cout << "Enter genre (Dewey decimal system): ";
                std::cin >> genre;

                if (std::cin.fail()) {
                    std::cout << "Invalid input. Please enter an integer.\n";
                    std::cin.clear();
                    clearInputBuffer();
                    break;
                }
                clearInputBuffer();

                std::cout << "Enter creation date (month day year): ";
                std::cin >> month >> day >> year;

                if (std::cin.fail()) {
                    std::cout << "Invalid input. Please enter integers.\n";
                    std::cin.clear();
                    clearInputBuffer();
                    break;
                }
                clearInputBuffer();

                std::cout << "Enter location (floor section aisle shelf): ";
                std::cin >> floor;
                std::getline(std::cin, section, ' '); // Read until space
                std::getline(std::cin, aisle, ' ');   // Read until space
                std::cin >> shelf;

                if (std::cin.fail()) {
                    std::cout << "Invalid input. Please enter valid values.\n";
                    std::cin.clear();
                    clearInputBuffer();
                    break;
                }
                clearInputBuffer();

                Date created(month, day, year);
                Location location(floor, section, aisle, shelf);

                Item* newItem = nullptr;
                switch (itemType) {
                    case 1: {
                        std::cout << "Enter length in pages: ";
                        std::cin >> lengthInPages;

                        if (std::cin.fail()) {
                            std::cout << "Invalid input. Please enter an integer.\n";
                            std::cin.clear();
                            clearInputBuffer();
                            break;
                        }
                        clearInputBuffer();

                        std::cout << "Enter author: ";
                        std::getline(std::cin, author);
                        std::cout << "Enter publisher: ";
                        std::getline(std::cin, publisher);
                        newItem = new Book(title, genre, created, location, lengthInPages, author, publisher);
                        break;
                    }
                    case 2: {
                        float lengthFloat;
                        std::cout << "Enter length in minutes: ";
                        std::cin >> lengthFloat;

                        if (std::cin.fail()) {
                            std::cout << "Invalid input. Please enter a number.\n";
                            std::cin.clear();
                            clearInputBuffer();
                            break;
                        }
                        clearInputBuffer();

                        std::cout << "Enter artist: ";
                        std::getline(std::cin, artist);
                        std::cout << "Enter producer: ";
                        std::getline(std::cin, producer);
                        newItem = new CD(title, genre, created, location, lengthFloat, artist, producer);
                        break;
                    }
                    case 3: {
                        std::cout << "Enter length in minutes: ";
                        std::cin >> length;

                        if (std::cin.fail()) {
                            std::cout << "Invalid input. Please enter an integer.\n";
                            std::cin.clear();
                            clearInputBuffer();
                            break;
                        }
                        clearInputBuffer();

                        std::cout << "Enter director: ";
                        std::getline(std::cin, director);
                        std::cout << "Enter cast (enter 'done' when finished):\n";
                        while (true) {
                            std::cout << "Enter actor: ";
                            std::getline(std::cin, actor);
                            if (actor == "done") {
                                break;
                            }
                            cast.push_back(actor);
                        }
                        newItem = new Movie(title, genre, created, location, length, director, cast);
                        break;
                    }
                    default:
                        std::cout << "Invalid item type.\n";
                        break;
                }

                if (newItem != nullptr) {
                    library.store(newItem);
                    std::cout << "Item stored successfully!\n";
                }
                break;
            }
            case 2: {
                std::string searchTitle;
                std::cout << "Enter title to search: ";
                std::getline(std::cin, searchTitle);
                Item* retrievedItem = library.retrieve(searchTitle);
                if (retrievedItem != nullptr) {
                    std::cout << "Item found:\n";
                    retrievedItem->print();
                    std::cout << std::endl;
                } else {
                    std::cout << "Item not found.\n";
                }
                break;
            }
            case 3:
                library.sort();
                std::cout << "Library sorted.\n";
                break;
            case 4: {
                std::string removeTitle;
                std::cout << "Enter title to remove: ";
                std::getline(std::cin, removeTitle);
                if (library.remove(removeTitle)) {
                    std::cout << "Item removed successfully.\n";
                } else {
                    std::cout << "Item not found.\n";
                }
                break;
            }
            case 5:
                std::cout << "Number of items: " << library.countItems() << std::endl;
                break;
            case 6:
                if (library.isEmpty()) {
                    std::cout << "Library is empty.\n";
                } else {
                    std::cout << "Library is not empty.\n";
                }
                break;
            case 7:
                library.clear();
                std::cout << "Library cleared.\n";
                break;
            case 8:
                std::cout << "All items in the library:\n";
                library.printAllItems();
                break;
            case 0:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}