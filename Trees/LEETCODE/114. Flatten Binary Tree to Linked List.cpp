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
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;

        if (root->left == nullptr && root->right == nullptr)
            return;

        if (root->left)
        {
            // keep diving to left
            flatten(root->left);

            // put the left node to right side, the prev/existing right side node will be appended to the new right node
            TreeNode *store_right_append_later = root->right;
            
            root->right = root->left;
            root->left = nullptr;

            // find the position to insert the stored right node
            TreeNode *traverse = root->right;
            while (traverse->right)
                traverse = traverse->right;

            traverse->right = store_right_append_later;
        }

        flatten(root->right);
    }
};