#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Car {
    string name;
    int year;
    double engineVolume;
    double price;
};

class CarDealership {
    vector<Car> cars;

public:
    void addCar(const Car& car) {
        cars.push_back(car);
    }

    void deleteCar(const string& name) {
        cars.erase(remove_if(cars.begin(), cars.end(), [&](const Car& car) {
            return car.name == name;
            }), cars.end());
    }

    void displayCars() const {
        for (const auto& car : cars) {
            cout << "Name: " << car.name << ", Year: " << car.year
                << ", Engine Volume: " << car.engineVolume << ", Price: " << car.price << endl;
        }
    }

    void sortByName() {
        sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.name < b.name;
            });
    }

    void sortByYear() {
        sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.year < b.year;
            });
    }

    void sortByEngineVolume() {
        sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.engineVolume < b.engineVolume;
            });
    }

    void sortByPrice() {
        sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.price < b.price;
            });
    }

    void searchByName(const string& name) const {
        auto it = find_if(cars.begin(), cars.end(), [&](const Car& car) {
            return car.name == name;
            });
        if (it != cars.end()) {
            cout << "Found: " << it->name << ", Year: " << it->year
                << ", Engine Volume: " << it->engineVolume << ", Price: " << it->price << endl;
        }
        else {
            cout << "Car not found" << endl;
        }
    }
};

int main() {
    CarDealership dealership;
    dealership.addCar({ "Toyota", 2020, 2.0, 30000 });
    dealership.addCar({ "Honda", 2018, 1.8, 25000 });
    dealership.addCar({ "Ford", 2019, 2.5, 28000 });

    cout << "All cars:" << endl;
    dealership.displayCars();

    cout << "\nSorted by name:" << endl;
    dealership.sortByName();
    dealership.displayCars();

    cout << "\nSorted by year:" << endl;
    dealership.sortByYear();
    dealership.displayCars();

    cout << "\nSearching for 'Honda':" << endl;
    dealership.searchByName("Honda");

    cout << "\nDeleting 'Ford':" << endl;
    dealership.deleteCar("Ford");
    dealership.displayCars();
}
