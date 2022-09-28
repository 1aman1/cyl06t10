#include <iostream>
#include <queue>

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
    void breadth_first_search();
};

void Views::breadth_first_search()
{
    if (root == nullptr)
        return;

    std::queue<node_t *> queue;

    queue.push(root);

    while (!queue.empty())
    {
        node_t *tmp = queue.front();
        queue.pop();

        std::cout << tmp->data << " ";

        if (tmp->left)
            queue.push(tmp->left);
        if (tmp->right)
            queue.push(tmp->right);
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

    tobj->breadth_first_search();

    return 0;
}
