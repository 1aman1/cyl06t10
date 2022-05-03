#include <iostream>

#define DEBUG false

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
    void inOrder(tree_node *);
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

void insertInSeq(tree &treeObj, int arr[], int left, int right)
{
    if (right >= left)
    {
        int mid = (right - left) / 2 + left;
        std::cout << arr[mid] << std::endl;
        treeObj.root = treeObj.insert(arr[mid], treeObj.root);

        insertInSeq(treeObj, arr, left, mid - 1);
        insertInSeq(treeObj, arr, mid + 1, right);
    }
    return;
}

void tree::inOrder(tree_node *ptr)
{
    if (!ptr)
        return;

    inOrder(ptr->left);
    std::cout << ptr->node_data << std::endl;
    inOrder(ptr->right);
}

int main()
{
    tree treeObj;
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};

    insertInSeq(treeObj, arr, 0, 6);
    treeObj.inOrder(treeObj.root);

    return 0;
}