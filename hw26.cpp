#include <iostream>
#include <string>
using namespace std;

struct Violation {
    string description;
    Violation* next;

    Violation(const string& desc) : description(desc), next(nullptr) {}
};

struct Node {
    string carNumber;
    Violation* violations;
    Node* left;
    Node* right;

    Node(const string& number) : carNumber(number), violations(nullptr), left(nullptr), right(nullptr) {}
};

class TrafficDatabase {
private:
    Node* root;

    void addViolation(Violation*& head, const string& description) {
        if (!head) {
            head = new Violation(description);
        }
        else {
            Violation* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = new Violation(description);
        }
    }

    Node* add(Node* node, const string& carNumber, const string& description) {
        if (!node) {
            Node* newNode = new Node(carNumber);
            addViolation(newNode->violations, description);
            return newNode;
        }

        if (carNumber < node->carNumber) {
            node->left = add(node->left, carNumber, description);
        }
        else if (carNumber > node->carNumber) {
            node->right = add(node->right, carNumber, description);
        }
        else {
            addViolation(node->violations, description);
        }
        return node;
    }

    void printAll(Node* node) {
        if (!node) return;

        printAll(node->left);
        cout << "Car Number: " << node->carNumber << endl;
        cout << "Violations: ";
        Violation* current = node->violations;
        while (current) {
            cout << current->description << "; ";
            current = current->next;
        }
        cout << endl << endl;
        printAll(node->right);
    }

    Node* search(Node* node, const string& carNumber) {
        if (!node || node->carNumber == carNumber) {
            return node;
        }
        if (carNumber < node->carNumber) {
            return search(node->left, carNumber);
        }
        else {
            return search(node->right, carNumber);
        }
    }

    void printInRange(Node* node, const string& minNumber, const string& maxNumber) {
        if (!node) return;

        if (node->carNumber >= minNumber) {
            printInRange(node->left, minNumber, maxNumber);
        }

        if (node->carNumber >= minNumber && node->carNumber <= maxNumber) {
            cout << "Car Number: " << node->carNumber << endl;
            cout << "Violations: ";
            Violation* current = node->violations;
            while (current) {
                cout << current->description << "; ";
                current = current->next;
            }
            cout << endl << endl;
        }

        if (node->carNumber <= maxNumber) {
            printInRange(node->right, minNumber, maxNumber);
        }
    }

public:
    TrafficDatabase() : root(nullptr) {}

    void addTicket(const string& carNumber, const string& description) {
        root = add(root, carNumber, description);
    }

    void printDatabase() {
        printAll(root);
    }

    void printByCarNumber(const string& carNumber) {
        Node* node = search(root, carNumber);
        if (!node) {
            cout << "No data found for car number: " << carNumber << endl;
            return;
        }

        cout << "Car Number: " << node->carNumber << endl;
        cout << "Violations: ";
        Violation* current = node->violations;
        while (current) {
            cout << current->description << "; ";
            current = current->next;
        }
        cout << endl;
    }

    void printByRange(const string& minNumber, const string& maxNumber) {
        printInRange(root, minNumber, maxNumber);
    }
};

void menu() {
    TrafficDatabase db;
    int choice;

    do {
        cout << "\nTraffic Database Menu\n";
        cout << "1. Add Ticket\n";
        cout << "2. Print All Data\n";
        cout << "3. Search by Car Number\n";
        cout << "4. Print by Range\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string carNumber, description;
            cout << "Enter car number: ";
            cin >> carNumber;
            cin.ignore();
            cout << "Enter violation description: ";
            getline(cin, description);
            db.addTicket(carNumber, description);
            break;
        }
        case 2: {
            cout << "Database Content:\n";
            db.printDatabase();
            break;
        }
        case 3: {
            string carNumber;
            cout << "Enter car number to search: ";
            cin >> carNumber;
            db.printByCarNumber(carNumber);
            break;
        }
        case 4: {
            string minNumber, maxNumber;
            cout << "Enter minimum car number: ";
            cin >> minNumber;
            cout << "Enter maximum car number: ";
            cin >> maxNumber;
            db.printByRange(minNumber, maxNumber);
            break;
        }
        case 5: {
            cout << "Exiting...\n";
            break;
        }
        default: {
            cout << "Invalid choice! Please try again.\n";
        }
        }
    } while (choice != 5);
}

int main()
{
    menu();
}
