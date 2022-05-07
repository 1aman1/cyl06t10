/* Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *NextNode;
     ListNode(int x) : val(x), NextNode(NULL) {}
 };
//*/

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        /*
        node to be deleted in not the tail node is CRUCIAL for the below method to work

        1. copy value of next node in current node
        2. update pointer of current node
        3. delete the next node
        */

        ListNode *currNode = node, *NextNode = nullptr;

        // 1.
        currNode->val = currNode->next->val;

        // 2.
        NextNode = currNode->next;
        if (NextNode->next == nullptr)
        {
            currNode->next = nullptr;
        }
        else
        {
            currNode->next = NextNode->next;
        }

        delete NextNode;
    }
};