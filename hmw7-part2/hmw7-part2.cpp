#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Task 1
void initializeMatrix(int** matrix, int size) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            matrix[i][j] = rand() % 100;
}

void initializeMatrix(double** matrix, int size) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            matrix[i][j] = static_cast<double>(rand()) / RAND_MAX * 100;
}

void initializeMatrix(char** matrix, int size) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            matrix[i][j] = 'A' + rand() % 26;
}

template <typename T>
void printMatrix(T** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

template <typename T>
pair<T, T> findMinMaxDiagonal(T** matrix, int size) {
    T minElem = matrix[0][0];
    T maxElem = matrix[0][0];
    for (int i = 0; i < size; ++i) {
        if (matrix[i][i] < minElem) minElem = matrix[i][i];
        if (matrix[i][i] > maxElem) maxElem = matrix[i][i];
    }
    return { minElem, maxElem };
}

template <typename T>
void sortRows(T** matrix, int size) {
    for (int i = 0; i < size; ++i)
        sort(matrix[i], matrix[i] + size);
}

// Task 2
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Task 3
void bullsAndCows(string secret, string guess, int& bulls, int& cows) {
    if (secret.empty()) return;
    if (secret[0] == guess[0]) bulls++;
    else if (secret.find(guess[0]) != string::npos) cows++;
    bullsAndCows(secret.substr(1), guess.substr(1), bulls, cows);
}

int main() {
    srand(time(0));

    // Task 1
    int size = 3;
    int** intMatrix = new int* [size];
    for (int i = 0; i < size; ++i) intMatrix[i] = new int[size];
    initializeMatrix(intMatrix, size);
    printMatrix(intMatrix, size);
    pair<int, int> minMaxInt = findMinMaxDiagonal(intMatrix, size);
    cout << "Min: " << minMaxInt.first << ", Max: " << minMaxInt.second << endl;
    sortRows(intMatrix, size);
    printMatrix(intMatrix, size);

    // Task 2
    cout << "GCD of 48 and 18: " << gcd(48, 18) << endl;

    // Task 3
    string secret = "1234";
    string guess = "1243";
    int bulls = 0, cows = 0;
    bullsAndCows(secret, guess, bulls, cows);
    cout << "Bulls: " << bulls << ", Cows: " << cows << endl;

    for (int i = 0; i < size; ++i) delete[] intMatrix[i];
    delete[] intMatrix;

    return 0;
}
