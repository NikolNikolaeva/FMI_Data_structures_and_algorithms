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

void List::push_front(Node* newNode)
{
	newNode->next = head;
	head->prev = newNode;
	head = newNode;

	if (tail == nullptr)
		tail = head;
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
	std::cout << '\n';
}

void List::delete_last()
{
	if (head == tail) {
		delete_first();
		return;
	}

	Node* last = tail;
	tail = last->prev;
	tail->next = nullptr;
	delete last;
	size--;
}

void List::delete_first()
{
	if (head == nullptr)
		return;
	if (head == tail)
	{
		Node* curr = head;
		tail = nullptr;
		head = nullptr;
		delete curr;
		size--;
		return;
	}

	Node* first = head;
	head = first->next;
	head->prev = nullptr;
	delete first;
	size--;
}

void List::remove(Node* curr)
{
	Node* prev = curr->prev;
	Node* next = curr->next;
	prev->next = next;
	next->prev = prev;
	delete curr;
	size--;
}

long List::getSize() const
{
	return size;
}

long List::peek_front() const
{
	return head->value;
}

long List::peek_back() const
{
	return tail->value;
}

List::~List()
{
	free();
}