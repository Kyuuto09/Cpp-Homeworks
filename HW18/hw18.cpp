#include <iostream>
#include <cstring>

using namespace std;

class Person {
private:
    char* name;
public:
    Person(const char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);
    }

    Person(const Person& other) {
        this->name = new char[strlen(other.name) + 1];
        strcpy_s(this->name, strlen(other.name) + 1, other.name);
    }

    ~Person() {
        delete[] name;
    }

    void display() const {
        cout << "Person: " << name << endl;
    }
};

class Apartment {
private:
    Person** residents;
    int numResidents;
public:
    Apartment(int numResidents) : numResidents(numResidents) {
        residents = new Person * [numResidents];
        for (int i = 0; i < numResidents; ++i) {
            residents[i] = nullptr;
        }
    }

    Apartment(const Apartment& other) : numResidents(other.numResidents) {
        residents = new Person * [numResidents];
        for (int i = 0; i < numResidents; ++i) {
            if (other.residents[i] != nullptr) {
                residents[i] = new Person(*other.residents[i]);
            }
            else {
                residents[i] = nullptr;
            }
        }
    }

    ~Apartment() {
        for (int i = 0; i < numResidents; ++i) {
            delete residents[i];
        }
        delete[] residents;
    }

    void addResident(int index, const char* name) {
        if (index >= 0 && index < numResidents) {
            delete residents[index];
            residents[index] = new Person(name);
        }
    }

    void display() const {
        for (int i = 0; i < numResidents; ++i) {
            if (residents[i] != nullptr) {
                residents[i]->display();
            }
        }
    }
};

class House {
private:
    Apartment** apartments;
    int numApartments;
public:
    House(int numApartments) : numApartments(numApartments) {
        apartments = new Apartment * [numApartments];
        for (int i = 0; i < numApartments; ++i) {
            apartments[i] = nullptr;
        }
    }

    House(const House& other) : numApartments(other.numApartments) {
        apartments = new Apartment * [numApartments];
        for (int i = 0; i < numApartments; ++i) {
            if (other.apartments[i] != nullptr) {
                apartments[i] = new Apartment(*other.apartments[i]);
            }
            else {
                apartments[i] = nullptr;
            }
        }
    }

    ~House() {
        for (int i = 0; i < numApartments; ++i) {
            delete apartments[i];
        }
        delete[] apartments;
    }

    void addApartment(int index, int numResidents) {
        if (index >= 0 && index < numApartments) {
            delete apartments[index];
            apartments[index] = new Apartment(numResidents);
        }
    }

    Apartment* getApartment(int index) const {
        if (index >= 0 && index < numApartments) {
            return apartments[index];
        }
        return nullptr;
    }

    void display() const {
        for (int i = 0; i < numApartments; ++i) {
            if (apartments[i] != nullptr) {
                apartments[i]->display();
            }
        }
    }
};

int main() 
{
    House house(2);
    house.addApartment(0, 2);
    house.addApartment(1, 3);

    house.getApartment(0)->addResident(0, "John Doe");
    house.getApartment(0)->addResident(1, "Jane Doe");

    house.getApartment(1)->addResident(0, "Alice");
    house.getApartment(1)->addResident(1, "Bob");
    house.getApartment(1)->addResident(2, "Charlie");

    house.display();
}