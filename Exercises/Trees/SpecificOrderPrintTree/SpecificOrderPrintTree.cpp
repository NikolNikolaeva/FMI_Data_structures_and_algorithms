#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int value;
    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void printSFB() {

        deque<Node*> tree;
        long long level = 0;
        tree.push_front(root);

        if (root == nullptr)
            return;

        while (tree.size() != 0)
        {
            long long size = tree.size();

            if (level % 2 == 0)
            {
                for (int i = 0; i < size; i++)
                    printf("%d ", tree[i]->value);
            }
            else {
                for (int i = size - 1; i >= 0; i--)
                    printf("%d ", tree[i]->value);
            }

            for (int i = 0; i < size; i++) {
                if (tree.front()->left != nullptr)
                    tree.push_back(tree.front()->left);
                if (tree.front()->right != nullptr)
                    tree.push_back(tree.front()->right);

                tree.pop_front();
            }
            level += 1;
        }
    }

private:



    Node* root;

    Node* insert(Node* curNode, int value) {
        if (curNode == NULL) {
            curNode = new Node(value);
        }
        else if (curNode->value < value) {
            curNode->right = insert(curNode->right, value);
        }
        else if (curNode->value > value) {
            curNode->left = insert(curNode->left, value);
        }
        else {
            //if we already have this value at the tree - do nothing
        }
        return curNode;
    }
};

int main() {
    int n;
    cin >> n;
    int value;
    BST tree;
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }

    tree.printSFB();
    return 0;
}