# Library Management System

A comprehensive Library Management System built in C++ to manage books, members, and borrowing transactions.

## 🚀 Features
- **Book Management**: Add, remove, and list books.
- **Member Management**: Register and remove members.
- **Transactions**: Issue and return books with due date tracking.
- **Data Persistence**: Automatically saves and loads data from text files (`books.txt`, `members.txt`).

## 🛠️ How to Run

### Windows (Easy Way)
1. Download the code or clone the repository.
2. Double-click **`build_and_run.bat`** to compile and run automatically.

### Manual Compilation (Command Line)
If you have a C++ compiler (like g++ MinGW) installed:

```sh
g++ -o library_system.exe main.cpp Book.cpp Member.cpp Library.cpp
./library_system.exe
```

## 📂 Project Structure
- `main.cpp`: Entry point of the application.
- `Library.cpp/h`: Core logic for managing the library system.
- `Book.cpp/h`: Class representing a book.
- `Member.cpp/h`: Class representing a library member.
- `*.txt`: Data files for storing records.
