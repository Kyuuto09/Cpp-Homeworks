#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

void Task1() {
    int count = 0;
    for (int i = 100; i <= 999; i++) {
        string digits = to_string(i);
        if (digits[0] == digits[1] || digits[1] == digits[2] || digits[0] == digits[2])
            count++;
    }
    cout << count << endl;
}

void Task2() {
    int count = 0;
    for (int i = 100; i <= 999; i++) {
        string digits = to_string(i);
        if (digits[0] != digits[1] && digits[1] != digits[2] && digits[0] != digits[2])
            count++;
    }
    cout << count << endl;
}

void Task3() {
    string number;
    cin >> number;
    number.erase(remove(number.begin(), number.end(), '3'), number.end());
    number.erase(remove(number.begin(), number.end(), '6'), number.end());
    cout << number << endl;
}

void Task4() {
    int A;
    cin >> A;
    for (int B = 1; B <= sqrt(A); B++) {
        if (A % (B * B) == 0 && A % (B * B * B) != 0)
            cout << B << endl;
    }
}

void Task5() {
    int A;
    cin >> A;
    int sumOfDigits = 0;
    string strA = to_string(A);
    for (char c : strA) {
        sumOfDigits += c - '0';
    }
    if (pow(sumOfDigits, 3) == A * A)
        cout << "True" << endl;
    else
        cout << "False" << endl;
}

void Task6() {
    int A;
    cin >> A;
    for (int i = 1; i <= A; i++) {
        if (A % i == 0)
            cout << i << endl;
    }
}

void Task7() {
    int A, B;
    cin >> A >> B;
    int max = std::max(A, B);
    for (int i = 1; i <= max; i++) {
        if (A % i == 0 && B % i == 0)
            cout << i << endl;
    }
}

int main()
{
    Task1();
    Task2();
    Task3();
    Task4();
    Task5();
    Task6();
    Task7();
}