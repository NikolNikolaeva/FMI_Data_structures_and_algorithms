#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <stack>
#include "SinglyLinkedList.h"
using namespace std;

std::ostream& operator<<(std::ostream& os, const SinglyLinkedList& list)
{
    Node* traverse = list.head;
    while (traverse != nullptr)
    {
        os << traverse->value << '#';
        traverse = traverse->next;
    } //os << '\n';
    return os;
}

void SinglyLinkedList::addAtHead(int X)
{
    Node* newNode = new Node(X);
    if (head == nullptr) // tail will then also point to nullptr
    {
        head = tail = newNode;
    }
    else
    {
        Node* temp = head;
        newNode->next = temp;
        head = newNode;
    }
    size++;
}

void SinglyLinkedList::addAtTail(int X)
{
    Node* newNode = new Node(X);
    if (head == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void SinglyLinkedList::add(int X, int pos)
{
    if (pos == 0) {
        addAtHead(X);
    }
    else if (pos < 0 || pos > size)
    {
        addAtTail(X);
        //std::cout << "add_last";
    }
    else if (pos == size)
    {
        addAtTail(X);
    }
    else
    {
        Node* newNode = new Node(X);
        Node* traverse = head;
        for (int i = 1; i < pos; i++)
        {
            traverse = traverse->next;
        } // traverse points to (pos-1)th Node        
        Node* temp = traverse->next; // pos-th Node  :  traverse - newNode - temp
        traverse->next = newNode;
        newNode->next = temp;
        size++;
    }
}

void SinglyLinkedList::remove(int pos)
{
    if (pos < 0 || pos >= (int)size)
    {
        std::cout << "remove_failed";
    }
    else if (pos == 0)
    {
        Node* temp = head->next;
        delete head;
        head = temp;
        size--;
    }
    else
    {
        Node* traverse = head;
        for (int i = 0; i < pos - 1; i++)
        {
            traverse = traverse->next;
        } // traverseNode points to (pos-1)th Node
        Node* temp = traverse->next; // pos-th Node (node we want to remove)
        traverse->next = temp->next; // (pos+1)th Node
        if (temp->next == nullptr)
        {
            tail = traverse;
        }
        delete temp; // remove temp;
        size--;
    }
}


void SinglyLinkedList::replace(int X)
{
    Node* temp = head;

    for (unsigned long int i = 0; i < X; i++)
    {
        if (temp == nullptr)
            return;
        temp = temp->next;
    }
    if (temp == nullptr)
        return;
    int  num = temp->value;
    Node* curr = head;

    while (curr != nullptr)
    {
        if (curr->value == num && curr->next == nullptr)
            return;
        if (curr->value == num)
        {
            curr->value = curr->next->value;
        }
        curr = curr->next;
    }

}