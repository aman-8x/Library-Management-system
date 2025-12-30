#include <iostream>
#include "Library.h"

using namespace std;

void displayMenu() {
    cout << "\n=== Library Management System ===" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Add Member" << endl;
    cout << "3. Issue Book" << endl;
    cout << "4. Return Book" << endl;
    cout << "5. Display All Books" << endl;
    cout << "6. Display All Members" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Library lib;
    lib.loadData(); // Load data at startup
    int choice;

    // Uncomment to pre-populate if needed, but loading from file is better
    // lib.addBook(101, "The Great Gatsby", "F. Scott Fitzgerald");
    // lib.addBook(102, "1984", "George Orwell");
    // lib.addMember(1, "Alice");
    // lib.addMember(2, "Bob");

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                string title, author;
                cout << "Enter Book ID: ";
                cin >> id;
                cin.ignore(); // clear buffer
                cout << "Enter Title: ";
                getline(cin, title);
                cout << "Enter Author: ";
                getline(cin, author);
                lib.addBook(id, title, author);
                break;
            }
            case 2: {
                int id;
                string name;
                cout << "Enter Member ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, name);
                lib.addMember(id, name);
                break;
            }
            case 3: {
                int mid, bid;
                cout << "Enter Member ID: ";
                cin >> mid;
                cout << "Enter Book ID: ";
                cin >> bid;
                lib.issueBook(mid, bid);
                break;
            }
            case 4: {
                int mid, bid;
                cout << "Enter Member ID: ";
                cin >> mid;
                cout << "Enter Book ID: ";
                cin >> bid;
                lib.returnBook(mid, bid);
                break;
            }
            case 5:
                lib.displayBooks();
                break;
            case 6:
                lib.displayMembers();
                break;
            case 0:
                lib.saveData();
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
