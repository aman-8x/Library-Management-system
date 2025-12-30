#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"
#include "Member.h"

class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:
    void addBook(int id, string title, string author);
    void addMember(int id, string name);
    void issueBook(int memberId, int bookId);
    void returnBook(int memberId, int bookId);
    void saveData();
    void loadData();
    void displayBooks() const;
    void displayMembers() const;
    Book* findBook(int id);
    Member* findMember(int id);
};

#endif
