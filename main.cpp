#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    int year;
    string genre;
    string description;
    float rating;
};

// ===== DATABASE FUNCTIONS =====
void loadDatabase(Book books[], int &count) {
    count = 10;
    books[0] = {"The Alchemist", "Paulo Coelho", 1988, "Fiction", "A young shepherd travels from Spain to Egypt in search of treasure.", 4.7};
    books[1] = {"Atomic Habits", "James Clear", 2018, "Self-Help", "A practical guide to building good habits through small daily changes.", 4.8};
    books[2] = {"Rich Dad Poor Dad", "Robert Kiyosaki", 1997, "Finance", "A story about two fathers with different views on money.", 4.6};
    books[3] = {"Think and Grow Rich", "Napoleon Hill", 1937, "Self-Help", "A classic book about the mindset needed to achieve success.", 4.6};
    books[4] = {"1984", "George Orwell", 1949, "Dystopian", "A dark story about a totalitarian society controlling every aspect of life.", 4.7};
    books[5] = {"The 7 Habits of Highly Effective People", "Stephen Covey", 1989, "Self-Help", "Seven principles to become more effective in life.", 4.5};
    books[6] = {"Sapiens", "Yuval Noah Harari", 2011, "History", "A brief history of humankind from the Stone Age to modern era.", 4.7};
    books[7] = {"The Power of Now", "Eckhart Tolle", 1997, "Spirituality", "A guide to enlightenment through living in the present moment.", 4.5};
    books[8] = {"Deep Work", "Cal Newport", 2016, "Productivity", "How to focus deeply on difficult tasks in a distracting world.", 4.6};
    books[9] = {"The 48 Laws of Power", "Robert Greene", 1998, "Psychology", "Forty-eight laws about how power works in human relationships.", 4.4};
}

void displayAllBooks(Book books[], int count) {
    cout << "\n===== Library Database =====" << endl;
    for (int i = 0; i < count; i++) {
        cout << "\nBook " << i + 1 << ":" << endl;
        cout << "Title: " << books[i].title << endl;
        cout << "Author: " << books[i].author << endl;
        cout << "Year: " << books[i].year << endl;
        cout << "Genre: " << books[i].genre << endl;
        cout << "Description: " << books[i].description << endl;
        cout << "Rating: " << books[i].rating << endl;
    }
}

// ===== ADD AND DELETE FUNCTIONS =====
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

// ===== SEARCH FUNCTION =====
void searchBook(Book books[], int count) {
    if (count == 0) {
        cout << "No books in the library!" << endl;
        return;
    }
    cout << "\n===== Search a Book =====" << endl;
    cout << "Enter the title of the book to search: ";
    cin.ignore();
    string title;
    getline(cin, title);
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (books[i].title == title) {
            cout << "\nBook Found!" << endl;
            cout << "Title: " << books[i].title << endl;
            cout << "Author: " << books[i].author << endl;
            cout << "Year: " << books[i].year << endl;
            cout << "Genre: " << books[i].genre << endl;
            cout << "Description: " << books[i].description << endl;
            cout << "Rating: " << books[i].rating << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found!" << endl;
    }
}

// ===== MAIN FUNCTION =====
int main() {
    Book books[100];
    int count = 0;
    int choice;

    loadDatabase(books, count);

    do {
        cout << "\n===== Library Management System =====" << endl;
        cout << "1. Display All Books" << endl;
        cout << "2. Add a Book" << endl;
        cout << "3. Delete a Book" << endl;
        cout << "4. Search a Book" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayAllBooks(books, count);
                break;
            case 2:
                addBook(books, count);
                break;
            case 3:
                deleteBook(books, count);
                break;
            case 4:
                searchBook(books, count);
                break;
            case 0:
                cout << "\nGoodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
