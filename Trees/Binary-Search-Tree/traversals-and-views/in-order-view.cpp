#include <iostream>
#include <queue>
#include <list>

struct node_t
{
    int data;
    node_t *left;
    node_t *right;

    node_t() = delete;

    node_t(int newData) : data(newData),
                          left(nullptr),
                          right(nullptr) {}
};

class Tree
{
public:
    Tree();

    void
    insert(int);

protected:
    node_t *root;

    virtual node_t *
    _insertUtil(node_t *, int);
};

Tree::Tree() : root(nullptr) {}

void Tree::insert(int newData)
{
    root = _insertUtil(root, newData);
}

node_t *Tree::_insertUtil(node_t *curr_ptr, int newData)
{
    if (!curr_ptr)
        return new node_t(newData);

    if (newData < curr_ptr->data)
        curr_ptr->left = _insertUtil(curr_ptr->left, newData);

    else
        curr_ptr->right = _insertUtil(curr_ptr->right, newData);

    return curr_ptr;
}

class Views : public Tree
{
private:
    void _inOrderView(node_t *);

public:
    void inOrderView();
};

void Views::inOrderView()
{
    _inOrderView(root);
}

void Views::_inOrderView(node_t *curr_ptr)
{
    if (!curr_ptr)
    {
        return;
    }

    _inOrderView(curr_ptr->left);

    std::cout << curr_ptr->data << "\t";

    _inOrderView(curr_ptr->right);
}

int main()
{
    std::cout << "Building " << __FILE__ << std::endl;

    Views *tobj = new Views();

    tobj->insert(7);
    tobj->insert(5);
    tobj->insert(3);
    tobj->insert(9);
    tobj->insert(11);

    tobj->inOrderView();

    return 0;
}
