#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class Contact {
private:
    char* fullName;
    char homePhone[20];
    char workPhone[20];
    char mobilePhone[20];
    char additionalInfo[100];

public:
    Contact(const char* name = "", const char* home = "", const char* work = "", const char* mobile = "", const char* info = "") {
        fullName = new char[strlen(name) + 1];
        strcpy_s(fullName, strlen(name) + 1, name);
        strcpy_s(homePhone, sizeof(homePhone), home);
        strcpy_s(workPhone, sizeof(workPhone), work);
        strcpy_s(mobilePhone, sizeof(mobilePhone), mobile);
        strcpy_s(additionalInfo, sizeof(additionalInfo), info);
    }

    ~Contact() {
        delete[] fullName;
    }

    void setValues(const char* name, const char* home, const char* work, const char* mobile, const char* info) {
        delete[] fullName;
        fullName = new char[strlen(name) + 1];
        strcpy_s(fullName, strlen(name) + 1, name);
        strcpy_s(homePhone, sizeof(homePhone), home);
        strcpy_s(workPhone, sizeof(workPhone), work);
        strcpy_s(mobilePhone, sizeof(mobilePhone), mobile);
        strcpy_s(additionalInfo, sizeof(additionalInfo), info);
    }

    void display() const {
        cout << "Name: " << fullName << endl;
        cout << "Home Phone: " << homePhone << endl;
        cout << "Work Phone: " << workPhone << endl;
        cout << "Mobile Phone: " << mobilePhone << endl;
        cout << "Additional Info: " << additionalInfo << endl;
    }

    const char* getName() const {
        return fullName;
    }
};

class PhoneBook {
private:
    Contact contacts[100];
    int count;

public:
    PhoneBook() : count(0) {}

    void addContact(const char* name, const char* home, const char* work, const char* mobile, const char* info) {
        if (count < 100) {
            contacts[count++].setValues(name, home, work, mobile, info);
        }
        else {
            cout << "Phone book is full." << endl;
        }
    }

    void deleteContact(const char* name) {
        for (int i = 0; i < count; ++i) {
            if (strcmp(contacts[i].getName(), name) == 0) {
                for (int j = i; j < count - 1; ++j) {
                    contacts[j] = contacts[j + 1];
                }
                --count;
                cout << "Contact deleted." << endl;
                return;
            }
        }
        cout << "Contact not found." << endl;
    }

    void searchContact(const char* name) const {
        for (int i = 0; i < count; ++i) {
            if (strcmp(contacts[i].getName(), name) == 0) {
                contacts[i].display();
                return;
            }
        }
        cout << "Contact not found." << endl;
    }

    void displayAll() const {
        if (count == 0) {
            cout << "Phone book is empty." << endl;
            return;
        }
        for (int i = 0; i < count; ++i) {
            contacts[i].display();
            cout << "-------------------" << endl;
        }
    }
};

int main() {
    PhoneBook phoneBook;
    phoneBook.addContact("John Doe", "12345", "67890", "54321", "Friend");
    phoneBook.addContact("Jane Smith", "11223", "44556", "77889", "Colleague");

    cout << "All Contacts:" << endl;
    phoneBook.displayAll();

    cout << "Search for 'John Doe':" << endl;
    phoneBook.searchContact("John Doe");

    cout << "Delete 'John Doe':" << endl;
    phoneBook.deleteContact("John Doe");

    cout << "All Contacts after deletion:" << endl;
    phoneBook.displayAll();

    return 0;
}
