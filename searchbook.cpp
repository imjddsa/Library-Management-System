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
