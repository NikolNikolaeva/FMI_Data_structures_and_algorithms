#pragma once
#include "Node.hpp"

class List
{
private:
    Node* head = nullptr;
    Node* tail = nullptr;

    unsigned long int size = 0;

    void copyFrom(const List& other);
    void free();

public:

    List() = default;

    List(const List& other);
    List operator=(const List& other);

    long  getSize() const;
    void push_back(Node*);
    void push_front(Node*);
    void print() const;
    void delete_first();
    void delete_last();
    void remove(Node* curr);
    long  peek_front() const;
    long  peek_back() const;

    ~List();
};