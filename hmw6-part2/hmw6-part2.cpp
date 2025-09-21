#include <iostream>
#include <algorithm> //std::sort

using namespace std;

// Task 1
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1; 
}

// Task 2
int binarySearch(int arr[], int size, int key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid; 
        }
        else if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = { 34, 7, 23, 32, 5, 62 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int key;
    cout << "Enter key to search: ";
    cin >> key;

    // Task 1
    int linearResult = linearSearch(arr, size, key);
    if (linearResult != -1) {
        cout << "Linear Search: Key found at index " << linearResult << endl;
    }
    else {
        cout << "Linear Search: Key not found." << endl;
    }

    sort(arr, arr + size);

    // Task 2
    int binaryResult = binarySearch(arr, size, key);
    if (binaryResult != -1) {
        cout << "Binary Search: Key found at index " << binaryResult << endl;
    }
    else {
        cout << "Binary Search: Key not found." << endl;
    }

    return 0;
}
