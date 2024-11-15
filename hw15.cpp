#include <iostream>
#include <string>
using namespace std;

// Task 1:
struct Complex {
    double real;
    double imag;

    Complex operator+(const Complex& other) {
        return { real + other.real, imag + other.imag };
    }

    Complex operator-(const Complex& other) {
        return { real - other.real, imag - other.imag };
    }

    Complex operator*(const Complex& other) {
        return { real * other.real - imag * other.imag, real * other.imag + imag * other.real };
    }

    Complex operator/(const Complex& other) {
        double denominator = other.real * other.real + other.imag * other.imag;
        return { (real * other.real + imag * other.imag) / denominator,
                (imag * other.real - real * other.imag) / denominator };
    }

    void display() const {
        cout << real << (imag >= 0 ? "+" : "") << imag << "i" << endl;
    }
};

// Task 2:
struct Car {
    double length;
    double clearance;
    double engineVolume;
    double enginePower;
    double wheelDiameter;
    string color;
    string transmission;

    void setValues(double len, double clr, double vol, double power, double diam, const string& col, const string& trans) {
        length = len;
        clearance = clr;
        engineVolume = vol;
        enginePower = power;
        wheelDiameter = diam;
        color = col;
        transmission = trans;
    }

    void displayValues() const {
        cout << "Length: " << length << endl;
        cout << "Clearance: " << clearance << endl;
        cout << "Engine Volume: " << engineVolume << endl;
        cout << "Engine Power: " << enginePower << endl;
        cout << "Wheel Diameter: " << wheelDiameter << endl;
        cout << "Color: " << color << endl;
        cout << "Transmission: " << transmission << endl;
    }

    bool findByColor(const string& searchColor) const {
        return color == searchColor;
    }
};

int main() {
    // Task 1
    Complex a{ 3, 4 }, b{ 1, -2 };

    cout << "Complex Number A: ";
    a.display();

    cout << "Complex Number B: ";
    b.display();

    Complex sum = a + b;
    cout << "Sum: ";
    sum.display();

    Complex difference = a - b;
    cout << "Difference: ";
    difference.display();

    Complex product = a * b;
    cout << "Product: ";
    product.display();

    Complex quotient = a / b;
    cout << "Quotient: ";
    quotient.display();

    // Task 2
    Car car;
    car.setValues(4.5, 0.2, 2.0, 150, 18, "Red", "Automatic");
    cout << "\nCar Details:" << endl;
    car.displayValues();

    string searchColor = "Red";
    if (car.findByColor(searchColor)) {
        cout << "\nCar with color " << searchColor << " found." << endl;
    }
    else {
        cout << "\nCar with color " << searchColor << " not found." << endl;
    }

    return 0;
}
