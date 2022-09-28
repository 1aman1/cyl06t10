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

//______SOLUTION_______//

class Solution : public Tree
{
    int tree_value_recursive(node_t *);

public:
    int tree_value_recursive();

    int tree_value_iterative();
};

int Solution::tree_value_iterative()
{
    if (root == nullptr)
        return 0;

    std::queue<node_t *> queue;
    int Sum = root->data;

    queue.push(root);

    while (!queue.empty())
    {
        node_t *tmp = queue.front();
        queue.pop();

        if (tmp->left)
        {
            Sum += tmp->left->data;
            queue.push(tmp->left);
        }
        if (tmp->right)
        {
            Sum += tmp->right->data;
            queue.push(tmp->right);
        }
    }

    return Sum;
}

int Solution::tree_value_recursive()
{
    return tree_value_recursive(root);
}

int Solution::tree_value_recursive(node_t *curr_node)
{
    if (curr_node == nullptr)
        return 0;

    return (curr_node->data +
            tree_value_recursive(curr_node->left) +
            tree_value_recursive(curr_node->right));
}

int main()
{
    std::cout << "Building " << __FILE__ << std::endl;

    Solution *tobj = new Solution();

    tobj->insert(7);
    tobj->insert(3);
    tobj->insert(10);
    tobj->insert(80);
    tobj->insert(100);

    std::cout << tobj->tree_value_recursive() << "\n";
    std::cout << tobj->tree_value_iterative() << "\n";

    return 0;
}
