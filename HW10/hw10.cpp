#include <iostream>
using namespace std;

// Task 1 
void copyArray(int* src, int* dest, int size) {
    for (int i = 0; i < size; i++) {
        *(dest + i) = *(src + i);
    }
}

// Task 2 
void reverseArray(int* arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = *(arr + i);
        *(arr + i) = *(arr + size - i - 1);
        *(arr + size - i - 1) = temp;
    }
}

// Task 3
void copyReverseArray(int* src, int* dest, int size) {
    for (int i = 0; i < size; i++) {
        *(dest + i) = *(src + size - i - 1);
    }
}

int main() {
    int size;
    cout << "Enter array size: ";
    cin >> size;

    int* arr1 = new int[size];
    int* arr2 = new int[size];
    int* arr3 = new int[size];

    cout << "Enter elements of array:\n";
    for (int i = 0; i < size; i++) cin >> *(arr1 + i);

    copyArray(arr1, arr2, size);
    cout << "Copied array: ";
    for (int i = 0; i < size; i++) cout << *(arr2 + i) << " ";
    cout << endl;

    reverseArray(arr1, size);
    cout << "Reversed original array: ";
    for (int i = 0; i < size; i++) cout << *(arr1 + i) << " ";
    cout << endl;

    copyReverseArray(arr1, arr3, size);
    cout << "Reversed copied array: ";
    for (int i = 0; i < size; i++) cout << *(arr3 + i) << " ";
    cout << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
}
