#include <iostream>

struct tree_node
{
    int node_data;
    tree_node *left;
    tree_node *right;
    tree_node(int newdata) : node_data(newdata),
                             left(nullptr),
                             right(nullptr) {}
};

class tree
{
public:
    tree_node *root;
    tree();
    tree_node *insert(int, tree_node *);
};

tree::tree()
{
    root = nullptr;
}

tree_node *tree::insert(int newdata, tree_node *ptr)
{
    if (!ptr)
    {
        return new tree_node(newdata);
    }

    if (newdata < ptr->node_data)
    {
        ptr->left = insert(newdata, ptr->left);
    }

    else //(newdata > ptr->node_data)
    {
        ptr->right = insert(newdata, ptr->right);
    }

    return ptr;
}

int main()
{
    tree obj;

    obj.root = obj.insert(2, obj.root);
    obj.root = obj.insert(1, obj.root);
    obj.root = obj.insert(3, obj.root);

    std::cout << obj.root->node_data << std::endl;
    std::cout << obj.root->left->node_data << std::endl;
    std::cout << obj.root->right->node_data << std::endl;

    return 0;
}