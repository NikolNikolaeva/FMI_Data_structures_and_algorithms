#pragma once
#include "Node.hpp"

class List
{
public:
	Node* head = nullptr;
	Node* tail = nullptr;

	long long size = 0;

	void copyFrom(const List& other);
	void free();

public:

	List() = default;

	List(const List& other);
	List operator=(const List& other);

	long long  getSize() const;
	void push_back(Node*);
	//void push_front(Node*);
	void print() const;
	//void delete_first();
	//void delete_last();
	//void remove(Node* curr);
	void remove(Node* first, Node* last);
	//long long  peek_front() const;
	//long long  peek_back() const;
	void insert(Node* prev, Node* curr, Node* next);

	~List();
};