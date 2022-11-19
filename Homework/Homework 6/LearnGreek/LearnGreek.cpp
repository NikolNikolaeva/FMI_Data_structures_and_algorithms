
#include <iostream>
#include <vector>
using namespace std;


struct Node {
	std::string value;
	Node* right = nullptr;
	Node* left = nullptr;

	Node(std::string value)
	{
		this->value = value;
		right = nullptr;
		left = nullptr;
	}
};

class BinarySearchTree {
private:
	Node* root;

	Node* insert(string element, Node* node) {
		if (node == nullptr) {
			node = new Node(element);
		}
		else if (element < node->value) {
			node->left = this->insert(element, node->left);
		}
		else if (element > node->value) {
			node->right = this->insert(element, node->right);
		}

		return node;
	}

	void preOrderCopy(Node* node) {
		if (node == nullptr) {
			return;
		}

		this->insert(node->value);
		this->preOrderCopy(node->left);
		this->preOrderCopy(node->right);
	}

	BinarySearchTree(Node* node) {
		this->preOrderCopy(node);
	}

public:
	BinarySearchTree() {
		this->root = nullptr;
	}

	void insert(string element) {
		this->root = insert(element, this->root);
	}


	Node* findElement(string& element) {
		Node* current = this->root;

		while (current != nullptr) {
			if (current->value > element) {
				current = current->left;
			}
			else if (current->value < element) {
				current = current->right;
			}
			else {
				break;
			}
		}

		return current;
	}
};


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	BinarySearchTree bst;

	long long N, Q;
	
	cin >> N;
	for (long long i = 0; i < N; i++)
	{
		string value;
		std::cin >> value;
		bst.insert(value);
	}

	cin >> Q;
	for (long long i = 0; i < Q; i++)
	{
		string word;
		std::cin >> word;
		if (bst.findElement(word) == nullptr)
			cout << "NO\n";
		else
			cout << "YES\n";
	}

	return 0;
}
