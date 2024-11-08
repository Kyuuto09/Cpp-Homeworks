#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

struct Book {
    string title;
    string author;
    string publisher;
    string genre;
};

// Pribt information about a book
void printBook(const Book& book) {
    cout << "Title: " << book.title << ", Author: " << book.author
        << ", Publisher: " << book.publisher << ", Genre: " << book.genre << endl;
}

// Print information about all books
void printAllBooks(Book books[], int size) {
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". ";
        printBook(books[i]);
    }
}

// Edit book information
void editBook(Book& book) {
    cout << "Enter new title: ";
    getline(cin, book.title);
    cout << "Enter new author: ";
    getline(cin, book.author);
    cout << "Enter new publisher: ";
    getline(cin, book.publisher);
    cout << "Enter new genre: ";
    getline(cin, book.genre);
}

// Search book by author
void searchByAuthor(Book books[], int size, const string& author) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (books[i].author == author) {
            printBook(books[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "No books found by author " << author << "." << endl;
    }
}

// Search book by title
void searchByTitle(Book books[], int size, const string& title) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (books[i].title == title) {
            printBook(books[i]);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No book found with title " << title << "." << endl;
    }
}
bool compareByTitle(const Book& a, const Book& b) {
    return a.title < b.title;
}

bool compareByAuthor(const Book& a, const Book& b) {
    return a.author < b.author;
}

bool compareByPublisher(const Book& a, const Book& b) {
    return a.publisher < b.publisher;
}

int main() {
    const int size = 10;
    Book books[size] = {
        {"The Great Gatsby", "F. Scott Fitzgerald", "Scribner", "Fiction"},
        {"To Kill a Mockingbird", "Harper Lee", "J.B. Lippincott", "Fiction"},
        {"1984", "George Orwell", "Secker & Warburg", "Dystopian"},
        {"Moby Dick", "Herman Melville", "Harper & Brothers", "Adventure"},
        {"Pride and Prejudice", "Jane Austen", "T. Egerton", "Romance"},
        {"War and Peace", "Leo Tolstoy", "The Russian Messenger", "Historical"},
        {"The Odyssey", "Homer", "Penguin Classics", "Epic"},
        {"Hamlet", "William Shakespeare", "Norton", "Tragedy"},
        {"The Catcher in the Rye", "J.D. Salinger", "Little, Brown", "Fiction"},
        {"The Hobbit", "J.R.R. Tolkien", "George Allen & Unwin", "Fantasy"}
    };

    int choice;
    do {
        cout << "\nLibrary Menu:\n";
        cout << "1. Print all books\n";
        cout << "2. Edit a book\n";
        cout << "3. Search books by author\n";
        cout << "4. Search book by title\n";
        cout << "5. Sort books by title\n";
        cout << "6. Sort books by author\n";
        cout << "7. Sort books by publisher\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline after integer input

        switch (choice) {
        case 1:
            printAllBooks(books, size);
            break;
        case 2: {
            int bookIndex;
            cout << "Enter book number to edit (1 to " << size << "): ";
            cin >> bookIndex;
            cin.ignore(); // Ignore newline
            if (bookIndex >= 1 && bookIndex <= size) {
                editBook(books[bookIndex - 1]);
            }
            else {
                cout << "Invalid book number." << endl;
            }
            break;
        }
        case 3: {
            string author;
            cout << "Enter author name: ";
            getline(cin, author);
            searchByAuthor(books, size, author);
            break;
        }
        case 4: {
            string title;
            cout << "Enter book title: ";
            getline(cin, title);
            searchByTitle(books, size, title);
            break;
        }
        case 5:
            sort(books, books + size, compareByTitle);
            cout << "Books sorted by title.\n";
            break;
        case 6:
            sort(books, books + size, compareByAuthor);
            cout << "Books sorted by author.\n";
            break;
        case 7:
            sort(books, books + size, compareByPublisher);
            cout << "Books sorted by publisher.\n";
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}


//DZ 2: 
/* 
struct Car {
    string color;
    string model;
    union Number {
        int numeric;
        char text[9];
    } number;
    bool isNumeric;
};

void fillCar(Car& car) {
    cout << "Enter car color: ";
    cin >> car.color;
    cout << "Enter car model: ";
    cin >> car.model;
    cout << "Is the car number numeric (1 for yes, 0 for no)? ";
    cin >> car.isNumeric;
    if (car.isNumeric) {
        cout << "Enter five-digit numeric number: ";
        cin >> car.number.numeric;
    }
    else {
        cout << "Enter text number (up to 8 characters): ";
        cin >> car.number.text;
    }
}

void printCar(const Car& car) {
    cout << "Color: " << car.color << ", Model: " << car.model << ", Number: ";
    if (car.isNumeric)
        cout << car.number.numeric;
    else
        cout << car.number.text;
    cout << endl;
}

void editCar(Car& car) {
    fillCar(car);
}

void printAllCars(const Car cars[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Car " << i + 1 << ": ";
        printCar(cars[i]);
    }
}

void searchByNumber(const Car cars[], int size, const string& searchNumber) {
    for (int i = 0; i < size; ++i) {
        if ((cars[i].isNumeric && to_string(cars[i].number.numeric) == searchNumber) ||
            (!cars[i].isNumeric && strcmp(cars[i].number.text, searchNumber.c_str()) == 0)) {
            cout << "Found Car " << i + 1 << ": ";
            printCar(cars[i]);
            return;
        }
    }
    cout << "Car with number " << searchNumber << " not found." << endl;
}

int main() {
    const int size = 10;
    Car cars[size];

    int choice;
    do {
        cout << "\n1. Fill a car\n2. Print all cars\n3. Edit a car\n4. Search by number\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int index;
            cout << "Enter car index (1-" << size << "): ";
            cin >> index;
            if (index >= 1 && index <= size) {
                fillCar(cars[index - 1]);
            }
            break;
        }
        case 2: printAllCars(cars, size); break;
        case 3: {
            int index;
            cout << "Enter car index to edit (1-" << size << "): ";
            cin >> index;
            if (index >= 1 && index <= size) {
                editCar(cars[index - 1]);
            }
            break;
        }
        case 4: {
            string searchNumber;
            cout << "Enter car number to search: ";
            cin >> searchNumber;
            searchByNumber(cars, size, searchNumber);
            break;
        }
        case 0: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}
*/