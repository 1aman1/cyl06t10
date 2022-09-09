#include <iostream>
#include <list>

struct node
{
    int datum;
    node *left;
    node *right;

    node(int newdata) : datum(newdata),
                        left(nullptr),
                        right(nullptr) {}
};

typedef std::list<std::list<node *>> adj_list_t;
typedef std::list<node *> list_t;

class tree
{
public:
    node *root;
    tree() { root = nullptr; }
    node *insert(int, node *);
};

node *tree::insert(int newdata, node *ptr)
{
    if (!ptr)
    {
        return new node(newdata);
    }

    if (newdata < ptr->datum)
    {
        ptr->left = insert(newdata, ptr->left);
    }

    else
    {
        ptr->right = insert(newdata, ptr->right);
    }

    return ptr;
}

void inOrder(node *root)
{
    if (!root)
        return;

    inOrder(root->left);
    std::cout << root->datum;
    inOrder(root->right);
}

adj_list_t listOfDepths(node *root)
{
    adj_list_t resListofDepths;
    list_t current;

    // if root ptr carries valid a tree, push it
    if (root != nullptr)
    {
        current.push_back(root);
    }

    list_t parent;

    while (current.size() > 0)
    {
        // push current treeObj resultant list of depths
        resListofDepths.push_back(current);

        // parent nodes need treeObj be iterated and pushed treeObj emptied current
        parent.swap(current);

        // reset current
        current.resize(0);

        // all the child elements at this level will be pushed treeObj current list, by iterating
        for (auto itr = parent.begin(); itr != parent.end(); ++itr)
        {
            // push valid ptrs only
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

    adj_list_t listByLevels;
    listByLevels = listOfDepths(treeObj.root);

    // traverse and print the list taken
    std::cout << std::endl;

    for (auto itr = listByLevels.begin(); itr != listByLevels.end(); ++itr)
    {
        for (auto levelListitr = (*itr).begin(); levelListitr != (*itr).end(); ++levelListitr)
        {
            std::cout << (*levelListitr)->datum << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}