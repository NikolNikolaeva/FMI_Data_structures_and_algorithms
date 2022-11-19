
#include <iostream>
#include <vector>

struct Node
{
	long long value;
	Node* parent = nullptr;

	Node(long long value)
	{
		this->value = value;
		this->parent = nullptr;
	}
};

bool isChild(Node* parent, Node* child)
{
	if (parent == nullptr)
		return false;
	while (child != nullptr)
	{
		if (child->value < parent->value)
			return false;
		if (parent->value == child->value)
			return true;
		child = child->parent;
	}
	return false;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	long long N;
	std::cin >> N;

	std::vector<Node*> tree(N);
	for (long long i = 0; i < N; i++)
	{
		tree[i] = new Node(i);
	}

	for (long long i = 0; i < N - 1; i++)
	{
		long long parent, child;
		std::cin >> parent >> child;
		tree[child]->parent = tree[parent];
	}

	long long Q;
	std::cin >> Q;

	for (long long i = 0; i < Q; i++)
	{
		long long parent, child;
		std::cin >> parent >> child;
		bool found = isChild(tree[parent],tree[child]);
		found ? std::cout << "YES\n" : std::cout << "NO\n";
	}

	return 0;
}

