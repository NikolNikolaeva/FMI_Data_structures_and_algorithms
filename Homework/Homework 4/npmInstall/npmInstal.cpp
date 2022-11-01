#include <iostream>
#include <vector>
#include <list>
#include "DoublyLinkedList.h"

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	long  countRequests;  //T
	long   maxPackages;    //N

	std::cin >> countRequests >> maxPackages;

	List requests;

	std::vector<bool> values(100001, false);
	std::vector<Node*> pointers(100001, nullptr);

	for (long i = 0; i < countRequests; i++)
	{
		long value;
		std::cin >> value;
		if (values[value] == true)
		{
			if (requests.peek_back() == value)
			{
				std::cout << "true" << "\n";
				continue;
			}

			Node* curr = new Node(pointers[value]);
			curr->next = nullptr;
			curr->prev = nullptr;
			if (requests.peek_front() == value)
			{
				pointers[requests.peek_front()] = nullptr;
				requests.delete_first();
			}
			else
			{
				requests.remove(pointers[value]);
				pointers[value] = nullptr;
			}
			requests.push_back(curr);
			pointers[value] = curr;

			std::cout << "true" << "\n";
		}
		else
		{
			Node* curr = new Node(value);
			if (requests.getSize() == maxPackages)
			{
				values[requests.peek_front()] = false;
				pointers[requests.peek_front()] = nullptr;
				requests.delete_first();
			}
			requests.push_back(curr);
			values[value] = true;
			pointers[value] = curr;
			std::cout << "false" << "\n";
		}
	}

	return 0;
}
