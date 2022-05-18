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
    int findPos(std::vector<int> &inOrder, int &start, int &end, int &val)
    {
        for (int i = start; i <= end; i++)
            if (inOrder[i] == val)
                return i;
        return -1;
    }

    TreeNode *buildTree(int start, int end, std::vector<int> &preOrder, std::vector<int> &inOrder, int &fillerIndex)
    {
        if (start > end)
            return nullptr;

        TreeNode *node = new TreeNode(preOrder[fillerIndex]);
        ++fillerIndex;

        if (start == end)
            return node;

        int pos = findPos(inOrder, start, end, node->val);
        
        node->left = buildTree(start, pos - 1, preOrder, inOrder, fillerIndex);
        node->right = buildTree(pos + 1, end, preOrder, inOrder, fillerIndex);

        return node;
    }

    TreeNode *buildTree(std::vector<int> &preOrder, std::vector<int> &inOrder)
    {
        int fillerIndex = 0;

        return buildTree(0, inOrder.size() - 1, preOrder, inOrder, fillerIndex);
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