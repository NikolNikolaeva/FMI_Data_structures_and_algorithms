#pragma once

struct Node
{
	long long   value;
	Node* next = nullptr;
	Node* prev = nullptr;

	Node(long long value, Node* next = nullptr, Node* prev = nullptr)
	{
		this->value = value;
		this->next = next;
		this->prev = prev;
	}
};