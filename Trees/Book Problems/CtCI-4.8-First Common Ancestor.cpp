#include <iostream>
#include <queue>
#include <list>

/*
node has data, left child, right child & parent ptr too.
*/

/*
implements LCA for BST
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

    tree_node *remove(int, tree_node *);
    tree_node *findSmallest(tree_node *currPtr);

    // LCA
    tree_node *FirstCommonAncestor(tree_node *, tree_node *);
    int height(tree_node *);
    tree_node *searchKey(tree_node *, tree_node *);

    // view
    void DepthView(tree_node *);
    std::list<std::list<tree_node *>> DepthViewUtility(tree_node *);
};

tree_node *tree::searchKey(tree_node *_root, tree_node *currNode)
{
    if (currNode == nullptr || currNode->node_data == _root->node_data)
    {
        return currNode;
    }
    else if (currNode->node_data < _root->node_data)
    {
        return searchKey(_root->left, currNode);
    }
    else
    {
        return searchKey(_root->right, currNode);
    }
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

tree_node *tree::remove(int item, tree_node *currPtr)
{
    // if it is null
    if (currPtr == nullptr)
        return currPtr;

    // if value to delete is less than current node's value, go left
    else if (item < currPtr->node_data)
        currPtr->left = remove(item, currPtr->left);

    // if value to delete is greater than current node's value, go right
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
            tree_node *ptrToLeftSubtree = currPtr->left;
            delete currPtr;
            return ptrToLeftSubtree;
        }

        // node with a right subtree
        else if (currPtr->left == nullptr && currPtr->right != nullptr)
        {
            tree_node *ptrToRightSubtree = currPtr->right;
            delete currPtr;
            return ptrToRightSubtree;
        }

        // node with left subtree and right subtree
        else
        {
            // finMin in right subtree
            tree_node *minNode = findSmallest(currPtr->right);

            // copy its data
            currPtr->node_data = minNode->node_data;

            // lastly call minNode deletion in its subtree
            currPtr->right = remove(minNode->node_data, currPtr->right);
        }
    }
    return currPtr;
}

int tree::height(tree_node *currNode)
{
    int height = 0;
    while (currNode)
    {
        currNode = currNode->parent;
        ++height;
    }
    return height;
}

tree_node *tree::FirstCommonAncestor(tree_node *p, tree_node *q)
{
    // where either one of the pointers given is a bluff
    if (searchKey(root, p) == nullptr || searchKey(root, q) == nullptr)
    {
        return nullptr;
    }

    //  else find the depths of both pointers and find intersection node

    int depth_p = height(p);
    int depth_q = height(q);

    tree_node *coverUp = nullptr;

    depth_p > depth_q ? coverUp = p : coverUp = q;

    int diff = std::abs(depth_p - depth_q);

    // make up for the difference
    while (coverUp && diff > 0)
    {
        diff--;
        coverUp = coverUp->parent;
    }

    depth_p > depth_q ? p = coverUp : q = coverUp;

    while (p && q && p->node_data != q->node_data)
    {
        p = p->parent;
        q = q->parent;
    }
    return p;
}

int main()
{
    std::cout << __FILE__ << std::endl;

    tree obj;

    obj.root = obj.insert(50, obj.root);
    obj.root = obj.insert(30, obj.root);
    obj.root = obj.insert(70, obj.root);
    // obj.root = obj.insert(4, obj.root);
    // obj.root = obj.insert(6, obj.root);
    obj.root = obj.insert(20, obj.root);
    // obj.root = obj.insert(8, obj.root);

    // LCA for 7 & 2 should be root ie, 5

    tree_node *p = nullptr;
    tree_node *q = nullptr;
    tree_node *res = nullptr;

    // create tmp objects for find

    tree_node *tmp1 = new tree_node(20);
    p = obj.searchKey(obj.root, tmp1);

    tree_node *tmp2 = new tree_node(70);
    q = obj.searchKey(obj.root, tmp2);

    std::cout << "p " << obj.height(p) << std::endl;
    std::cout << "q " << obj.height(q) << std::endl;

    res = obj.FirstCommonAncestor(p, q);

    // res = obj.FirstCommonAncestor(p, nullptr);
    // res = obj.FirstCommonAncestor(nullptr, q);

    if (res)
        std::cout << res->node_data << std::endl;
    else
        std::cout << "nullptr\n";

    /*
        std::cout << std::endl;
        obj.DepthView(obj.root);
        std::cout << std::endl;

        obj.remove(3, obj.root);

        std::cout        << std::endl;
        obj.DepthView(obj.root);
        std::cout << std::endl;
    */
    return 0;
}