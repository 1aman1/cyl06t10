#include <iostream>
#include <list>

struct node
{
    int data;
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
    typedef std::list<node *> list;

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

// left view =========================

class View_utility : public Tree
{

public:
    void
    view(bool left = false, bool right = false);

private:
    std::string side;
};

void View_utility::view(bool left, bool right)
{
    list parent = {_root};
    list current;

    left == true ? side = "left" : side = "right";

    std::cout << side << " view : ";

    while (!parent.empty())
    {
        side == "left" ? std::cout << parent.front()->data << "\n"
                       : std::cout << parent.back()->data << "\n";

        for (auto itr = parent.begin(); itr != parent.end(); ++itr)
        {
            if ((*itr)->left)
                current.push_back((*itr)->left);
            if ((*itr)->right)
                current.push_back((*itr)->right);
        }

        parent.swap(current);
        current.clear();
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

    obj.view(true, false);
    obj.view(false, true);

    return 0;
}