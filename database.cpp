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
