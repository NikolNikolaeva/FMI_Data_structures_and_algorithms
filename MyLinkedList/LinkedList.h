#pragma once
#include "Node.hpp"

class List
{
private:
	Node* head = nullptr;
	Node* tail = nullptr;

	void copyFrom(const List& other);
	void free();

public:

	List() = default;

	List(const List& other);
	List operator=(const List& other);

	void push_back(int value);
	void push_front(int value);
	void print() const;
	void insert(int value, int position);
	void delete_first();
	void delete_last();
	void remove(int position);
	bool search(int value);
	void reverse();
	int get(int position) const;
	int peek_front() const;
	int peek_back() const;
	Node* middleNode() const;
	Node* deleteDuplicates();
	bool hasCycle();

	~List();

};