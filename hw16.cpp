#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    void simplify() {
        int minVal = (numerator < denominator) ? numerator : denominator;
        int gcd = 1;
        for (int i = 1; i <= abs(minVal); ++i) {
            if (numerator % i == 0 && denominator % i == 0) {
                gcd = i;
            }
        }
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0) { // denominator is positive ? 
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        simplify();
    }

    void setFraction(int num, int denom) {
        if (denom == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        numerator = num;
        denominator = denom;
        simplify();
    }

    void display() const {
        cout << numerator << "/" << denominator << endl;
    }

    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw invalid_argument("Division by zero fraction is not allowed.");
        }
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Fraction(num, denom);
    }
};

int main() {
    try {
        Fraction a(3, 4), b(2, 5);

        cout << "Fraction A: ";
        a.display();

        cout << "Fraction B: ";
        b.display();

        Fraction sum = a + b;
        cout << "Sum: ";
        sum.display();

        Fraction difference = a - b;
        cout << "Difference: ";
        difference.display();

        Fraction product = a * b;
        cout << "Product: ";
        product.display();

        Fraction quotient = a / b;
        cout << "Quotient: ";
        quotient.display();
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
