#include <iostream>
#include <string>
using namespace std;

// Task 1:
void addColumn(int**& matrix, int rows, int& cols, int pos) {
    int** newMatrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        newMatrix[i] = new int[cols + 1];
        for (int j = 0; j < pos; j++) newMatrix[i][j] = matrix[i][j];
        newMatrix[i][pos] = 0; 
        for (int j = pos; j < cols; j++) newMatrix[i][j + 1] = matrix[i][j];
    }
    cols++;
    for (int i = 0; i < rows; i++) delete[] matrix[i];
    delete[] matrix;
    matrix = newMatrix;
}

// Task 2:
void removeColumn(int**& matrix, int rows, int& cols, int pos) {
    int** newMatrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        newMatrix[i] = new int[cols - 1];
        for (int j = 0; j < pos; j++) newMatrix[i][j] = matrix[i][j];
        for (int j = pos + 1; j < cols; j++) newMatrix[i][j - 1] = matrix[i][j];
    }
    cols--;
    for (int i = 0; i < rows; i++) delete[] matrix[i];
    delete[] matrix;
    matrix = newMatrix;
}

// Task 3:
void cyclicShift(int** matrix, int rows, int cols, int shifts, bool shiftRows) {
    for (int s = 0; s < shifts; s++) {
        if (shiftRows) { 
            for (int i = 0; i < rows; i++) {
                int last = matrix[rows - 1][i];
                for (int j = rows - 1; j > 0; j--) matrix[j][i] = matrix[j - 1][i];
                matrix[0][i] = last;
            }
        }
        else { 
            for (int i = 0; i < cols; i++) {
                int last = matrix[i][cols - 1];
                for (int j = cols - 1; j > 0; j--) matrix[i][j] = matrix[i][j - 1];
                matrix[i][0] = last;
            }
        }
    }
}


void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) cout << matrix[i][j] << " ";
        cout << endl;
    }
}

// Task 4
void transposeMatrix(int**& matrix, int& rows, int& cols) {
    int** transposedMatrix = new int* [cols];
    for (int i = 0; i < cols; i++) {
        transposedMatrix[i] = new int[rows];
        for (int j = 0; j < rows; j++) {
            transposedMatrix[i][j] = matrix[j][i];
        }
    }

    for (int i = 0; i < rows; i++) delete[] matrix[i];
    delete[] matrix;
    matrix = transposedMatrix;
    swap(rows, cols);
}

// Task 5:
struct ContactList {
    string* names;
    string* phones;
    int size;

    ContactList(int n) : size(n) {
        names = new string[size];
        phones = new string[size];
    }

    ~ContactList() {
        delete[] names;
        delete[] phones;
    }

    void addContact(int index, const string& name, const string& phone) {
        if (index < size) {
            names[index] = name;
            phones[index] = phone;
        }
    }

    int searchByName(const string& name) {
        for (int i = 0; i < size; i++) {
            if (names[i] == name) return i;
        }
        return -1;
    }

    int searchByPhone(const string& phone) {
        for (int i = 0; i < size; i++) {
            if (phones[i] == phone) return i;
        }
        return -1;
    }

    void editContact(int index, const string& newName, const string& newPhone) {
        if (index < size) {
            names[index] = newName;
            phones[index] = newPhone;
        }
    }

    void displayContacts() {
        cout << "Contact List:\n";
        for (int i = 0; i < size; i++) {
            cout << "Name: " << names[i] << ", Phone: " << phones[i] << endl;
        }
    }
};

int main() {
    int rows = 3, cols = 3;
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) matrix[i][j] = i * cols + j + 1;
    }

    cout << "Original Matrix:" << endl;
    printMatrix(matrix, rows, cols);

    // Task 1:
    addColumn(matrix, rows, cols, 1);
    cout << "\nAfter Adding Column at Position 1:" << endl;
    printMatrix(matrix, rows, cols);

    // Task 2:
    removeColumn(matrix, rows, cols, 2);
    cout << "\nAfter Removing Column at Position 2:" << endl;
    printMatrix(matrix, rows, cols);

    // Task 3:
    cyclicShift(matrix, rows, cols, 1, true);
    cout << "\nAfter 1 Cyclic Row Shift:" << endl;
    printMatrix(matrix, rows, cols);

    // Task 4:
    transposeMatrix(matrix, rows, cols);
    cout << "\nAfter Transposing the Matrix:" << endl;
    printMatrix(matrix, rows, cols);

    // Task 5:
    ContactList contacts(3);
    contacts.addContact(0, "Alice", "12345");
    contacts.addContact(1, "Bob", "67890");
    contacts.addContact(2, "Carol", "54321");

    cout << "\nContact List:" << endl;
    contacts.displayContacts();

	// Search by Name
    int idx = contacts.searchByName("Bob");
    if (idx != -1) {
        cout << "\nBob found. Editing Bob's contact to Robert with phone 98765.\n";
        contacts.editContact(idx, "Robert", "98765");
    }

    cout << "\nUpdated Contact List:" << endl;
    contacts.displayContacts();

    // Clean up
    for (int i = 0; i < rows; i++) delete[] matrix[i];
    delete[] matrix;
    return 0;
}
