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
    bool isCompleteTree(TreeNode *root)
    {
        // base case where initially the root is empty
        if (!root)
            return true;

        queue<TreeNode *> bfs_queue;
        bfs_queue.push(root);

        bool saw_a_null_node = false;

        while (!bfs_queue.empty())
        {
            TreeNode *temp = bfs_queue.front();
            bfs_queue.pop();

            if (temp == nullptr)
            {
                // once we have set this, if any other variable comes after that which is not null
                // then completeness of binary tree can be denied
                saw_a_null_node = true;
            }
            else
            {
                if (saw_a_null_node == true) // a nullptr was before this node, tree pass failed
                    return false;
                else
                {
                    bfs_queue.push(temp->left);
                    bfs_queue.push(temp->right);
                }
            }
        }

        // if control reaches this point, it is a complete BT
        return true;
    }
};