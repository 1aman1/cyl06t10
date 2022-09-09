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
    node_t *_root;

    virtual node_t *
    _insertUtil(node_t *, int);
};

Tree::Tree() : _root(nullptr) {}

void Tree::insert(int newData)
{
    _root = _insertUtil(_root, newData);
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
public:
    void level_list_view();
};

void Views::level_list_view()
{
    std::queue<node_t *> queue;

    node_t *tmp = _root;
    queue.push(tmp);

    while (!queue.empty())
    {
        tmp = queue.front();
        queue.pop();

        std::cout << tmp->data << "\t";

        if (tmp->left)
            queue.push(tmp->left);

        if (tmp->right)
            queue.push(tmp->right);
    }
    std::cout << std::endl;
    
    std::queue<node_t *> equeue;
    queue.swap(equeue);
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

    tobj->level_list_view();

    return 0;
}
