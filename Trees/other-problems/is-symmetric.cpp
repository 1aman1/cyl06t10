#include <iostream>

struct node
{
    int data;
    struct node *left;
    struct node *right;

    node(int data) : data(data), left(nullptr), right(nullptr) {}
};

void inOrder(node *curr_node)
{
    if (curr_node)
    {
        inOrder(curr_node->left);
        std::cout << curr_node->data << " ";
        inOrder(curr_node->right);
    }
}

bool are_symmetric(node *lht, node *rht)
{
    if (lht == nullptr && rht == nullptr)
        return true;

    if (!(lht && rht && lht->data == rht->data))
        return false;

    return are_symmetric(lht->left, rht->right) &&
           are_symmetric(lht->right, rht->left);
}

bool is_symmetric(node *tree)
{
    if (tree == nullptr)
        return true;
    return are_symmetric(tree->left, tree->right);
}

int main()
{
    // 1

    node *root_1 = new node(1);

    root_1->left = new node(2);
    root_1->right = new node(3);

    root_1->left->left = new node(4);
    root_1->left->right = new node(5);

    // 2
    node *root_2 = new node(1);

    root_2->right = new node(2);
    root_2->left = new node(3);

    root_2->right->left = new node(5);
    root_2->right->right = new node(4);

    // Main Root
    node *Tree = new node(0);

    Tree->left = root_1;
    Tree->right = root_2;

    inOrder(Tree);

    std::cout << std::boolalpha
              << "\n"
              << is_symmetric(Tree);

    std::cout << "\n";

    return 0;
}