
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//*/
class Solution
{
public:
    // ListNode* swapTwo
    ListNode *swapNodes(ListNode *head, int k)
    {

        if (!head || (head && !head->next))
        {
            return head;
        }

        /*
        traverse list, find ith node
        maintain k_front_prePtr and k_front_currPtr for ith Node
        first traversal should give length also
        2nd traversal,
        k_back_prePtr and k_back_currPtr for size -ith node

        interweave the list for getting swapped list.
        */

        ListNode *traverse = head;
        while (traverse)
        {

            traverse = traverse->next;
            ++length;

        }
    }
};