
#include <iostream>
#include <vector>

struct Node
{
	long long value = 0;

	Node* left = nullptr;
	Node* right = nullptr;

	long long  index = 0;

	Node() = default;

	Node(long long value)
	{
		this->value = value;
		this->left = nullptr;
		this->right = nullptr;
		this->index = 0;
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	long long N;
	std::cin >> N;

	std::vector<Node*> tree(N);

	for (long long i = 0; i < N; i++)
	{
		tree[i] = new Node();
	}

	for (long long i = 0; i < N; i++)
	{
		long long  value, leftIndex, rightIndex;
		std::cin >> value >> leftIndex >> rightIndex;

		tree[i]->value = value;
		if (leftIndex != -1)
		{
			tree[i]->left = tree[leftIndex];
			tree[leftIndex]->index = tree[i]->index - 1;
		}
		if (rightIndex != -1)
		{
			tree[i]->right = tree[rightIndex];
			tree[rightIndex]->index = tree[i]->index + 1;
		}
	}

	std::vector<long long > sumColumns(N + 1, 0);

	for (long long i = 0; i < N; i++)
	{
		sumColumns[tree[i]->index + N / 2] += tree[i]->value;
	}

	for (long long i = 0; i < N; i++)
	{
		if (sumColumns[i] != 0)
			std::cout << sumColumns[i] << " ";
	}

	return 0;
}
