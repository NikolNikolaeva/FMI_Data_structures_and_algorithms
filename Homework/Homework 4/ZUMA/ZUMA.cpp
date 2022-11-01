
#include <iostream>
#include <list>
#include <vector>
#include "DoublyLinkedList.h"

void ZUMA()
{
	long long  N, Q;

	std::cin >> N;

	List balls;

	std::vector<Node*> pointers;

	for (long long i = 0; i < N; i++)
	{
		long long  value;
		std::cin >> value;
		Node* curr = new Node(value);
		balls.push_back(curr);
		pointers.push_back(curr);
	}

	std::cin >> Q;

	for (long long i = 0; i < Q; i++)
	{
		long long  index, color;
		std::cin >> index >> color;
		if (balls.getSize() == 0)
		{
			std::cout << "Game Over\n";
			continue;
		}
		Node* newNode = new Node(color);
		balls.insert(pointers[index], newNode, pointers[index]->next);
		pointers.push_back(newNode);

		Node* right = newNode;
		Node* left = newNode;

		long long  counter = 0;
		while (true)
		{
			if (balls.getSize() == 0)
			{
				std::cout << "Game Over\n";
				break;
			}
			long long  counterSame = 1;
			while (((right->next != nullptr) && (right != nullptr)) && (right->value == right->next->value))
			{
				counterSame++;
				right = right->next;
			}
			while ((left->prev != nullptr) && (left != nullptr) && (left->value == left->prev->value))
			{
				counterSame++;
				left = left->prev;
			}

			if (counterSame >= 3)
			{
				Node* newLeft = left->prev;
				Node* newRight = right->next;
				balls.remove(left, right);
				if (balls.getSize() == 0)
				{
					counter += counterSame;
					std::cout << counter << '\n';
					break;
				}
				else
				{
					right = newRight;
					left = newLeft;

					if (right == nullptr && left == nullptr)
					{
						balls.head = nullptr;
						balls.tail = nullptr;
						counter += counterSame;
						std::cout << counter << '\n';
						break;
					}
					if (right == nullptr)
					{
						right = left;
						counter += counterSame;
						std::cout << counter << '\n';
						break;
					}
					else if (left == nullptr)
					{
						left = right;
						counter += counterSame;
						std::cout << counter << '\n';
						break;
					}
					else if (right->value == left->value)
					{
						right = left;
						counter += counterSame;
						continue;
					}
					else
					{
						counter += counterSame;
						std::cout << counter << '\n';
						break;
					}
				}
			}
			else
			{
				std::cout << counter << '\n';
				break;
			}
		}

	}

	if (balls.getSize() == 0)
	{
		std::cout << -1;
	}
	else
	{
		balls.print();
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	ZUMA();

	return 0;
}