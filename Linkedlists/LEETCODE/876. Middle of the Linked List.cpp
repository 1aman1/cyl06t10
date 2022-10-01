/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *PSlow_x = head;
        ListNode *PFast_2x = head;

        while (PFast_2x && PFast_2x->next && PFast_2x->next->next)
        {
            PSlow_x = PSlow_x->next;
            PFast_2x = PFast_2x->next->next;
        }

        if (PFast_2x->next)
        {
            PSlow_x = PSlow_x->next;
        }

        return PSlow_x;
    }
};