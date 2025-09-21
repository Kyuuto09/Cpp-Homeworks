#include <iostream>
#include <cmath>

using namespace std;

// Task 1
double power(double base, int exponent) {
    return pow(base, exponent);
}

// Task 2
int sumInRange(int num1, int num2) {
    int sum = 0;
    for (int i = min(num1, num2); i <= max(num1, num2); ++i) {
        sum += i;
    }
    return sum;
}

// Task 3
bool isPerfectNumber(int num) {
    int sum = 0;
    for (int i = 1; i <= num / 2; ++i) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum == num;
}

void findPerfectNumbers(int start, int end) {
    cout << "Perfect numbers in the range " << start << " to " << end << ": ";
    for (int i = start; i <= end; ++i) {
        if (isPerfectNumber(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

// Task 4
void displayCard(const string& card) {
    cout << "Card: " << card << endl;
}

// Task 5
bool isLuckyNumber(int num) {
    if (num < 100000 || num > 999999) {
        cout << "The number is not six digits!" << endl;
        return false;
    }
    int firstHalf = num / 1000;
    int secondHalf = num % 1000;

    int firstSum = 0, secondSum = 0;
    while (firstHalf > 0) {
        firstSum += firstHalf % 10;
        firstHalf /= 10;
    }
    while (secondHalf > 0) {
        secondSum += secondHalf % 10;
        secondHalf /= 10;
    }

    return firstSum == secondSum;
}

int main() {
    // Task 1
    double base;
    int exponent;
    cout << "Enter base and exponent: ";
    cin >> base >> exponent;
    cout << base << "^" << exponent << " = " << power(base, exponent) << endl;

    // Task 2
    int num1, num2;
    cout << "Enter two integers for the range: ";
    cin >> num1 >> num2;
    cout << "Sum between " << num1 << " and " << num2 << " = " << sumInRange(num1, num2) << endl;

    // Task 3
    int start, end;
    cout << "Enter the range to find perfect numbers (start and end): ";
    cin >> start >> end;
    findPerfectNumbers(start, end);

    // Task 4
    string card;
    cout << "Enter a card name to display: ";
    cin >> card;
    displayCard(card);

    // Task 5
    int number;
    cout << "Enter a 6-digit number to check if it's lucky: ";
    cin >> number;
    if (isLuckyNumber(number)) {
        cout << "The number " << number << " is lucky!" << endl;
    }
    else {
        cout << "The number " << number << " is not lucky." << endl;
    }
}