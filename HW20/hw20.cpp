#include <iostream>
using namespace std;

// Task 1
class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {}

    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    friend ostream& operator<<(ostream& os, const Fraction& frac) {
        os << frac.numerator << "/" << frac.denominator;
        return os;
    }
};

// Task 2
class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex& other) const {
        double denom = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denom, (imag * other.real - real * other.imag) / denom);
    }

    friend ostream& operator<<(ostream& os, const Complex& comp) {
        os << comp.real << (comp.imag >= 0 ? "+" : "") << comp.imag << "i";
        return os;
    }
};

int main() {
    Fraction f1(1, 2), f2(3, 4);
    cout << "Fraction operations:" << endl;
    cout << "f1 + f2 = " << f1 + f2 << endl;
    cout << "f1 - f2 = " << f1 - f2 << endl;
    cout << "f1 * f2 = " << f1 * f2 << endl;
    cout << "f1 / f2 = " << f1 / f2 << endl;

    Complex c1(1, 2), c2(3, 4);
    cout << "Complex operations:" << endl;
    cout << "c1 + c2 = " << c1 + c2 << endl;
    cout << "c1 - c2 = " << c1 - c2 << endl;
    cout << "c1 * c2 = " << c1 * c2 << endl;
    cout << "c1 / c2 = " << c1 / c2 << endl;
}