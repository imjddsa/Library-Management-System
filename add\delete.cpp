#include <iostream>
#include <string>
using namespace std;

void addBook(Book books[], int &count) {
    if (count >= 100) {
        cout << "Library is full! Cannot add more books." << endl;
        return;
    }

    cout << "\n===== Add New Book =====" << endl;
    
    cout << "Enter title: ";
    cin.ignore();
    getline(cin, books[count].title);
    
    cout << "Enter author: ";
    getline(cin, books[count].author);
    
    cout << "Enter year: ";
    cin >> books[count].year;
    
    cout << "Enter genre: ";
    cin.ignore();
    getline(cin, books[count].genre);
    
    cout << "Enter description: ";
    getline(cin, books[count].description);
    
    cout << "Enter rating (0-5): ";
    cin >> books[count].rating;
    
    count++;
    cout << "\nBook added successfully!" << endl;
}

void deleteBook(Book books[], int &count) {
    if (count == 0) {
        cout << "No books in the library!" << endl;
        return;
    }

    cout << "\n===== Delete a Book =====" << endl;
    cout << "Enter the title of the book to delete: ";
    cin.ignore();
    string title;
    getline(cin, title);

    int index = -1;
    for (int i = 0; i < count; i++) {
        if (books[i].title == title) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Book not found!" << endl;
        return;
    }

    for (int i = index; i < count - 1; i++) {
        books[i] = books[i + 1];
    }

    count--;
    cout << "\nBook deleted successfully!" << endl;
}
