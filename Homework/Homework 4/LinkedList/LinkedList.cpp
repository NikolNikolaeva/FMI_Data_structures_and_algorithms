#include <iostream>

struct SinglyLinkedListNode
{
	int data;
	SinglyLinkedListNode* next;
	SinglyLinkedListNode(int node_data) {
		this->data = node_data;
		this->next = nullptr;
	}
};

class SinglyLinkedList
{
public:
	SinglyLinkedListNode* head;
	SinglyLinkedListNode* tail;

	SinglyLinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
	}

	void insert_node(int node_data) {
		SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

		if (!this->head) {
			this->head = node;
		}
		else {
			this->tail->next = node;
		}

		this->tail = node;
	}
};

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position)
{

	if (position == 0)
	{
		SinglyLinkedListNode* curr = llist;
		delete llist;
		llist = curr->next;
		return llist;
	}
	SinglyLinkedListNode* current = llist;
	SinglyLinkedListNode* previous = nullptr;

	for (int i = 0; i < position; i++)
	{
		if (current->next != nullptr)
		{
			previous = current;
			current = current->next;
		}
	}
	previous->next = current->next;

	delete current;

	return llist;
}

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {

	SinglyLinkedListNode* previous = nullptr;
	SinglyLinkedListNode* currNode = llist;

	for (int i = 0; i < position; i++)
	{
		if (currNode != nullptr)
		{
			previous = currNode;
			currNode = currNode->next;
		}
	}

	SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
	newNode->next = currNode;
	previous->next = newNode;

	return llist;
}

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)
{
	int countList1 = 0;
	int countList2 = 0;

	SinglyLinkedListNode* curr1 = head1;
	SinglyLinkedListNode* curr2 = head2;

	while (curr1 != nullptr)
	{
		countList1++;
		curr1 = curr1->next;
	}
	curr1 = head1;
	while (curr2 != nullptr)
	{
		countList2++;
		curr2 = curr2->next;
	}
	curr2 = head2;

	int bigger = countList1 > countList2 ? 1 : 2;

	if (bigger == 1)
	{
		for (int i = 0; i < countList1 - countList2; i++)
		{
			curr1 = curr1->next;
		}
	}
	else
	{
		for (int i = 0; i < countList2 - countList1; i++)
		{
			curr2 = curr2->next;
		}
	}

	while (curr1 != curr2)
	{
		curr1 = curr1->next;
		curr2 = curr2->next;
	}

	return curr1->data;
}

void print_singly_linked_list(SinglyLinkedListNode* node)
{
	while (node != nullptr) {
		std::cout << node->data;

		node = node->next;
	}
}

void free_singly_linked_list(SinglyLinkedListNode* node)
{
	while (node != nullptr)
	{
		SinglyLinkedListNode* temp = node;
		node = node->next;
		delete temp;
	}
}

int main()
{

}