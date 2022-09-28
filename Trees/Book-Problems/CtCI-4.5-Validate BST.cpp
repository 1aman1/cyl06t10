#include <iostream>

constexpr int INT_MIN = -99999;
constexpr int INT_MAX = 99999;

struct node
{
    int datum;
    node *left;
    node *right;

    node(int newdata) : datum(newdata),
                        left(nullptr),
                        right(nullptr) {}
};

bool validateBST(int MIN, node *curr, int MAX)
{
    if (curr != nullptr)
    {
        if (MIN < curr->datum && curr->datum < MAX)
        {
            return validateBST(MIN, curr->left, curr->datum) &&
                   validateBST(curr->datum, curr->right, MAX);
        }

        return false;
    }

    return true;
}

int main()
{
    // Tree 1
    node *testroot1 = new node(2);
    testroot1->left = new node(1);
    testroot1->right = new node(3);

    std::cout << std::boolalpha
              << validateBST(INT_MIN, testroot1, INT_MAX)
              << std::endl;

    // Tree 2
    node *testroot2 = new node(4);
    testroot2->left = new node(2);
    // testroot2->right = new node(1);
    testroot2->left->right = new node(3);

    std::cout << std::boolalpha
              << validateBST(INT_MIN, testroot2, INT_MAX)
              << std::endl;

    // Tree 3
    node *testroot3 = new node(7);
    testroot3->left = new node(3);
    testroot3->right = new node(10);
    testroot3->left->right = new node(4);
    // testroot3->left->right = new node(14);

    std::cout << std::boolalpha
              << validateBST(INT_MIN, testroot3, INT_MAX)
              << std::endl;

    return 0;
}