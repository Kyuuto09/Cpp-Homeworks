#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <limits>
using namespace std;

//1
/* 
int main() {
    const int size = 10; 
    int arr[size];

    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100; 
    }

    cout << "Array elements: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    cout << "Minimum element: " << min << endl;
    cout << "Maximum element: " << max << endl;

    return 0;
}
*/

/* 
//2
int main() {
    const int months = 12;
    double profit[months];
    int startMonth, endMonth;

    cout << "Enter the profit for each month:" << endl;
    for (int i = 0; i < months; ++i) {
        cout << "Month " << i + 1 << ": ";
        cin >> profit[i];
    }

    cout << "Enter the range of months (e.g., 3 6): ";
    cin >> startMonth >> endMonth;

    startMonth -= 1;
    endMonth -= 1;

    if (startMonth < 0 || endMonth >= months || startMonth > endMonth) {
        cout << "Invalid range!" << endl;
        return 1;
    }

    int minMonth = startMonth;
    int maxMonth = startMonth;

    for (int i = startMonth + 1; i <= endMonth; ++i) {
        if (profit[i] < profit[minMonth]) {
            minMonth = i;
        }
        if (profit[i] > profit[maxMonth]) {
            maxMonth = i;
        }
    }

    cout << "Month with the minimum profit in the range: " << minMonth + 1 << " (Profit: " << profit[minMonth] << ")" << endl;
    cout << "Month with the maximum profit in the range: " << maxMonth + 1 << " (Profit: " << profit[maxMonth] << ")" << endl;

    return 0;
}
*/

//3
int main() {
    int N;
    cout << "Enter the size of the array: ";
    cin >> N;

    vector<double> arr(N);
    cout << "Enter " << N << " elements: ";
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    double sumNegatives = 0;
    double productBetweenMinMax = 1;
    double productEvenIndices = 1;
    double sumBetweenFirstLastNegatives = 0;

    int minIndex = 0, maxIndex = 0;
    int firstNegativeIndex = -1, lastNegativeIndex = -1;

    for (int i = 0; i < N; ++i) {
        if (arr[i] < 0) {
            sumNegatives += arr[i];
            if (firstNegativeIndex == -1) {
                firstNegativeIndex = i;
            }
            lastNegativeIndex = i;
        }

        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }

        if (i % 2 == 0) {
            productEvenIndices *= arr[i];
        }
    }

    if (minIndex > maxIndex) {
        swap(minIndex, maxIndex);
    }

    for (int i = minIndex + 1; i < maxIndex; ++i) {
        productBetweenMinMax *= arr[i];
    }

    if (firstNegativeIndex != -1 && lastNegativeIndex != -1 && firstNegativeIndex != lastNegativeIndex) {
        for (int i = firstNegativeIndex + 1; i < lastNegativeIndex; ++i) {
            sumBetweenFirstLastNegatives += arr[i];
        }
    }

    cout << "Sum of negative elements: " << sumNegatives << endl;
    cout << "Product of elements between min and max: " << productBetweenMinMax << endl;
    cout << "Product of elements with even indices: " << productEvenIndices << endl;
    cout << "Sum of elements between first and last negative elements: " << sumBetweenFirstLastNegatives << endl;

    return 0;
}