/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator
{
private:
    stack<TreeNode *> myStack;

    void goLeftUtil(TreeNode *root)
    {
        TreeNode *leftMost = root;
        while (leftMost != nullptr)
        {
            myStack.push(leftMost);
            leftMost = leftMost->left;
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        goLeftUtil(root);
    }

    int next()
    {
        TreeNode *onTop = myStack.top();
        myStack.pop();

        if (onTop->right != nullptr)
            goLeftUtil(onTop->right);

        return onTop->val;
    }

    bool hasNext()
    {
        if (myStack.empty())
            return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
