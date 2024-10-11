#include <iostream>
using namespace std;

// Task 1:
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Task 1:
int daysBetweenDates(int day1, int month1, int year1, int day2, int month2, int year2) {
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int days1 = day1, days2 = day2;

    for (int i = 0; i < month1 - 1; ++i) days1 += daysInMonth[i];
    for (int i = 0; i < month2 - 1; ++i) days2 += daysInMonth[i];
    days1 += year1 * 365 + year1 / 4 - year1 / 100 + year1 / 400;
    days2 += year2 * 365 + year2 / 4 - year2 / 100 + year2 / 400;

    if (isLeapYear(year1) && month1 > 2) ++days1;
    if (isLeapYear(year2) && month2 > 2) ++days2;

    return abs(days2 - days1);
}

// Task 2:
double averageArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) sum += arr[i];
    return static_cast<double>(sum) / size;
}

// Task 3:
void countElements(int arr[], int size, int& positive, int& negative, int& zero) {
    positive = negative = zero = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) ++positive;
        else if (arr[i] < 0) ++negative;
        else ++zero;
    }
}

int main() {
    int day1 = 1, month1 = 1, year1 = 2020;
    int day2 = 1, month2 = 1, year2 = 2021;
    cout << "Days between dates: " << daysBetweenDates(day1, month1, year1, day2, month2, year2) << endl;

    int arr[] = { 1, -2, 3, 0, -5, 6 };
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Average of array: " << averageArray(arr, size) << endl;

    int positive, negative, zero;
    countElements(arr, size, positive, negative, zero);
    cout << "Positive: " << positive << ", Negative: " << negative << ", Zero: " << zero << endl;

    return 0;
}
