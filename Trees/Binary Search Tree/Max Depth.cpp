#include <iostream>
#include <queue>
#include <list>

/*
Each BST node has data, left child, right child.
*/

struct node_t
{
    int node_data;
    node_t *left;
    node_t *right;

    node_t(int newData) : node_data(newData),
                          left(nullptr),
                          right(nullptr) {}
};

// BST interface
class BSTree_t
{
public:
    BSTree_t();
    void insert(int);
    void remove(int);
    void DepthView();
    node_t *findSmallest(node_t *);

    int maxDepth();

private:
    node_t *root;

    int maxDepthUtility(node_t *);

    virtual node_t *insertUtility(int, node_t *);
    virtual node_t *removeUtility(int, node_t *);
    std::list<std::list<node_t *>> DepthViewUtility(node_t *);
};

BSTree_t::BSTree_t() : root(nullptr) {}

int BSTree_t::maxDepthUtility(node_t *root)
{

    return root == NULL ? 0 : std::max(maxDepthUtility(root->left), maxDepthUtility(root->right)) + 1;
}

int BSTree_t::maxDepth()
{

    return maxDepthUtility(root);
}

/*--------------------------------------------- Insert Element into the tree */
void BSTree_t::insert(int newData)
{
    root = insertUtility(newData, root);
}

node_t *BSTree_t::insertUtility(int newData, node_t *ptr)
{
    if (!ptr) // no node present, create a new and return
    {
        return new node_t(newData);
    }

    // go to left subtree
    if (newData < ptr->node_data)
    {
        ptr->left = insertUtility(newData, ptr->left);
    }

    else //(newData > ptr->node_data) // go to right subtree
    {
        ptr->right = insertUtility(newData, ptr->right);
    }

    return ptr;
}

/* ---------------------------------------------Delete element from AVL tree */
void BSTree_t::remove(int newData)
{
    root = removeUtility(newData, root);
}

node_t *BSTree_t::removeUtility(int data, node_t *curr_ptr)
{
    // if curr_ptr is null
    if (curr_ptr == nullptr)
        return curr_ptr;

    // if delete node has less than current node's value, go left
    else if (data < curr_ptr->node_data)
        curr_ptr->left = removeUtility(data, curr_ptr->left);

    // if  delete node has greater than current node's value, go right
    else if (data > curr_ptr->node_data)
        curr_ptr->right = removeUtility(data, curr_ptr->right);

    // if no condition matches, then
    // it is the curr_ptr that has to be deleted
    else
    {
        // a leaf node
        if (curr_ptr->left == nullptr && curr_ptr->right == nullptr)
        {
            delete curr_ptr;
            return nullptr;
        }

        // node with a left subtree
        else if (curr_ptr->left != nullptr && curr_ptr->right == nullptr)
        {
            node_t *ptrToLeftSubtree = curr_ptr->left;
            delete curr_ptr;
            return ptrToLeftSubtree;
        }

        // node with a right subtree
        else if (curr_ptr->left == nullptr && curr_ptr->right != nullptr)
        {
            node_t *ptrToRightSubtree = curr_ptr->right;
            delete curr_ptr;
            return ptrToRightSubtree;
        }

        // node with left subtree and right subtree
        else
        {
            // finMin in right subtree
            node_t *minNode = findSmallest(curr_ptr->right);

            // copy its data
            curr_ptr->node_data = minNode->node_data;

            // lastly call minNode deletion in its subtree
            curr_ptr->right = removeUtility(minNode->node_data, curr_ptr->right);
        }
    }
    return curr_ptr;
}

/* ---------------------------------------------bird view utility */
void BSTree_t::DepthView()
{
    std::cout << std::endl;

    // call utility that creates a list
    std::list<std::list<node_t *>> depthViewList = DepthViewUtility(root);

    // then print the list
    for (std::list<std::list<node_t *>>::iterator itr = depthViewList.begin(); itr != depthViewList.end(); ++itr)
    {
        for (std::list<node_t *>::iterator nestItr = (*itr).begin(); nestItr != (*itr).end(); ++nestItr)
        {
            std::cout << (*nestItr)->node_data << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
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

/* ---------------------------------------------to find the minimum value node */
// params : node_t * T
node_t *BSTree_t::findSmallest(node_t *curr_ptr)
{
    while (curr_ptr && curr_ptr->left) // validation for curr_ptr deals with nullptr also
        curr_ptr = curr_ptr->left;

    return curr_ptr;
}

int main()
{
    std::cout << "Building " << __FILE__ << std::endl;

    BSTree_t obj;

    // INSERT & BALANCE TEST
    obj.insert(7);
    obj.DepthView();

    std::cout << "max depth:" << obj.maxDepth()
              << std::endl;

    obj.insert(5);
    obj.DepthView();

    std::cout << "max depth:" << obj.maxDepth()
              << std::endl;

    obj.insert(3);
    obj.DepthView();

    std::cout << "max depth:" << obj.maxDepth()
              << std::endl;

    // REMOVE & BALANCE TEST

    obj.insert(1);
    obj.DepthView();

    std::cout << "max depth:" << obj.maxDepth()
              << std::endl;

    obj.remove(7);
    obj.DepthView();

    std::cout << "max depth:" << obj.maxDepth()
              << std::endl;

    return 0;
}