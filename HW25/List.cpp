#include "List.h"
#include <cstdio>
#include <stdexcept> //std::out_of_range

List::List(int grow) : head(nullptr), tail(nullptr), size(0), grow(grow) {}

List::~List() {
    Clear();
}

void List::AddToHead(int value) {
    Node* newNode = new Node(value, head, nullptr);
    if (IsEmpty()) {
        head = tail = newNode;
    }
    else {
        head->prev = newNode;
        head = newNode;
    }
    ++size;
}

void List::AddToTail(int value) {
    Node* newNode = new Node(value, nullptr, tail);
    if (IsEmpty()) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    ++size;
}

void List::DeleteFromTail() {
    if (IsEmpty()) return;

    if (head == tail) {
        delete head;
        head = tail = nullptr;
    }
    else {
        Node* beforeLast = tail->prev;
        beforeLast->next = nullptr;
        delete tail;
        tail = beforeLast;
    }
    --size;
}

void List::Clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    head = tail = nullptr;
    size = 0;
}

void List::Show() const {
    Node* current = head;
    while (current != nullptr) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

bool List::IsEmpty() const {
    return size == 0;
}

int List::GetSize() const {
    return size;
}

void List::SetSize(int size, int grow)
{
}

int List::GetUpperBound() const
{
    return 0;
}

void List::FreeExtra()
{
}

void List::RemoveAll()
{
}

int List::GetAt(int index) const
{
    Node* current = head;
    for (int i = 0; i < index && current != nullptr; ++i) {
        current = current->next;
    }
    return current != nullptr ? current->data : -1; 
}

void List::SetAt(int index, int value)
{
    Node* current = head;
    for (int i = 0; i < index && current != nullptr; ++i) {
        current = current->next;
    }
    if (current != nullptr) {
        current->data = value;
    }
}

void List::Add(int value)
{
    AddToTail(value);
}

void List::Append(const List& other)
{
    Node* current = other.head;
    while (current != nullptr) {
        AddToTail(current->data);
        current = current->next;
    }
}

int* List::GetData() const
{
    int* data = new int[size];
    Node* current = head;
    for (int i = 0; i < size; ++i) {
        data[i] = current->data;
        current = current->next;
    }
    return data;
}

void List::InsertAt(int index, int value)
{
    if (index <= 0) {
        AddToHead(value);
    }
    else if (index >= size) {
        AddToTail(value);
    }
    else {
        Node* current = head;
        for (int i = 0; i < index - 1 && current != nullptr; ++i) {
            current = current->next;
        }
        if (current != nullptr) {
            Node* newNode = new Node(value, current->next, current);
            if (current->next != nullptr) {
                current->next->prev = newNode;
            }
            current->next = newNode;
            ++size;
        }
    }
}

void List::RemoveAt(int index)
{
    if (index < 0 || index >= size) return;

    if (index == 0) {
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
    }
    else {
        Node* current = head;
        for (int i = 0; i < index && current != nullptr; ++i) {
            current = current->next;
        }
        if (current != nullptr) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }
            delete current;
        }
    }
    --size;
}

int& List::operator[](int index)
{
    Node* current = head;
    for (int i = 0; i < index && current != nullptr; ++i) {
        current = current->next;
    }
    if (current == nullptr) {
        throw std::out_of_range("Index out of range");
    }
    return current->data;
}

List& List::operator=(const List& other)
{
    if (this != &other) {
        Clear();
        Node* current = other.head;
        while (current != nullptr) {
            AddToTail(current->data);
            current = current->next;
        }
    }
    return *this;
}
