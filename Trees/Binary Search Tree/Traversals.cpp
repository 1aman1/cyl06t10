#include <iostream>
#include <list>
#include <queue>

/*
node has data, left child, right child.
*/

struct tree_node
{
    int node_data;
    tree_node *left;
    tree_node *right;
    tree_node(int newdata) : node_data(newdata),
                             left(nullptr),
                             right(nullptr) {}
};

class tree
{
public:
    tree();
    tree_node *root;

    tree_node *insert(int, tree_node *);

    void inOrderView(tree_node *);
    void preOrderView(tree_node *);
    void postOrderView(tree_node *);
    void levelListView(tree_node *);

    void DepthView(tree_node *);
    std::list<std::list<tree_node *>> DepthViewUtility(tree_node *);
};

void tree::DepthView(tree_node *currPtr)
{
    // call utility that creates a list
    std::list<std::list<tree_node *>> depthViewList = DepthViewUtility(currPtr);

    // then print the list
    for (std::list<std::list<tree_node *>>::iterator itr = depthViewList.begin(); itr != depthViewList.end(); ++itr)
    {
        for (std::list<tree_node *>::iterator nestItr = (*itr).begin(); nestItr != (*itr).end(); ++nestItr)
        {
            std::cout << (*nestItr)->node_data << " ";
        }
        std::cout << std::endl;
    }
}

std::list<std::list<tree_node *>> tree::DepthViewUtility(tree_node *root)
{
    // create a new list of parent and current that
    std::list<std::list<tree_node *>> DepthViewList;

    // utility list to stash level nodes and then push into
    // DepthViewList before moving to next level
    std::list<tree_node *> current;
    current.push_back(root);

    while (!current.empty())
    {
        DepthViewList.push_back(current);
        std::list<tree_node *> parent = current;
        current.resize(0);

        for (std::list<tree_node *>::iterator itr = parent.begin(); itr != parent.end(); ++itr)
        {
            if ((*itr)->left)
            {
                current.push_back((*itr)->left);
            }
            if ((*itr)->right)
            {
                current.push_back((*itr)->right);
            }
        }
    }
    return DepthViewList;
}

tree::tree()
{
    root = nullptr;
}

tree_node *tree::insert(int newdata, tree_node *ptr)
{
    if (!ptr)
    {
        return new tree_node(newdata);
    }

    if (newdata < ptr->node_data)
    {
        ptr->left = insert(newdata, ptr->left);
    }

    else //(newdata > ptr->node_data)
    {
        ptr->right = insert(newdata, ptr->right);
    }

    return ptr;
}

void tree::inOrderView(tree_node *currPtr)
{
    if (!currPtr)
    {
        return;
    }

    inOrderView(currPtr->left);

    std::cout << currPtr->node_data << "\t";

    inOrderView(currPtr->right);
}

void tree::preOrderView(tree_node *currPtr)
{
    if (!currPtr)
    {
        return;
    }
    std::cout << currPtr->node_data << "\t";

    preOrderView(currPtr->left);
    preOrderView(currPtr->right);
}

void tree::postOrderView(tree_node *currPtr)
{
    if (!currPtr)
    {
        return;
    }

    postOrderView(currPtr->left);
    postOrderView(currPtr->right);

    std::cout << currPtr->node_data << "\t";
}

void tree::levelListView(tree_node *root)
{
    std::queue<tree_node *> myQueue;

    tree_node *currPtr = root;
    myQueue.push(currPtr);

    while (!myQueue.empty())
    {
        currPtr = myQueue.front();
        myQueue.pop();

        std::cout << currPtr->node_data << "\t";
        if (currPtr->left)
        {
            myQueue.push(currPtr->left);
        }
        if (currPtr->right)
        {
            myQueue.push(currPtr->right);
        }
    }

    // empty the queue
    std::queue<tree_node *> emptyQ;
    myQueue.swap(emptyQ);
}

int main()
{

    std::cout << __FILE__ << std::endl;

    tree obj;

    obj.root = obj.insert(5, obj.root);
    obj.root = obj.insert(3, obj.root);
    obj.root = obj.insert(7, obj.root);
    obj.root = obj.insert(4, obj.root);
    obj.root = obj.insert(6, obj.root);
    obj.root = obj.insert(2, obj.root);
    obj.root = obj.insert(8, obj.root);

    std::cout << "preOrderView" << std::endl;
    obj.preOrderView(obj.root);
    std::cout << std::endl;

    std::cout << "inOrderView" << std::endl;
    obj.inOrderView(obj.root);
    std::cout << std::endl;

    std::cout << "postOrderView" << std::endl;
    obj.postOrderView(obj.root);
    std::cout << std::endl;

    std::cout << "levelListView" << std::endl;
    obj.levelListView(obj.root);
    std::cout << std::endl;

    std::cout << "DepthView" << std::endl;
    obj.DepthView(obj.root);
    std::cout << std::endl;

    return 0;
}