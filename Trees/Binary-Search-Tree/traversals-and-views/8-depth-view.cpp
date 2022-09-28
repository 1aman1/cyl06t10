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

//______SOLUTION_______//

class View_utility : public Tree
{
public:
    typedef std::list<node *> slist;
    typedef std::list<std::list<node *>> adj_list;

public:
    void
    DepthView();

private:
    adj_list _DepthViewUtility(node *root);
};

void View_utility::DepthView()
{
    // call utility that creates a list
    adj_list depthViewList = _DepthViewUtility(_root);

    // then print the list
    for (auto itr = depthViewList.begin(); itr != depthViewList.end(); ++itr)
    {
        for (auto nestItr = (*itr).begin(); nestItr != (*itr).end(); ++nestItr)
        {
            std::cout << (*nestItr)->data << " ";
        }
        std::cout << std::endl;
    }
}

View_utility::adj_list
View_utility::_DepthViewUtility(node *curr_ptr)
{
    // create a new list of parent and current that
    adj_list DepthViewList;

    // utility list to stash level nodes and then push into
    // DepthViewList before moving to next level
    slist current;
    current.push_back(curr_ptr);

    while (!current.empty())
    {
        DepthViewList.push_back(current);
        slist parent = current;
        current.resize(0);

        for (auto itr = parent.begin(); itr != parent.end(); ++itr)
        {
            if ((*itr)->left != nullptr)
            {
                current.push_back((*itr)->left);
            }

            // if empty nodes are also needed to display

            // if ((*itr)->left == nullptr && (*itr)->right != nullptr)
            // {
            //     current.push_back(new node(-1));
            // }

            if ((*itr)->right)
            {
                current.push_back((*itr)->right);
            }

            // if ((*itr)->left != nullptr && (*itr)->right == nullptr)
            // {
            //     current.push_back(new node(-1));
            // }
        }
    }
    return DepthViewList;
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

    obj.DepthView();

    return 0;
}