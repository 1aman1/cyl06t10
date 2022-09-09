#include <iostream>
#include <algorithm>
#include <math.h>

constexpr int ERR_VAL = -99999;

/*
1. find height of subtrees

2. if they differ by > 1, then it is not a Balanced Tree
*/

struct node
{
    int datum;
    node *left;
    node *right;
    
    node(int newdata) : datum(newdata),
                        left(nullptr),
                        right(nullptr) {}
};

/*
method 1
uses maxDepth, isBalanced

O(N * log(N))
*/

int maxDepth(node *root)
{
    return root == NULL ? 0 : std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

bool isBalanced(node *root)
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

int checkHeight(node *root)
{
    if (root == nullptr)
        return -1;

    int leftHeight = checkHeight(root->left);
    if (leftHeight == ERR_VAL)
        return ERR_VAL;

    int rightHeight = checkHeight(root->right);
    if (rightHeight == ERR_VAL)
        return ERR_VAL;

    if (std::abs(leftHeight - rightHeight) > 1)
        return ERR_VAL;
    else
        return std::max(leftHeight, rightHeight) + 1;
}

bool isBalanced_2nd(node *root)
{
    return (checkHeight(root) != ERR_VAL);
}

int main()
{
    node *root = new node(1);
    root->left = new node(1);

    root->right = new node(1);
    // root->left->right = new node(1);

    // std::cout << "Is tree balanced ? " << std::boolalpha << isBalanced(root) << std::endl;
    std::cout << "Is tree balanced ? " << std::boolalpha << isBalanced_2nd(root) << std::endl;

    return 0;
}