#include <iostream>

#define INT_MIN -99999
#define INT_MAX 99999

struct t_Node
{
    int node_data;
    t_Node *left;
    t_Node *right;
    t_Node(int newdata) : node_data(newdata), left(nullptr), right(nullptr) {}
};

bool validateBST(int MIN, t_Node *curr, int MAX)
{
    if (curr)
    {
        if (MIN < curr->node_data && curr->node_data < MAX)
        {
            return validateBST(MIN, curr->left, curr->node_data) && validateBST(curr->node_data, curr->right, MAX);
        }
        else
        {
            return false;
        }
    }
    else
        return true;
}

int main()
{
    t_Node *testroot1 = new t_Node(2);
    testroot1->left = new t_Node(1);
    testroot1->right = new t_Node(3);

    std::cout << testroot1->node_data << std::endl;
    std::cout << testroot1->left->node_data << std::endl;
    std::cout << testroot1->right->node_data << std::endl;

    std::cout << std::boolalpha
              << validateBST(INT_MIN, testroot1, INT_MAX)
              << std::endl;

    t_Node *testroot2 = new t_Node(4);
    testroot2->left = new t_Node(2);
    testroot2->left->right = new t_Node(6);

    std::cout << testroot2->node_data << std::endl;
    std::cout << testroot2->left->node_data << std::endl;
    std::cout << testroot2->left->right->node_data << std::endl;

    std::cout << std::boolalpha
              << validateBST(INT_MIN, testroot2, INT_MAX)
              << std::endl;

    return 0;
}