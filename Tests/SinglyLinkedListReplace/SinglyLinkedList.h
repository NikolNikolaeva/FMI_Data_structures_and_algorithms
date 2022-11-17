#pragma once


struct Node
{
    int value;
    Node* next;
    // Constructor with two arguments, one of which is default
    Node(int value, Node* next = nullptr) : value(value), next(next) {};
};

struct SinglyLinkedList
{
    Node* head, * tail;
    int size;

    SinglyLinkedList() :head(nullptr), tail(nullptr), size(0) {}; // Default constructor

    void addAtHead(int X); // Utility function for add 
    void addAtTail(int X); // Utility function for add 
    void add(int X, int pos);

    void remove(int pos);

    void reverse(); // Iterative

    Node* reverseRecursiveUtil(Node* head); // Utility function for recursive reverse function
    void reverseRecursive(); // Recursive

    bool isPalindrom();

    int count(int X);

    void replace(int X);

    void group(int start, int end);

    // Instead of print function
    friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList& list);
};
