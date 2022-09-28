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
    static constexpr int INFINITY_NEG = -99999999;

    int max_root_to_leaf_sum(node_t *);

public:
    int max_root_to_leaf_sum();
};

int Solution::max_root_to_leaf_sum()
{
    return max_root_to_leaf_sum(root);
}

int Solution::max_root_to_leaf_sum(node_t *curr_node)
{
    if (curr_node == nullptr)
        return INFINITY_NEG;

    if (curr_node->left == nullptr && curr_node->right == nullptr)
        return curr_node->data;

    int leftMax = INFINITY_NEG;
    int rightMax = INFINITY_NEG;

    if (curr_node->left)
        leftMax = max_root_to_leaf_sum(curr_node->left);
    if (curr_node->right)
        rightMax = max_root_to_leaf_sum(curr_node->right);

    return std::max(leftMax, rightMax) + curr_node->data;
}

int main()
{
    std::cout << "Building " << __FILE__ << std::endl;

    Solution *tobj = new Solution();

    tobj->insert(7);
    tobj->insert(3);
    tobj->insert(20);
    tobj->insert(80);
    tobj->insert(100);

    std::cout << tobj->max_root_to_leaf_sum() << "\n";

    return 0;
}
