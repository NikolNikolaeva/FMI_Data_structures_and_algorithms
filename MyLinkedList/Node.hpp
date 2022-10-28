#pragma once

struct Node
{
	int value;
	Node* next = nullptr;

	Node(int value, Node* next = nullptr)
	{
		this->value = value;
		this->next = next;
	}
};
