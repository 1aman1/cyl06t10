/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return nullptr;

        linker_util(root->left, root->right);

        return root;
    }

    void linker_util(Node *lhs, Node *rhs)
    {
        if (!lhs)
            return;
        lhs->next = rhs;

        linker_util(lhs->left, lhs->right);
        linker_util(rhs->left, rhs->right);

        linker_util(lhs->right, rhs->left);
    }
};