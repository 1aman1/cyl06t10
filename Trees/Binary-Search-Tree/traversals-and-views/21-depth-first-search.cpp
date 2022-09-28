#include <iostream>
#include <stack>

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

//______SOLUTION_______//

class Views : public Tree
{
public:
    void depth_first_search_iterative();

    // TODO
    // depth_first_search_recursive
};

void Views::depth_first_search_iterative()
{
    if (root == nullptr)
        return;

    std::stack<node_t *> stack;

    stack.push(root);

    while (!stack.empty())
    {
        node_t *tmp = stack.top();
        stack.pop();

        std::cout << tmp->data << " ";

        if (tmp->right)
            stack.push(tmp->right);
        if (tmp->left)
            stack.push(tmp->left);
    }

    std::cout << "\n";
}

int main()
{
    std::cout << "Building " << __FILE__ << std::endl;

    Views *tobj = new Views();

    tobj->insert(7);
    tobj->insert(3);
    tobj->insert(5);
    tobj->insert(1);
    tobj->insert(9);
    tobj->insert(10);
    tobj->insert(11);

    tobj->depth_first_search_iterative();

    return 0;
}
