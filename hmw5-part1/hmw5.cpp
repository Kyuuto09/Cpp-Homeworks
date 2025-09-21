#include <iostream>
#include <ctime>


using namespace std;

//1---------------
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

int daysBetweenDates(int year1, int month1, int day1, int year2, int month2, int day2) {
    tm date1 = {};
    date1.tm_year = year1 - 1900;
    date1.tm_mon = month1 - 1;
    date1.tm_mday = day1;

    tm date2 = {};
    date2.tm_year = year2 - 1900;
    date2.tm_mon = month2 - 1;
    date2.tm_mday = day2;

    time_t time1 = mktime(&date1);
    time_t time2 = mktime(&date2);

    const int secondsInDay = 60 * 60 * 24;
    return difftime(time2, time1) / secondsInDay;
}

int main() {
    int year1 = 2020, month1 = 1, day1 = 1;
    int year2 = 2021, month2 = 1, day2 = 1;

    cout << "Difference in days: " << daysBetweenDates(year1, month1, day1, year2, month2, day2) << endl;
    cout << "Is 2020 a leap year? " << (isLeapYear(2020) ? "Yes" : "No") << endl;

}
*/

//2---------------
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

int daysBetweenDates(int year1, int month1, int day1, int year2, int month2, int day2) {
    tm date1 = {};
    date1.tm_year = year1 - 1900;
    date1.tm_mon = month1 - 1;
    date1.tm_mday = day1;

    tm date2 = {};
    date2.tm_year = year2 - 1900;
    date2.tm_mon = month2 - 1;
    date2.tm_mday = day2;

    time_t time1 = mktime(&date1);
    time_t time2 = mktime(&date2);

    const int secondsInDay = 60 * 60 * 24;
    return difftime(time2, time1) / secondsInDay;
}

double averageArray(int arr[], int size) {
    if (size == 0) return 0.0;
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size;
}

int main() {
    int year1 = 2020, month1 = 1, day1 = 1;
    int year2 = 2021, month2 = 1, day2 = 1;

    cout << "Difference in days: " << daysBetweenDates(year1, month1, day1, year2, month2, day2) << endl;
    cout << "Is 2020 a leap year? " << (isLeapYear(2020) ? "Yes" : "No") << endl;

    int arr[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Average of array: " << averageArray(arr, size) << endl;

}
*/

//3---------------
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

int daysBetweenDates(int year1, int month1, int day1, int year2, int month2, int day2) {
    tm date1 = {};
    date1.tm_year = year1 - 1900;
    date1.tm_mon = month1 - 1;
    date1.tm_mday = day1;

    tm date2 = {};
    date2.tm_year = year2 - 1900;
    date2.tm_mon = month2 - 1;
    date2.tm_mday = day2;

    time_t time1 = mktime(&date1);
    time_t time2 = mktime(&date2);

    const int secondsInDay = 60 * 60 * 24;
    return difftime(time2, time1) / secondsInDay;
}

double averageArray(int arr[], int size) {
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
            positiveCount++;
        }
        else if (arr[i] < 0) {
            negativeCount++;
        }
        else {
            zeroCount++;
        }
    }
}

int main() {
    int year1 = 2020, month1 = 1, day1 = 1;
    int year2 = 2021, month2 = 1, day2 = 1;

    cout << "Difference in days: " << daysBetweenDates(year1, month1, day1, year2, month2, day2) << endl;
    cout << "Is 2020 a leap year? " << (isLeapYear(2020) ? "Yes" : "No") << endl;

    int arr[] = { 1, -2, 0, 4, -5, 0, 3 };
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Average of array: " << averageArray(arr, size) << endl;

    int positiveCount, negativeCount, zeroCount;
    countElements(arr, size, positiveCount, negativeCount, zeroCount);
    cout << "Positive elements: " << positiveCount << endl;
    cout << "Negative elements: " << negativeCount << endl;
    cout << "Zero elements: " << zeroCount << endl;

}