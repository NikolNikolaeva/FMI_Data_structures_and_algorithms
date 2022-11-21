#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* leftNode;
    Node* rightNode;
    Node(int d) {
        data = d;
        leftNode = NULL;
        rightNode = NULL;
    }
};

class Solution {
private:
    long long sumLeaves(long long& sum, Node* curr)
    {
        if (curr != nullptr)
        {
            if (curr->leftNode == nullptr && curr->rightNode == nullptr && curr->data % 2 != 0)
                sum += curr->data;

            sumLeaves(sum, curr->leftNode);
            sumLeaves(sum, curr->rightNode);
        }

        return sum;
    }
public:
    Node* insert(Node* root, int data) {
        if (root == NULL) {
            return new Node(data);
        }
        else {
            Node* cur;
            if (data <= root->data) {
                cur = insert(root->leftNode, data);
                root->leftNode = cur;
            }
            else {
                cur = insert(root->rightNode, data);
                root->rightNode = cur;
            }

            return root;
        }
    }


    void leaves(Node* root) {
        long long sum = 0;
        sum = sumLeaves(sum, root);
        cout << sum;
    }


}; //End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.leaves(root);
    return 0;
}