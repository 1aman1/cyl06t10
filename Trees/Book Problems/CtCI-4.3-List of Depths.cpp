#include <iostream>
#include <list>
#define DEBUG false

struct treeNode
{
    int node_data;
    treeNode *left;
    treeNode *right;
    treeNode(int newdata) : node_data(newdata),
                            left(nullptr),
                            right(nullptr) {}
};

class tree
{
public:
    treeNode *root;
    tree();
    treeNode *insert(int, treeNode *);
};

tree::tree()
{
    root = nullptr;
}

treeNode *tree::insert(int newdata, treeNode *ptr)
{
    if (!ptr)
    {
        return new treeNode(newdata);
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

void inOrder(treeNode *root)
{
    if (!root)
        return;

    inOrder(root->left);
    std::cout << root->node_data;
    inOrder(root->right);
}

std::list<std::list<treeNode *>> listOfDepths(treeNode *root)
{
    std::list<std::list<treeNode *>> resListofDepths;
    std::list<treeNode *> current;

    // if root carries valid a tree, push it to resultant list of depths
    if (root != nullptr)
    {
        current.push_back(root);
    }

    while (current.size() > 0)
    {
        // push current to resultant list of depths
        resListofDepths.push_back(current);

        // parent nodes need to be iterated and pushed to emptied current 
        std::list<treeNode *> parent = current;
        
        // reset current
        current.resize(0);

        // all the child elements at this level will be pushed to current list, by iterating
        for (std::list<treeNode *>::iterator itr = parent.begin(); itr != parent.end(); ++itr)
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
    tree tO;

    tO.root = tO.insert(4, tO.root);
    tO.root = tO.insert(2, tO.root);
    tO.root = tO.insert(6, tO.root);
    tO.root = tO.insert(1, tO.root);
    tO.root = tO.insert(3, tO.root);
    tO.root = tO.insert(5, tO.root);
    tO.root = tO.insert(7, tO.root);

    inOrder(tO.root);

    std::list<std::list<treeNode *>> listByLevels;
    listByLevels = listOfDepths(tO.root);

    // levels taken
    // std::cout << std::endl;
    // std::cout << listByLevels.size();
    // std::cout << std::endl;

    //  std::list<std::list<treeNode *>>
    //  std::list<treeNode *>

    // traverse and print the list taken
    std::cout << std::endl;

    for (std::list<std::list<treeNode *>>::iterator itr = listByLevels.begin(); itr != listByLevels.end(); ++itr)
    {
        for (std::list<treeNode *>::iterator levelListitr = (*itr).begin(); levelListitr != (*itr).end(); ++levelListitr)
        {
            std::cout << (*levelListitr)->node_data << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}