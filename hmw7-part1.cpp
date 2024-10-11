#include <iostream>
using namespace std;

//1-------------------------
/* 
bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}
int daysInMonth(int month, int year) {
    switch (month) {
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return isLeapYear(year) ? 29 : 28;
    default:
        return 31;
    }
}

int dateDifference(int day1, int month1, int year1, int day2, int month2, int year2) {
    int days1 = day1;
    for (int m = 1; m < month1; ++m) {
        days1 += daysInMonth(m, year1);
    }
    int days2 = day2;
    for (int m = 1; m < month2; ++m) {
        days2 += daysInMonth(m, year2);
    }

    int yearDiff = year2 - year1;
    int dayDiff = days2 - days1;

    return yearDiff * 365 + dayDiff + (yearDiff / 4) - (yearDiff / 100) + (yearDiff / 400);
}

int main() {
    int day1, month1, year1, day2, month2, year2;
    cout << "Enter first date (day month year): ";
    cin >> day1 >> month1 >> year1;
    cout << "Enter second date (day month year): ";
    cin >> day2 >> month2 >> year2;

    int diff = dateDifference(day1, month1, year1, day2, month2, year2);
    cout << "Difference in days: " << diff << endl;

    return 0;
}
*/ 

//2-------------------------
//2-------------------------
#include <iostream>
using namespace std;

double calculateMean(int arr[], int size) {
    if (size == 0) return 0.0;
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size;
}

void countElements(int arr[], int size, int& positiveCount, int& negativeCount, int& zeroCount) {
    positiveCount = 0;
    negativeCount = 0;
    zeroCount = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            ++positiveCount;
        }
        else if (arr[i] < 0) {
            ++negativeCount;
        }
        else {
            ++zeroCount;
        }
    }
}

int main() {
    int arr[] = { 1, -2, 3, 0, -5, 6, 0, 8, -9 };
    int size = sizeof(arr) / sizeof(arr[0]);

    // Task 2:
    double mean = calculateMean(arr, size);
    cout << "Mean of the array: " << mean << endl;

    // Task 3:
    int positiveCount, negativeCount, zeroCount;
    countElements(arr, size, positiveCount, negativeCount, zeroCount);
    cout << "Positive elements: " << positiveCount << endl;
    cout << "Negative elements: " << negativeCount << endl;
    cout << "Zero elements: " << zeroCount << endl;

    return 0;
}
