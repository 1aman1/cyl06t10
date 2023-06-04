#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

bool checkUtil(struct Node *root,
               int level, int *leafLevel)
{
    if (root == nullptr)
        return true;

    if (root->left == nullptr && root->right == nullptr)
    {
        if (*leafLevel == 0)
        {
            *leafLevel = level; // Set first found leaf's level
            return true;
        }
        return (level == *leafLevel);
    }

    return checkUtil(root->left, level + 1, leafLevel) &&
           checkUtil(root->right, level + 1, leafLevel);
}

bool check(struct Node *root)
{
    int level = 0, leafLevel = 0;
    return checkUtil(root, level, &leafLevel);
}

int main()
{

    Node *root = new Node(1);

    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right = new Node(3);
    root->right->left = new Node(15);
    root->right->right = new Node(15);
    // root->right->right->right = new Node(14);

    int result = check(root);
    if (result)
        cout << "All leaf nodes are at same level\n";
    else
        cout << "Leaf nodes not at same level\n";

    std::cout << "\n";

    return 0;
}