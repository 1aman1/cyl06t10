#include <iostream>
#include <algorithm>
#include <math.h>

#define ERR_VALUE -99999

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

/*
method 1
uses maxDepth, isBalanced

O(N * log(N))
*/

int maxDepth(tree_node *root)
{
    return root == NULL ? 0 : std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

bool isBalanced(tree_node *root)
{
    if (!root)
        return true;

    if (abs(maxDepth(root->left) - maxDepth(root->right)) <= 1)
        return isBalanced(root->left) && isBalanced(root->right);
    else
        return false;
}

/*
method 2
uses checkHeight, isBalanced_2nd

relatively efficient
O(N)

*/

int checkHeight(tree_node *root)
{
    if (root == nullptr)
        return -1;

    int leftHeight = checkHeight(root->left);
    if (leftHeight == ERR_VALUE)
        return ERR_VALUE;

    int rightHeight = checkHeight(root->right);
    if (rightHeight == ERR_VALUE)
        return ERR_VALUE;

    int heightDifference = leftHeight - rightHeight;
    if (std::abs(heightDifference) > 1)
        return ERR_VALUE;
    else
    {
        return std::max(leftHeight, rightHeight) + 1;
    }
}

bool isBalanced_2nd(tree_node *root)
{
    return (checkHeight(root) != ERR_VALUE);
}

int main()
{
    tree_node *root = new tree_node(4);
    root->left = new tree_node(4);
    // root->left->right = new tree_node(4); // unbalancing node
    root->left->left = new tree_node(4);
    root->left->left->right = new tree_node(4);

    root->right = new tree_node(1);
    root->right->left = new tree_node(1);
    root->right->right = new tree_node(1);

    // std::cout << "Is tree balanced ?" << std::boolalpha << isBalanced(root) << std::endl;
    std::cout << "Is tree balanced ?" << std::boolalpha << isBalanced_2nd(root) << std::endl;

    return 0;
}