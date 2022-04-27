#include <iostream>
#include <algorithm>
#include<math.h>

#define DEBUG false

// WIP

/*
1. find height of subtrees

2. if they differ by > 1
not a BST,

*/
struct t_Node
{
    int node_data;
    t_Node* left;
    t_Node* right;
    t_Node(int newdata) : node_data(newdata), left(nullptr), right(nullptr) {}
};

int maxDepth(t_Node* root)
{
    return root == NULL ? 0 :std:: max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

bool isBalanced(t_Node* root)
{
    if (!root)
        return true;

    return isBalanced(root->left) && isBalanced(root->right) && (abs(maxDepth(root->left) - maxDepth(root->right)) >= 1);
}

int main()
{
    t_Node* testroot1 = new t_Node(4);
    testroot1->left = new t_Node(4);
    testroot1->left->left = new t_Node(4);
    testroot1->left->left->right = new t_Node(4);

    testroot1->right = new t_Node(1);
    testroot1->right->left = new t_Node(1);
    testroot1->right->right = new t_Node(1);

    // std::cout << testroot1->node_data << std::endl;
    // std::cout << testroot1->left->node_data << std::endl;
    // std::cout << testroot1->left->left->node_data << std::endl;

    std::cout << maxDepth(testroot1) << std::endl;

    /*
        t_Node *testroot2 = new t_Node(1);
        testroot2->left = new t_Node(2);
        testroot2->left->left = new t_Node(3);

        std::cout << testroot2->node_data << std::endl;
        std::cout << testroot2->left->node_data << std::endl;
        std::cout << testroot2->left->left->node_data << std::endl;

        t_Node *testroot3 = new t_Node(1);
        testroot3->left = new t_Node(2);
        testroot3->left->left = new t_Node(3);

        std::cout << testroot3->node_data << std::endl;
        std::cout << testroot3->left->node_data << std::endl;
        std::cout << testroot3->left->left->node_data << std::endl;

    */
    return 0;
}