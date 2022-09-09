
#include <iostream>
#include <list>

struct node;

typedef std::list<std::list<node *>> adj_list_t;
typedef std::list<node *> list_t;

/*
node has data, left child, right child & parent ptr too.
*/

struct node
{
    int node_data;

    node *left;
    node *right;

    node *parent;

    node(int newdata) : node_data(newdata),
                        left(nullptr),
                        right(nullptr),
                        parent(nullptr) {}
};

class tree
{
public:
    node *root;

    tree() : root(nullptr){};

    node *insert(int, node *);

    node *successor(node *);
    node *findSmallest(node *currPtr);

    // view
    void DepthView(node *);
    adj_list_t DepthViewUtility(node *);
};

node *tree::insert(int newdata, node *ptr)
{
    if (!ptr)
    {
        return new node(newdata);
    }
    // ptr here would be the parent of the newNode when put successfully
    // ptr can be assigned as the parent of newNode
    if (newdata < ptr->node_data)
    {

        node *left_child_node = insert(newdata, ptr->left);
        ptr->left = left_child_node;

        left_child_node->parent = ptr;
    }

    else //(newdata > ptr->node_data)
    {
        node *right_child_node = insert(newdata, ptr->right);
        ptr->right = right_child_node;

        right_child_node->parent = ptr;
    }

    return ptr;
}

node *tree::findSmallest(node *currPtr)
{
    // validation for currPtr deals with nullptr also
    while (currPtr && currPtr->left)
        currPtr = currPtr->left;

    return currPtr;
}

void tree::DepthView(node *currPtr)
{
    // call utility that creates a list
    adj_list_t depthViewList = DepthViewUtility(currPtr);

    // then print the list
    for (auto itr = depthViewList.begin(); itr != depthViewList.end(); ++itr)
    {
        for (auto nestItr = (*itr).begin(); nestItr != (*itr).end(); ++nestItr)
        {
            std::cout << (*nestItr)->node_data;
            if ((*nestItr)->parent != nullptr)
                std::cout << "^parent" << (*nestItr)->parent->node_data << " ";
        }
        std::cout << std::endl;
    }
}

adj_list_t tree::DepthViewUtility(node *root)
{
    // create a new list of parent and current that
    adj_list_t DepthViewList;

    // utility list to stash level nodes and then push into
    // DepthViewList before moving to next level
    list_t current;
    list_t parent;
    
    current.push_back(root);

    while (!current.empty())
    {
        DepthViewList.push_back(current);

        parent.swap(current);
        current.resize(0);

        for (auto itr = parent.begin(); itr != parent.end(); ++itr)
        {
            if ((*itr)->left != nullptr)
            {
                current.push_back((*itr)->left);
            }
            if ((*itr)->right != nullptr)
            {
                current.push_back((*itr)->right);
            }
        }
    }
    return DepthViewList;
}

node *tree::successor(node *curr_ptr)
{
    if (curr_ptr == nullptr)
        return curr_ptr;

    if (curr_ptr->right != nullptr)
        return findSmallest(curr_ptr->right);

    else
    {
        node *currPtr = curr_ptr;
        node *parent_of_currPtr = currPtr->parent;

        while (parent_of_currPtr != nullptr && parent_of_currPtr->left != currPtr)
        {
            currPtr = parent_of_currPtr;
            parent_of_currPtr = parent_of_currPtr->parent;
        }

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

    node *result = obj.root->left;
    result = obj.successor(result);

    if (result != nullptr)
        std::cout << "Successor node value " << result->node_data << std::endl;
    else
        std::cout << "nullptr\n";

    return 0;
}