#include <iostream>
#include <queue>
#include <list>

/*
node has data, left child, right child & parent ptr too.
*/

/*
implements LCA for BST
*/

struct node;

typedef std::list<std::list<node *>> adj_list_t;
typedef std::list<node *> list_t;

struct node
{
    int data;

    node *left;
    node *right;

    node *parent;

    node() = delete;

    node(int newdata) : data(newdata),
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

    node *remove(int, node *);
    node *findSmallest(node *currPtr);

    // LCA
    node *FirstCommonAncestor(node *, node *);
    int height(node *);
    node *searchKey(node *, node *);

    // view
    void DepthView(node *);
    adj_list_t DepthViewUtility(node *);
};

node *tree::searchKey(node *_root, node *curr_node)
{
    if (curr_node == nullptr || curr_node->data == _root->data)
    {
        return curr_node;
    }
    else if (curr_node->data < _root->data)
    {
        return searchKey(_root->left, curr_node);
    }
    else
    {
        return searchKey(_root->right, curr_node);
    }
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
            std::cout << (*nestItr)->data;
            if ((*nestItr)->parent != nullptr)
                std::cout << "^parent" << (*nestItr)->parent->data << " ";
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
    current.push_back(root);

    while (!current.empty())
    {
        DepthViewList.push_back(current);
        list_t parent = current;
        current.resize(0);

        for (auto itr = parent.begin(); itr != parent.end(); ++itr)
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

node *tree::insert(int newdata, node *ptr)
{
    if (!ptr)
    {
        return new node(newdata);
    }
    // ptr here would be the parent of the newNode when put successfully
    // ptr can be assigned as the parent of newNode
    if (newdata < ptr->data)
    {

        node *left_child_node = insert(newdata, ptr->left);
        ptr->left = left_child_node;

        left_child_node->parent = ptr;
    }

    else //(newdata > ptr->data)
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

node *tree::remove(int item, node *currPtr)
{
    // if it is null
    if (currPtr == nullptr)
        return currPtr;

    // if value to delete is less than current node's value, go left
    else if (item < currPtr->data)
        currPtr->left = remove(item, currPtr->left);

    // if value to delete is greater than current node's value, go right
    else if (item > currPtr->data)
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
            node *ptrToLeftSubtree = currPtr->left;
            delete currPtr;
            return ptrToLeftSubtree;
        }

        // node with a right subtree
        else if (currPtr->left == nullptr && currPtr->right != nullptr)
        {
            node *ptrToRightSubtree = currPtr->right;
            delete currPtr;
            return ptrToRightSubtree;
        }

        // node with left subtree and right subtree
        else
        {
            // finMin in right subtree
            node *minNode = findSmallest(currPtr->right);

            // copy its data
            currPtr->data = minNode->data;

            // lastly call minNode deletion in its subtree
            currPtr->right = remove(minNode->data, currPtr->right);
        }
    }
    return currPtr;
}

int tree::height(node *curr_node)
{
    int height = 0;
    while (curr_node)
    {
        curr_node = curr_node->parent;
        ++height;
    }
    return height;
}

node *tree::FirstCommonAncestor(node *p, node *q)
{
    // where either one of the pointers given is a bluff
    if (searchKey(root, p) == nullptr || searchKey(root, q) == nullptr)
    {
        return nullptr;
    }

    //  else find the depths of both pointers and find intersection node

    int depth_p = height(p);
    int depth_q = height(q);

    node *coverUp = nullptr;

    depth_p > depth_q ? coverUp = p : coverUp = q;

    int diff = std::abs(depth_p - depth_q);

    // make up for the difference
    while (coverUp && diff > 0)
    {
        diff--;
        coverUp = coverUp->parent;
    }

    depth_p > depth_q ? p = coverUp : q = coverUp;

    while (p && q && p->data != q->data)
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

    node *p = nullptr;
    node *q = nullptr;
    node *res = nullptr;

    // create tmp objects for find

    node *tmp1 = new node(20);
    p = obj.searchKey(obj.root, tmp1);

    node *tmp2 = new node(70);
    q = obj.searchKey(obj.root, tmp2);

    std::cout << "p " << obj.height(p) << std::endl;
    std::cout << "q " << obj.height(q) << std::endl;

    res = obj.FirstCommonAncestor(p, q);

    // res = obj.FirstCommonAncestor(p, nullptr);
    // res = obj.FirstCommonAncestor(nullptr, q);

    if (res)
        std::cout << res->data << std::endl;
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