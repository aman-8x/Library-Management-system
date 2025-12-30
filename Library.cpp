#include "Library.h"
#include <iostream>
#include <fstream>

using namespace std;

void Library::addBook(int id, string title, string author) {
    books.push_back(Book(id, title, author));
    cout << "Book added successfully!" << endl;
}

void Library::addMember(int id, string name) {
    members.push_back(Member(id, name));
    cout << "Member added successfully!" << endl;
}

Book* Library::findBook(int id) {
    for (auto& book : books) {
        if (book.getId() == id) {
            return &book;
        }
    }
    return nullptr;
}

Member* Library::findMember(int id) {
    for (auto& member : members) {
        if (member.getId() == id) {
            return &member;
        }
    }
    return nullptr;
}

void Library::issueBook(int memberId, int bookId) {
    Member* member = findMember(memberId);
    Book* book = findBook(bookId);

    if (member == nullptr) {
        cout << "Member not found!" << endl;
        return;
    }
    if (book == nullptr) {
        cout << "Book not found!" << endl;
        return;
    }

    if (book->getIsIssued()) {
        cout << "Book is already issued to someone else!" << endl;
        return;
    }

    if (member->getIssuedBookId() != -1) {
        cout << "Member already has a book issued. Return it first!" << endl;
        return;
    }

    book->issueBook();
    member->issueBook(bookId);
    cout << "Book issued into member: " << member->getName() << endl;
}

void Library::returnBook(int memberId, int bookId) {
    Member* member = findMember(memberId);
    Book* book = findBook(bookId);

    if (member == nullptr) {
        cout << "Member not found!" << endl;
        return;
    }
    if (book == nullptr) {
        cout << "Book not found!" << endl;
        return;
    }

    if (member->getIssuedBookId() != bookId) {
        cout << "This book is not issued to this member!" << endl;
        return;
    }

    book->returnBook();
    member->returnBook();
    cout << "Book returned from member: " << member->getName() << endl;
}

void Library::saveData() {
    ofstream bookFile("books.txt");
    if (bookFile.is_open()) {
        for (const auto& book : books) {
            bookFile << book.getId() << endl;
            bookFile << book.getTitle() << endl;
            bookFile << book.getAuthor() << endl;
            bookFile << book.getIsIssued() << endl;
        }
        bookFile.close();
    }

    ofstream memberFile("members.txt");
    if (memberFile.is_open()) {
        for (const auto& member : members) {
            memberFile << member.getId() << endl;
            memberFile << member.getName() << endl;
            memberFile << member.getIssuedBookId() << endl;
        }
        memberFile.close();
    }
    cout << "Data saved successfully!" << endl;
}

void Library::loadData() {
    ifstream bookFile("books.txt");
    if (bookFile.is_open()) {
        int id;
        string title, author;
        bool isIssued;
        while (bookFile >> id) {
            bookFile.ignore();
            getline(bookFile, title);
            getline(bookFile, author);
            bookFile >> isIssued;
            Book b(id, title, author);
            if (isIssued) {
                b.issueBook();
            }
            books.push_back(b);
        }
        bookFile.close();
    }

    ifstream memberFile("members.txt");
    if (memberFile.is_open()) {
        int id, issuedBookId;
        string name;
        while (memberFile >> id) {
            memberFile.ignore();
            getline(memberFile, name);
            memberFile >> issuedBookId;
            Member m(id, name);
            if (issuedBookId != -1) {
                m.issueBook(issuedBookId);
            }
            members.push_back(m);
        }
        memberFile.close();
    }
    cout << "Data loaded successfully!" << endl;
}

void Library::displayBooks() const {
    cout << "----- All Books -----" << endl;
    for (const auto& book : books) {
        book.displayBook();
    }
    cout << "---------------------" << endl;
}

void Library::displayMembers() const {
    cout << "----- All Members -----" << endl;
    for (const auto& member : members) {
        member.displayMember();
    }
    cout << "-----------------------" << endl;
}
