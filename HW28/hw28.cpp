#include <iostream>
#include <cmath>

using namespace std;

class Engine {
private:
	float power; // horsepower

public:
    Engine(float power) : power(power) {}

    float getPower() const {
        return power;
    }
};

class Wheel {
private:
    int radius; // inches

public:
    Wheel() : radius(0) {} 
    Wheel(int radius) : radius(radius) {}

    int getRadius() const {
        return radius;
    }
};

class Car {
private:
    Engine engine;
    Wheel* wheels;
    int wheelCount;

public:
    Car(Engine engine, Wheel wheels[], int wheelCount) : engine(engine), wheelCount(wheelCount) {
        this->wheels = new Wheel[wheelCount];
        for (int i = 0; i < wheelCount; ++i) {
            this->wheels[i] = wheels[i];
        }
    }

    ~Car() {
        delete[] wheels;
    }

    int drive(int distance) {
        float power = engine.getPower();
        float totalRadius = 0;
        for (int i = 0; i < wheelCount; ++i) {
            totalRadius += wheels[i].getRadius();
        }
        float averageRadius = totalRadius / wheelCount;

        float time = distance / (power * averageRadius * 0.1f);

        cout << "Power: " << power << " hp, Average Radius: " << averageRadius << " inches" << endl;
        cout << "Calculated time (before rounding): " << time << " hours" << endl;

        return static_cast<int>(round(time));
    }
};

class Driver {
private:
    Car* car; 

public:
    Driver(Car* car = nullptr) : car(car) {}

    int useCar(Car& otherCar, int distance) {
        if (car != nullptr) {
            cout << "Using own car." << endl;
            return car->drive(distance);
        }
        else {
            cout << "Using provided car." << endl;
            return otherCar.drive(distance);
        }
    }

    void setCar(Car* newCar) {
        car = newCar;
    }
};

int main() {
    Engine engine1(150.0f);
    Engine engine2(200.0f);

    Wheel wheels1[] = { Wheel(15), Wheel(15), Wheel(15), Wheel(15) };
    Wheel wheels2[] = { Wheel(18), Wheel(18), Wheel(18), Wheel(18) };

    Car car1(engine1, wheels1, 4);
    Car car2(engine2, wheels2, 4);

    Driver driver;

    int distance = 300; // km
    cout << "Time to drive with car1: " << driver.useCar(car1, distance) << " hours" << endl;

    driver.setCar(&car2);
    cout << "Time to drive with car2: " << driver.useCar(car1, distance) << " hours" << endl;
}
