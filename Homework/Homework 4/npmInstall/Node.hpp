#pragma once

struct Node
{
    long  value;
    Node* next = nullptr;
    Node* prev = nullptr;

    Node(long  value, Node* next = nullptr, Node* prev = nullptr)
    {
        this->value = value;
        this->next = next;
        this->prev = prev;
    }
    Node(Node* curr)
    {
        value = curr->value;
        next = curr->next;
        prev = curr->prev;
    }
};