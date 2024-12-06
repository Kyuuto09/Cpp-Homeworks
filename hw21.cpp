#include <iostream>
#include <string>
using namespace std;

// Task 1
class Overcoat {
private:
    string type;
    double price;

public:
    Overcoat(string type = "", double price = 0.0) : type(type), price(price) {}

    bool operator==(const Overcoat& other) const {
        return type == other.type;
    }

    Overcoat& operator=(const Overcoat& other) {
        if (this != &other) {
            type = other.type;
            price = other.price;
        }
        return *this;
    }

    bool operator>(const Overcoat& other) const {
        return (type == other.type && price > other.price);
    }

    void display() const {
        cout << "Type: " << type << ", Price: " << price << endl;
    }
};

// Task 2
class Flat {
private:
    double area;
    double price;

public:
    Flat(double area = 0.0, double price = 0.0) : area(area), price(price) {}

    bool operator==(const Flat& other) const {
        return area == other.area;
    }

    Flat& operator=(const Flat& other) {
        if (this != &other) {
            area = other.area;
            price = other.price;
        }
        return *this;
    }

    bool operator>(const Flat& other) const {
        return price > other.price;
    }

    void display() const {
        cout << "Area: " << area << ", Price: " << price << endl;
    }
};

int main() {
    // Task 1
	cout << "Task 1: " << endl;
    Overcoat coat1("Trench", 150.0), coat2("Trench", 200.0), coat3("Jacket", 120.0);
    cout << "Coat1 == Coat2: " << (coat1 == coat2 ? "True" : "False") << endl;
    cout << "Coat1 > Coat2: " << (coat1 > coat2 ? "True" : "False") << endl;
    coat1 = coat3;
    coat1.display();

	cout << "--------------------------------" << endl;

    // Task 2
	cout << "Task 2: " << endl;
    Flat flat1(80.0, 100000.0), flat2(80.0, 120000.0), flat3(90.0, 110000.0);
    cout << "Flat1 == Flat2: " << (flat1 == flat2 ? "True" : "False") << endl;
    cout << "Flat2 > Flat3: " << (flat2 > flat3 ? "True" : "False") << endl;
    flat1 = flat3;
    flat1.display();

}