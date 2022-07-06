#include <iostream>
#include <list>
#define DEBUG false
/*
node has data, left child, right child & parent ptr too.
*/

struct tree_node
{
    int node_data;

    tree_node *left;
    tree_node *right;

    tree_node *parent;

    tree_node(int newdata) : node_data(newdata),
                             left(nullptr),
                             right(nullptr),
                             parent(nullptr) {}
};

class tree
{
public:
    tree_node *root;

    tree() : root(nullptr){};

    tree_node *insert(int, tree_node *);

    tree_node *successor(tree_node *);
    tree_node *findSmallest(tree_node *currPtr);

    // view
    void DepthView(tree_node *);
    std::list<std::list<tree_node *>> DepthViewUtility(tree_node *);
};

tree_node *tree::insert(int newdata, tree_node *ptr)
{
    if (!ptr)
    {
        return new tree_node(newdata);
    }
    // ptr here would be the parent of the newNode when put successfully
    // ptr can be assigned as the parent of newNode
    if (newdata < ptr->node_data)
    {

        tree_node *left_child_node = insert(newdata, ptr->left);
        ptr->left = left_child_node;

        left_child_node->parent = ptr;
    }

    else //(newdata > ptr->node_data)
    {
        tree_node *right_child_node = insert(newdata, ptr->right);
        ptr->right = right_child_node;

        right_child_node->parent = ptr;
    }

    return ptr;
}

tree_node *tree::findSmallest(tree_node *currPtr)
{
    // validation for currPtr deals with nullptr also
    while (currPtr && currPtr->left)
        currPtr = currPtr->left;

    return currPtr;
}

void tree::DepthView(tree_node *currPtr)
{
    // call utility that creates a list
    std::list<std::list<tree_node *>> depthViewList = DepthViewUtility(currPtr);

    // then print the list
    for (std::list<std::list<tree_node *>>::iterator itr = depthViewList.begin(); itr != depthViewList.end(); ++itr)
    {
        for (std::list<tree_node *>::iterator nestItr = (*itr).begin(); nestItr != (*itr).end(); ++nestItr)
        {
            std::cout << (*nestItr)->node_data;
            if ((*nestItr)->parent != nullptr)
                std::cout << "^parent" << (*nestItr)->parent->node_data << " ";
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

tree_node *tree::successor(tree_node *Node)
{
    DEBUG == true ? std::cout << __LINE__ << "" << std::endl : std::cout << "";

    if (Node == nullptr)
        return Node;

    DEBUG == true ? std::cout << __LINE__ << "" << std::endl : std::cout << "";

    if (Node->right != nullptr)
        return findSmallest(Node->right);
    else
    {

        DEBUG == true ? std::cout << __LINE__ << " " << Node->node_data << " parent: " << Node->parent->node_data << std::endl : std::cout << "";

        tree_node *currPtr = Node;
        tree_node *parent_of_currPtr = currPtr->parent;

        DEBUG == true ? std::cout << __LINE__ << "" << std::endl : std::cout << "";

        while (parent_of_currPtr != nullptr && parent_of_currPtr->left != currPtr)
        {
            currPtr = parent_of_currPtr;
            parent_of_currPtr = parent_of_currPtr->parent;
        }

        DEBUG == true ? std::cout << __LINE__ << "" << std::endl : std::cout << "";

        return parent_of_currPtr;
    }
}

int main()
{

    std::cout << __FILE__ << std::endl;

    tree obj;

    obj.root = obj.insert(5, obj.root);
    obj.root = obj.insert(3, obj.root);
    obj.root = obj.insert(7, obj.root);
    obj.root = obj.insert(2, obj.root);
    obj.root = obj.insert(4, obj.root);
    obj.root = obj.insert(6, obj.root);
    obj.root = obj.insert(8, obj.root);

    std::cout << std::endl;
    obj.DepthView(obj.root);
    std::cout << std::endl;

    tree_node *result = obj.root->left;
    result = obj.successor(result);

    if (result != nullptr)
        std::cout << "Successor node value " << result->node_data << std::endl;
    else
        std::cout << "nullptr\n";

    return 0;
}