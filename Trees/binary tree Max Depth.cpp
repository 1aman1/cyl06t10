#include <iostream>
#include <algorithm>
#include <math.h>

/*
1. find height of subtrees

2. if they differ by > 1
not a BST,

*/

struct tree_node
{
    int node_data;
    tree_node *left;
    tree_node *right;
    tree_node(int newdata) : node_data(newdata),
                             left(nullptr),
                             right(nullptr) {}
};

int maxDepth(tree_node *root)
{
    return root == NULL ? 0 : std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main()
{
    tree_node *root = new tree_node(4);
    root->left = new tree_node(4);
    root->left->left = new tree_node(4);
    root->left->left->right = new tree_node(4);

    root->right = new tree_node(1);
    root->right->left = new tree_node(1);
    root->right->right = new tree_node(1);

    std::cout << "max depth : " << maxDepth(root) << std::endl;

    return 0;
}