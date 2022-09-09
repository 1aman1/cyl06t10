#include <iostream>
#include <map>
#include <queue>

// 

struct node
{
    int data;
    int h_dist = 0;
    node *left, *right;

    node() = delete;

    node(int v) : data(v),
                  left(nullptr),
                  right(nullptr){};
};

class Tree
{
protected:
    node *_root;

public:
    Tree() : _root(nullptr){};

public:
    void
    view_in_order();

    void
    insert(int newData);

private:
    void
    _in_order(node *);

    node *
    _insertUtility(node *, int newData);
};

void Tree::view_in_order()
{
    _in_order(_root);
}

void Tree::_in_order(node *curr_node)
{
    if (curr_node)
    {
        _in_order(curr_node->left);
        std::cout << curr_node->data << " : ";
        _in_order(curr_node->right);
    }
}

void Tree::insert(int newData)
{
    _root = _insertUtility(_root, newData);
}

node *
Tree::_insertUtility(node *curr_node, int newData)
{
    if (curr_node == nullptr)
        return new node(newData);

    else if (newData < curr_node->data)
        curr_node->left = _insertUtility(curr_node->left, newData);
    else
        curr_node->right = _insertUtility(curr_node->right, newData);

    return curr_node;
}

class View_utility : public Tree
{

public:
    void topview();

private:
};

void View_utility::topview()
{
    if (!_root)
        return;

    node *curr_node = _root;

    int h_dist = 0;
    curr_node->h_dist = 0;

    std::map<int, int> map;
    std::queue<node *> queue;

    queue.push(curr_node);
    while (!queue.empty())
    {
        h_dist = curr_node->h_dist;

        if (!map.count(h_dist))
            map[h_dist] = curr_node->data;

        if (curr_node->left)
        {
            curr_node->left->h_dist = h_dist - 1;
            queue.push(curr_node->left);
        }

        if (curr_node->right)
        {
            curr_node->right->h_dist = h_dist + 1;
            queue.push(curr_node->right);
        }

        queue.pop();
        curr_node = queue.front();
    }

    for (auto &i : map)
    {
        // std::cout << i.first << " : ";
        std::cout << i.second << "\n";
    }
}

int main()
{

    View_utility obj;

    // CASE - 1
    // obj.insert(15);
    // obj.insert(5);
    // obj.insert(1);
    // obj.insert(10);
    // obj.insert(14);

    // CASE -2
    obj.insert(1000);
    obj.insert(500);
    obj.insert(700);
    obj.insert(300);
    obj.insert(400);
    obj.insert(360);
    obj.insert(330);
    obj.insert(2000);
    obj.insert(3000);
    obj.insert(2500);
    obj.insert(2700);

    // obj.view_in_order();
    obj.topview();

    return 0;
}
