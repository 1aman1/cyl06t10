#include <iostream>

#define DEBUG false

struct t_Node
{
    int node_data;
    t_Node *left;
    t_Node *right;
    t_Node(int newdata) : node_data(newdata), left(nullptr), right(nullptr) {}
};

class tree
{
private:
public:
    t_Node *root;
    tree();
    t_Node *insert(int, t_Node *);
    void inOrder(t_Node *);
};

tree::tree()
{
    root = nullptr;
}

t_Node *tree::insert(int newdata, t_Node *ptr)
{
    DEBUG == true ? std::cout << __FUNCTION__ << std::endl : std::cout;

    if (!ptr)
    {
        DEBUG == true ? std::cout << " creating new node with " << newdata << std::endl : std::cout;
        return new t_Node(newdata);
    }

    if (newdata < ptr->node_data)
    {
        DEBUG == true ? std::cout << " new data is smaller " << newdata << std::endl : std::cout;

        ptr->left = insert(newdata, ptr->left);
    }

    else //(newdata > ptr->node_data)
    {
        DEBUG == true ? std::cout << " new data is bigger " << newdata << std::endl : std::cout;

        ptr->right = insert(newdata, ptr->right);
    }

    return ptr;
}

void insertInSeq(tree &obj, int arr[], int left, int right)
{
    if (right >= left)
    {
        int mid = (right - left) / 2 + left;
        std::cout << arr[mid] << std::endl;
        obj.root = obj.insert(arr[mid], obj.root);

        insertInSeq(obj, arr, left, mid - 1);
        insertInSeq(obj, arr, mid + 1, right);
    }
    return;
}

void tree::inOrder(t_Node *ptr)
{
    if (!ptr)
        return;

    inOrder(ptr->left);
    std::cout << ptr->node_data << std::endl;
    inOrder(ptr->right);
}

int main()
{
    tree obj;
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};

    insertInSeq(obj, arr, 0, 6);
    obj.inOrder(obj.root);

    return 0;
}