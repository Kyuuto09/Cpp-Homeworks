#include <iostream>
using namespace std;

// Task 1:
void addColumn(int** matrix, int& rows, int& cols, int position) {
    for (int i = 0; i < rows; ++i) {
        int* newRow = new int[cols + 1];
        for (int j = 0; j < position; ++j) {
            newRow[j] = matrix[i][j];
        }
        newRow[position] = 0; 
        for (int j = position; j < cols; ++j) {
            newRow[j + 1] = matrix[i][j];
        }
        delete[] matrix[i];
        matrix[i] = newRow;
    }
    cols++;
}

// Task 2:
void removeColumn(int** matrix, int& rows, int& cols, int index) {
    for (int i = 0; i < rows; ++i) {
        int* newRow = new int[cols - 1];
        for (int j = 0; j < index; ++j) {
            newRow[j] = matrix[i][j];
        }
        for (int j = index + 1; j < cols; ++j) {
            newRow[j - 1] = matrix[i][j];
        }
        delete[] matrix[i];
        matrix[i] = newRow;
    }
    cols--;
}

// Task 3:
void cyclicShift(int** matrix, int rows, int cols, int shift, bool shiftRows) {
    if (shiftRows) {
        for (int i = 0; i < abs(shift); ++i) {
            if (shift > 0) {
                int* temp = matrix[0];
                for (int j = 0; j < rows - 1; ++j) {
                    matrix[j] = matrix[j + 1];
                }
                matrix[rows - 1] = temp;
            }
            else {
                int* temp = matrix[rows - 1];
                for (int j = rows - 1; j > 0; --j) {
                    matrix[j] = matrix[j - 1];
                }
                matrix[0] = temp;
            }
        }
    }
    else {
        for (int i = 0; i < abs(shift); ++i) {
            if (shift > 0) {
                for (int j = 0; j < rows; ++j) {
                    int temp = matrix[j][0];
                    for (int k = 0; k < cols - 1; ++k) {
                        matrix[j][k] = matrix[j][k + 1];
                    }
                    matrix[j][cols - 1] = temp;
                }
            }
            else {
                for (int j = 0; j < rows; ++j) {
                    int temp = matrix[j][cols - 1];
                    for (int k = cols - 1; k > 0; --k) {
                        matrix[j][k] = matrix[j][k - 1];
                    }
                    matrix[j][0] = temp;
                }
            }
        }
    }
}

// Task 1, Homework 2:
void transpose(int** matrix, int& rows, int& cols) {
    int** transposed = new int* [cols];
    for (int i = 0; i < cols; ++i) {
        transposed[i] = new int[rows];
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    matrix = transposed;
    swap(rows, cols);
}

// Task 2, Homework 2:
void createDynamicArray(char**& data, int& size) {
    data = new char* [2];
    data[0] = new char[100]; // name
    data[1] = new char[100]; // phone
    size = 2;
}

void inputData(char** data) {
    cout << "Enter name: ";
    cin >> data[0];
    cout << "Enter phone: ";
    cin >> data[1];
}

void searchData(char** data, const char* name) {
    if (strcmp(data[0], name) == 0) {
        cout << "Name: " << data[0] << ", Phone: " << data[1] << endl;
    }
    else {
        cout << "Not found." << endl;
    }
}

void changeData(char** data) {
    cout << "Enter new name: ";
    cin >> data[0];
    cout << "Enter new phone: ";
    cin >> data[1];
}

int main() {
    int rows = 3, cols = 3;
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols] {0}; 
    }


    addColumn(matrix, rows, cols, 1);
    removeColumn(matrix, rows, cols, 1); 
    cyclicShift(matrix, rows, cols, 1, true);
    transpose(matrix, rows, cols);

    char** data;
    int size;
    createDynamicArray(data, size);
    inputData(data);
    searchData(data, "John"); 
    changeData(data);

    // clean up 
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    delete[] data[0];
    delete[] data[1];
    delete[] data;

    return 0;
}
