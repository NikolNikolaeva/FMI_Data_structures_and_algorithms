#include "Linkedlist.h"
#include <exception>
#include <iostream>

void List::copyFrom(const List& other)
{
	Node* node = other.head;

	while (node != nullptr)
	{
		push_back(node->value);
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

void List::push_back(int value)
{
	Node* newNode = new Node(value);

	if (head == nullptr)
	{
		head = newNode;
		tail = head;
	}
	else
	{
		tail->next = newNode;
		tail = tail->next;
	}
}

void List::push_front(int value)
{
	Node* newNode = new Node(value, head);
	head = newNode;

	if (tail == nullptr)
		tail = head;
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

void List::insert(int value, int position)
{
	if (position == 0)
	{
		push_front(value);
		return;
	}

	if (head == nullptr)
		throw std::out_of_range("List is empty!");


	Node* previous = nullptr;
	Node* currNode = head;

	for (size_t i = 0; i < position; i++)
	{
		if (currNode != nullptr)
		{
			previous = currNode;
			currNode = currNode->next;
		}
		else
			throw std::out_of_range("Invalid position!");
	}

	Node* newNode = new Node(value, currNode);
	previous->next = newNode;

	if (tail == previous)
		tail = newNode;
}

void List::delete_first()
{
	remove(0);
}

void List::delete_last()
{
	if (head == tail) {
		delete_first();
		return;
	}

	Node* curr = head;
	Node* prev = nullptr;
	while (curr->next != nullptr)
	{
		prev = curr;
		curr = curr->next;
	}

	tail = prev;
	prev->next = nullptr;
	delete curr;
}

void List::remove(int position)
{
	if (position == 0)
	{
		delete_first();
		return;
	}

	if (head == nullptr)
		throw std::out_of_range("List is empty");

	Node* current = head;
	Node* previous = nullptr;

	for (int i = 0; i < position; i++)
	{
		if (current->next != nullptr)
		{
			previous = current;
			current = current->next;
		}
		else
			throw std::out_of_range("Invalid position");
	}

	previous->next = current->next;

	if (tail == current) {
		tail = previous;
	}

	delete current;
}

bool List::search(int value)
{
	Node* curr = head;

	while (curr != nullptr)
	{
		if (curr->value == value)
			return true;
		curr = curr->next;
	}
	return false;
}

void List::reverse()
{
	if (head == tail)
		return;

	Node* prev = nullptr;
	Node* curr = head;
	Node* next = head->next;

	while (true)
	{
		curr->next = prev;
		prev = curr;
		curr = next;
		if (curr != nullptr)
			next = next->next;
		else break;
	}

	tail = head;
	head = prev;
}

int List::get(int position) const
{
	if (head == nullptr)
		throw std::out_of_range("List is empty!");

	Node* curr = head;

	for (int i = 0; i < position; i++)
	{
		if (curr->next != nullptr)
			curr = curr->next;
		else
			throw std::out_of_range("Invalid position!");
	}
	return curr->value;
}

int List::peek_front() const
{
	return get(0);
}

int List::peek_back() const
{
	if (tail == nullptr)
		throw std::out_of_range("List is empty!");

	return tail->value;
}

List::~List()
{
	free();
}