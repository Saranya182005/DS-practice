#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Book Class
class Book {
private:
    int id;
    string title;
    string author;

public:
    Book(int id, string title, string author) {
        this->id = id;
        this->title = title;
        this->author = author;
    }
    int getId() const {
        return id;
    }
    string getTitle() const {
        return title;
    }
    string getAuthor() const {
        return author;
    }
    void display() const {
        cout << "ID: " << id << " | Title: " << title << " | Author: " << author << endl;
    }
};
// Library Class
class Library {
private:
    vector<Book> books;
public:
    void addBook(int id, string title, string author) {
        books.push_back(Book(id, title, author));
        cout << "Book added successfully.\n";
    }
    void viewBooks() const {
        if (books.empty()) {
            cout << "Library is empty.\n";
            return;
        }
        cout << "\nList of Books:\n";
        for (const Book& book : books) {
            book.display();
        }
    }
    void searchBook(const string& title) const {
        bool found = false;
        for (const Book& book : books) {
            if (book.getTitle() == title) {
                cout << "Book Found:\n";
                book.display();
                found = true;
            }
        }
        if (!found) {
            cout << "Book not found.\n";
        }
    }
    void deleteBook(int id) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getId() == id) {
                books.erase(it);
                cout << "Book deleted successfully.\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }
};
// Main Function
int main() {
    Library library;
    int choice, id;
    string title, author;

    while (true) {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Search Book by Title\n";
        cout << "4. Delete Book by ID\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
      // clear newline after integer input
        switch (choice) {
        case 1:
            cout << "Enter ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Title: ";
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            library.addBook(id, title, author);
            break;

        case 2:
            library.viewBooks();
            break;

        case 3:
            cout << "Enter Title to Search: ";
            getline(cin, title);
            library.searchBook(title);
            break;

        case 4:
            cout << "Enter ID to Delete: ";
            cin >> id;
            cin.ignore();
            library.deleteBook(id);
            break;

        case 5:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}
