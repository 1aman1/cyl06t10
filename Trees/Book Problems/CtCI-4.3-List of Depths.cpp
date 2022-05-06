#include <iostream>
#include <list>
#define DEBUG false

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
    tree_node *insert(int, tree_node *);
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

    else
    {
        ptr->right = insert(newdata, ptr->right);
    }

    return ptr;
}

void inOrder(tree_node *root)
{
    if (!root)
        return;

    inOrder(root->left);
    std::cout << root->node_data;
    inOrder(root->right);
}

std::list<std::list<tree_node *>> listOfDepths(tree_node *root)
{
    std::list<std::list<tree_node *>> resListofDepths;
    std::list<tree_node *> current;

    // if root ptr carries valid a tree, push it
    if (root != nullptr)
    {
        current.push_back(root);
    }

    while (current.size() > 0)
    {
        // push current treeObj resultant list of depths
        resListofDepths.push_back(current);

        // parent nodes need treeObj be iterated and pushed treeObj emptied current
        std::list<tree_node *> parent = current;

        // reset current
        current.resize(0);

        // all the child elements at this level will be pushed treeObj current list, by iterating
        for (std::list<tree_node *>::iterator itr = parent.begin(); itr != parent.end(); ++itr)
        {
            // push valid ptrs
            if ((*itr)->left != nullptr)
                current.push_back((*itr)->left);
            if ((*itr)->right != nullptr)
                current.push_back((*itr)->right);
        }
    }
    return resListofDepths;
}

int main()
{
    tree treeObj;

    treeObj.root = treeObj.insert(4, treeObj.root);
    treeObj.root = treeObj.insert(2, treeObj.root);
    treeObj.root = treeObj.insert(6, treeObj.root);
    treeObj.root = treeObj.insert(1, treeObj.root);
    treeObj.root = treeObj.insert(3, treeObj.root);
    treeObj.root = treeObj.insert(5, treeObj.root);
    treeObj.root = treeObj.insert(7, treeObj.root);

    inOrder(treeObj.root);

    std::list<std::list<tree_node *>> listByLevels;
    listByLevels = listOfDepths(treeObj.root);

    // levels taken
    // std::cout << std::endl;
    // std::cout << listByLevels.size();
    // std::cout << std::endl;

    //  std::list<std::list<tree_node *>>
    //  std::list<tree_node *>

    // traverse and print the list taken
    std::cout << std::endl;

    for (std::list<std::list<tree_node *>>::iterator itr = listByLevels.begin(); itr != listByLevels.end(); ++itr)
    {
        for (std::list<tree_node *>::iterator levelListitr = (*itr).begin(); levelListitr != (*itr).end(); ++levelListitr)
        {
            std::cout << (*levelListitr)->node_data << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}