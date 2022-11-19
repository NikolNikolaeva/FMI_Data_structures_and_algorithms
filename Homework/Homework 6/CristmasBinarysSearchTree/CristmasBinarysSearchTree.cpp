
#include <iostream>
#include <vector>

struct Node
{
	long long value = 0;

	Node* left = nullptr;
	Node* right = nullptr;

	Node() = default;

	Node(long long value)
	{
		this->value = value;
		this->left = nullptr;
		this->right = nullptr;
	}
};

void InOrder(Node*& node, std::vector<long long>& arr)
{
	if (node == nullptr) {
		return;
	}

	InOrder(node->left, arr);
	arr.push_back(node->value);
	InOrder(node->right, arr);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	long long T;
	std::cin >> T;

	for (long long i = 0; i < T; i++)
	{
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
			}
			if (rightIndex != -1)
			{
				tree[i]->right = tree[rightIndex];
			}
		}

		std::vector<long long> arr;
		InOrder(tree[0], arr);

		bool same = true;
		for (long long i = 0; i < N-1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				same = false;
				break;
			}
		}
		
		same ? std::cout << 1<<'\n' : std::cout << 0<<'\n';
	}

	return 0;
}
