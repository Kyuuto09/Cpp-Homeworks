#include <iostream>
#include <algorithm>

using namespace std;

void initializeMatrix(int** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = rand() % 100; 
        }
    }
}

void initializeMatrix(double** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = static_cast<double>(rand()) / RAND_MAX * 100; 
        }
    }
}

void initializeMatrix(char** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = 'A' + rand() % 26; 
        }
    }
}

void displayMatrix(int** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void displayMatrix(double** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void displayMatrix(char** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void findMaxMinDiagonal(int** matrix, int size, int& maxVal, int& minVal) {
    maxVal = matrix[0][0];
    minVal = matrix[0][0];
    for (int i = 1; i < size; ++i) {
        if (matrix[i][i] > maxVal) maxVal = matrix[i][i];
        if (matrix[i][i] < minVal) minVal = matrix[i][i];
    }
}

void findMaxMinDiagonal(double** matrix, int size, double& maxVal, double& minVal) {
    maxVal = matrix[0][0];
    minVal = matrix[0][0];
    for (int i = 1; i < size; ++i) {
        if (matrix[i][i] > maxVal) maxVal = matrix[i][i];
        if (matrix[i][i] < minVal) minVal = matrix[i][i];
    }
}

void findMaxMinDiagonal(char** matrix, int size, char& maxVal, char& minVal) {
    maxVal = matrix[0][0];
    minVal = matrix[0][0];
    for (int i = 1; i < size; ++i) {
        if (matrix[i][i] > maxVal) maxVal = matrix[i][i];
        if (matrix[i][i] < minVal) minVal = matrix[i][i];
    }
}

void sortRows(int** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        sort(matrix[i], matrix[i] + size);
    }
}

void sortRows(double** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        sort(matrix[i], matrix[i] + size);
    }
}

void sortRows(char** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        sort(matrix[i], matrix[i] + size);
    }
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    const int size = 3;
    int** intMatrix = new int* [size];
    for (int i = 0; i < size; ++i) {
        intMatrix[i] = new int[size];
    }

    initializeMatrix(intMatrix, size);
    displayMatrix(intMatrix, size);

    int maxVal, minVal;
    findMaxMinDiagonal(intMatrix, size, maxVal, minVal);
    cout << "Max on diagonal: " << maxVal << ", Min on diagonal: " << minVal << endl;

    sortRows(intMatrix, size);
    displayMatrix(intMatrix, size);

    for (int i = 0; i < size; ++i) {
        delete[] intMatrix[i];
    }
    delete[] intMatrix;

    int a = 56, b = 98;
    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b) << endl;

    return 0;
}
