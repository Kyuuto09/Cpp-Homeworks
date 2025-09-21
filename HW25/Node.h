#pragma once
#ifndef NODE_H // header guard 
#define NODE_H

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int value, Node* next = nullptr, Node* prev = nullptr)
        : data(value), next(next), prev(prev) {
    }
};

#endif // NODE_H 
