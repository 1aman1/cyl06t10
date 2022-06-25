#include <iostream>
#include <queue>
#include <list>

/*
node has data, left child, right child.
*/

struct node_t
{
    int node_data;
    node_t *left;
    node_t *right;
    node_t(int newdata) : node_data(newdata),
                          left(nullptr),
                          right(nullptr) {}
};

class BSTree_t
{
public:
    node_t *root;
    BSTree_t();

public:
    node_t *insert(int, node_t *);
    node_t *remove(int, node_t *);

    // utility
    node_t *findSmallest(node_t *);

    // view
    void DepthView(node_t *);
    std::list<std::list<node_t *>> DepthViewUtility(node_t *);
};

BSTree_t::BSTree_t()
{
    root = nullptr;
}

node_t *BSTree_t::findSmallest(node_t *currPtr)
{ // takes a left pointer for any node, to traverse down the left subtree recursively

    while (currPtr && currPtr->left) // validation for currPtr deals with nullptr also
        currPtr = currPtr->left;

    return currPtr;
}

node_t *BSTree_t::insert(int newdata, node_t *ptr)
{
    if (!ptr) // no node present, create a new and return
    {
        return new node_t(newdata);
    }

    // go to left subtree
    if (newdata < ptr->node_data)
    {
        ptr->left = insert(newdata, ptr->left);
    }

    else //(newdata > ptr->node_data) // go to right subtree
    {
        ptr->right = insert(newdata, ptr->right);
    }

    return ptr;
}

node_t *BSTree_t::remove(int item, node_t *currPtr)
{
    // if currPtr is null
    if (currPtr == nullptr)
        return currPtr;

    // if delete node has less than current node's value, go left
    else if (item < currPtr->node_data)
        currPtr->left = remove(item, currPtr->left);

    // if  delete node has greater than current node's value, go right
    else if (item > currPtr->node_data)
        currPtr->right = remove(item, currPtr->right);

    // if no condition matches, then
    // it is the currPtr that has to be deleted
    else
    {
        // a leaf node
        if (currPtr->left == nullptr && currPtr->right == nullptr)
        {
            delete currPtr;
            return nullptr;
        }

        // node with a left subtree
        else if (currPtr->left != nullptr && currPtr->right == nullptr)
        {
            node_t *ptrToLeftSubtree = currPtr->left;
            delete currPtr;
            return ptrToLeftSubtree;
        }

        // node with a right subtree
        else if (currPtr->left == nullptr && currPtr->right != nullptr)
        {
            node_t *ptrToRightSubtree = currPtr->right;
            delete currPtr;
            return ptrToRightSubtree;
        }

        // node with left subtree and right subtree
        else
        {
            // finMin in right subtree
            node_t *minNode = findSmallest(currPtr->right);

            // copy its data
            currPtr->node_data = minNode->node_data;

            // lastly call minNode deletion in its subtree
            currPtr->right = remove(minNode->node_data, currPtr->right);
        }
    }
    return currPtr;
}

void BSTree_t::DepthView(node_t *currPtr)
{
    // call utility that creates a list
    std::list<std::list<node_t *>> depthViewList = DepthViewUtility(currPtr);

    // then print the list
    for (std::list<std::list<node_t *>>::iterator itr = depthViewList.begin(); itr != depthViewList.end(); ++itr)
    {
        for (std::list<node_t *>::iterator nestItr = (*itr).begin(); nestItr != (*itr).end(); ++nestItr)
        {
            std::cout << (*nestItr)->node_data << " ";
        }
        std::cout << std::endl;
    }
}

std::list<std::list<node_t *>> BSTree_t::DepthViewUtility(node_t *root)
{
    // create a new list of parent and current that
    std::list<std::list<node_t *>> DepthViewList;

    // utility list to stash level nodes and then push into
    // DepthViewList before moving to next level
    std::list<node_t *> current;
    current.push_back(root);

    while (!current.empty())
    {
        DepthViewList.push_back(current);
        std::list<node_t *> parent = current;
        current.resize(0);

        for (std::list<node_t *>::iterator itr = parent.begin(); itr != parent.end(); ++itr)
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

int main()
{
    std::cout << __FILE__ << std::endl;

    BSTree_t obj;

    obj.root = obj.insert(5, obj.root);
    obj.root = obj.insert(3, obj.root);
    obj.root = obj.insert(7, obj.root);
    obj.root = obj.insert(4, obj.root);
    obj.root = obj.insert(6, obj.root);
    obj.root = obj.insert(2, obj.root);
    obj.root = obj.insert(8, obj.root);

    std::cout << std::endl;
    obj.DepthView(obj.root);
    std::cout << std::endl;

    obj.root = obj.remove(7, obj.root);

    std::cout << std::endl;
    obj.DepthView(obj.root);
    std::cout << std::endl;

    return 0;
}