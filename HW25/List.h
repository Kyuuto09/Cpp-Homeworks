#pragma once
#ifndef LIST_H
#define LIST_H
#include "Node.h"

class List {
    Node* head;
    Node* tail;
    int size; 
    int grow; 

public:
    List(int grow = 1);
    ~List();

    void AddToHead(int value);
    void AddToTail(int value);
    void DeleteFromTail();
    void Clear();
    void Show() const;

    bool IsEmpty() const;
    int GetSize() const;
    void SetSize(int size, int grow = 1);
    int GetUpperBound() const;
    void FreeExtra();
    void RemoveAll();
    int GetAt(int index) const;
    void SetAt(int index, int value);
    void Add(int value);
    void Append(const List& other);
    int* GetData() const;
    void InsertAt(int index, int value);
    void RemoveAt(int index);

    int& operator[](int index);
    List& operator=(const List& other);
};

#endif // LIST_H
