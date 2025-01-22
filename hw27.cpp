#include <iostream>
#include <stdexcept>
using namespace std;

//task 1
/* 
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(int val) {
        Node* newNode = new (nothrow) Node(val);
        if (!newNode) {
            throw runtime_error("Memory allocation failed");
        }
        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void remove() {
        if (head == nullptr) {
            throw runtime_error("Attempt to remove from an empty list");
        }
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void display() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    try {
        DoublyLinkedList list;
        list.add(10);
        list.add(20);
        list.display();
        list.remove();
        list.display();
        list.remove();
        list.remove(); 
    }
    catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }
}
*/

//Task 2
class CustomException : public runtime_error {
public:
    CustomException(const string& message) : runtime_error(message) {}
};

class MemoryException : public CustomException {
public:
    MemoryException() : CustomException("Memory allocation failed") {}
};

class EmptyListException : public CustomException {
public:
    EmptyListException() : CustomException("Attempt to remove from an empty list") {}
};

class MathException : public CustomException {
public:
    MathException(const string& message) : CustomException(message) {}
};

class FileException : public CustomException {
public:
    FileException(const string& message) : CustomException(message) {}
};

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(int val) {
        Node* newNode = new (nothrow) Node(val);
        if (!newNode) {
            throw MemoryException();
        }
        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void remove() {
        if (head == nullptr) {
            throw EmptyListException();
        }
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void display() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    try {
        DoublyLinkedList list;
        list.add(10);
        list.add(20);
        list.display();
        list.remove();
        list.display();
        list.remove();
        list.remove();
    }
    catch (const CustomException& e) {
        cerr << "CustomException: " << e.what() << endl;
    }
}
