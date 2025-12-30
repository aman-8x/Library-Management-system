#include "Book.h"

Book::Book(int id, string title, string author) {
    this->id = id;
    this->title = title;
    this->author = author;
    this->isIssued = false;
}

int Book::getId() const {
    return id;
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

bool Book::getIsIssued() const {
    return isIssued;
}

void Book::issueBook() {
    if (!isIssued) {
        isIssued = true;
        cout << "Book issued successfully!" << endl;
    } else {
        cout << "Book is already issued!" << endl;
    }
}

void Book::returnBook() {
    if (isIssued) {
        isIssued = false;
        cout << "Book returned successfully!" << endl;
    } else {
        cout << "Book was not issued!" << endl;
    }
}

void Book::displayBook() const {
    cout << "ID: " << id << ", Title: " << title << ", Author: " << author 
         << ", Status: " << (isIssued ? "Issued" : "Available") << endl;
}
