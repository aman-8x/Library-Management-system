#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <iostream>

using namespace std;

class Member {
private:
    int id;
    string name;
    int issuedBookId; // -1 if no book issued

public:
    Member(int id, string name);
    int getId() const;
    string getName() const;
    int getIssuedBookId() const;
    void issueBook(int bookId);
    void returnBook();
    void displayMember() const;
};

#endif
