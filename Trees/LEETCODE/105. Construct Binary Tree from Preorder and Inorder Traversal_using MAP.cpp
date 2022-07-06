#include <iostream>
#include <unordered_map>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *builderUtility(const int &left,
                             const int &right,
                             const std::vector<int> &preOrderSeq,
                             int &fillerIndex,
                             std::unordered_map<int, int> &inOrderLookupMap)
    {
        if (left > right)
            return nullptr;

        TreeNode *node = new TreeNode(preOrderSeq[fillerIndex]);
        ++fillerIndex;

        // pos is the location of current node->val in the inorder sequence,
        // to divide the further calls for left subtree and calls for right subtree
        int pos = inOrderLookupMap[node->val];
        node->left = builderUtility(left, pos - 1, preOrderSeq, fillerIndex, inOrderLookupMap);

        node->right = builderUtility(pos + 1, right, preOrderSeq, fillerIndex, inOrderLookupMap);

        return node;
    }

    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
    {
        std::unordered_map<int, int> inOrderLookupMap;

        for (unsigned long i = 0; i < inorder.size(); ++i)
            inOrderLookupMap[inorder[i]] = i;

        int fillerIndex = 0;
        return builderUtility(0, inorder.size() - 1, preorder, fillerIndex, inOrderLookupMap);
    }
};

class tree : public Solution
{
public:
    TreeNode *root;

    // views
    void inOrderView(TreeNode *currPtr);
    void preOrderView(TreeNode *currPtr);
};

void tree::inOrderView(TreeNode *currPtr)
{
    if (!currPtr)
    {
        return;
    }

    inOrderView(currPtr->left);

    std::cout << currPtr->val << "\t";

    inOrderView(currPtr->right);
}

void tree::preOrderView(TreeNode *currPtr)
{
    if (!currPtr)
    {
        return;
    }
    std::cout << currPtr->val << "\t";

    preOrderView(currPtr->left);
    preOrderView(currPtr->right);
}

int main()
{
    std::cout << __FILE__ << std::endl;

    std::vector<int> inOrderSeq = {4, 2, 1, 7, 5, 8, 3, 6};
    std::vector<int> preOrderSeq = {1, 2, 4, 3, 5, 7, 8, 6};

    // tree obj;
    tree obj;

    obj.root = obj.buildTree(inOrderSeq, preOrderSeq);

    std::cout << std::endl;
    obj.inOrderView(obj.root);

    std::cout << std::endl;
    obj.preOrderView(obj.root);

    std::cout << std::endl;
    return 0;
}