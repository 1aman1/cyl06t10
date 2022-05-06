#include <iostream>
#include <queue>
#include <list>

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
    tree_node *root;
    tree();

public:
    tree_node *insert(int, tree_node *);

    int maxDepth(tree_node *root);
    void DepthView(tree_node *);
    std::list<std::list<tree_node *>> DepthViewUtility(tree_node *);
};

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

int tree::maxDepth(tree_node *root)
{
    return root == NULL ? 0 : std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
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

    std::cout << std::endl;
    obj.DepthView(obj.root);
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "max depth for this tree :" << obj.maxDepth(obj.root);
    std::cout << std::endl;

    return 0;
}