#include "DoublyLinkedList.h"
#include <iostream>

void List::copyFrom(const List& other)
{
	Node* node = other.head;

	while (node != nullptr)
	{
		push_back(node);
		node = node->next;
	}
}

void List::free()
{
	Node* node = head;

	while (node != nullptr)
	{
		Node* next = node->next;
		delete node;
		node = next;
	}

	head = nullptr;
	tail = nullptr;
}

List::List(const List& other)
{
	copyFrom(other);
}

List List::operator=(const List& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

void List::push_back(Node* newNode)
{
	if (head == nullptr)
	{
		head = newNode;
		tail = head;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = tail->next;
	}
	size++;
}

void List::print() const
{
	Node* curr = head;

	while (curr != nullptr)
	{
		std::cout << curr->value << " ";
		curr = curr->next;
	}
}

void List::remove(Node* first, Node* last)
{
	if (first == head && head != nullptr && last != nullptr)
		head = last->next;

	if (head == nullptr)
		tail = nullptr;

	Node* prev;
	if (first != nullptr)
		prev = first->prev;
	else prev = nullptr;

	Node* next;
	if (first != nullptr)
		next = last->next;
	else     next = nullptr;


	if (prev != nullptr)
		prev->next = next;
	else head = next;
	if (next != nullptr)
		next->prev = prev;
	else tail = prev;

	Node* curr = first;
	Node* lastNext = last->next;

	while (curr != lastNext)
	{
		Node* toDelete = curr;
		curr = curr->next;
		delete toDelete;
		size--;
	}

}

long long List::getSize() const
{
	return size;
}


void List::insert(Node* prev, Node* curr, Node* next)
{
	if (prev != nullptr)
		prev->next = curr;
	curr->prev = prev;
	curr->next = next;
	if (next != nullptr)
		next->prev = curr;
	size++;
	if (head == next)
		head = curr;
	if (prev == tail)
		tail = curr;
}

List::~List()
{
	free();
}