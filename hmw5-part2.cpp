#include <iostream>
#include <algorithm>

using namespace std;

//1----------- 
/* 
template <typename T>
void initializeMatrix(T** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cin >> matrix[i][j];
        }
    }
}

template <typename T>
void displayMatrix(T** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

template <typename T>
void findMinMaxDiagonal(T** matrix, int size, T& minElem, T& maxElem) {
    minElem = matrix[0][0];
    maxElem = matrix[0][0];
    for (int i = 1; i < size; ++i) {
        if (matrix[i][i] < minElem) {
            minElem = matrix[i][i];
        }
        if (matrix[i][i] > maxElem) {
            maxElem = matrix[i][i];
        }
    }
}

template <typename T>
void sortRows(T** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        sort(matrix[i], matrix[i] + size);
    }
}

int main() {
    int size;
    cin >> size;

    // Integer matrix
    int** intMatrix = new int* [size];
    for (int i = 0; i < size; ++i) {
        intMatrix[i] = new int[size];
    }

    initializeMatrix(intMatrix, size);
    displayMatrix(intMatrix, size);

    int minInt, maxInt;
    findMinMaxDiagonal(intMatrix, size, minInt, maxInt);
    cout << "Min on diagonal: " << minInt << ", Max on diagonal: " << maxInt << endl;

    sortRows(intMatrix, size);
    displayMatrix(intMatrix, size);

    for (int i = 0; i < size; ++i) {
        delete[] intMatrix[i];
    }
    delete[] intMatrix;
}
*/

//2-----------
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int num1, num2;
    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    cout << "GCD of " << num1 << " and " << num2 << " is " << gcd(num1, num2) << endl;

}