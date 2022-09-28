#include <iostream>
#include <stack>
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
    static constexpr int INFINITY = 9999999;

    int tree_min_recursive_util(node_t *);

public:
    int tree_min_recursive();

    int tree_min_iterative();
};

int Solution::tree_min_recursive_util(node_t *curr_node)
{
    if (root == nullptr)
        return INFINITY;

    int leftMin = INFINITY;
    int rightMin = INFINITY;

    if (curr_node->left)
        leftMin = tree_min_recursive_util(curr_node->left);
    if (curr_node->right)
        rightMin = tree_min_recursive_util(curr_node->right);

    return (std::min(leftMin,
                     std::min(curr_node->data, rightMin)));
}

int Solution::tree_min_recursive()
{
    return tree_min_recursive_util(root);
}

int Solution::tree_min_iterative()
{
    int Min = INFINITY;
    if (root != nullptr)
    {
        std::stack<node_t *> stack;

        stack.push(root);
        while (!stack.empty())
        {
            node_t *tmp = stack.top();
            stack.pop();

            Min = std::min(Min, tmp->data);

            if (tmp->right)
                stack.push(tmp->right);
            if (tmp->left)
                stack.push(tmp->left);
        }
    }
    return Min;
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

    std::cout << tobj->tree_min_iterative() << "\n";
    std::cout << tobj->tree_min_recursive() << "\n";

    return 0;
}
