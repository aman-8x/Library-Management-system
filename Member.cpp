#include "Member.h"

Member::Member(int id, string name) {
    this->id = id;
    this->name = name;
    this->issuedBookId = -1; // -1 indicates no book is issued
}

int Member::getId() const {
    return id;
}

string Member::getName() const {
    return name;
}

int Member::getIssuedBookId() const {
    return issuedBookId;
}

void Member::issueBook(int bookId) {
    this->issuedBookId = bookId;
}

void Member::returnBook() {
    this->issuedBookId = -1;
}

void Member::displayMember() const {
    cout << "ID: " << id << ", Name: " << name;
    if (issuedBookId != -1) {
        cout << ", Issued Book ID: " << issuedBookId;
    } else {
        cout << ", No Book Issued";
    }
    cout << endl;
}
