/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode *PSlow_x, *PFast_2x;

        PSlow_x = PFast_2x = head;

        while (PFast_2x && PFast_2x->next && PFast_2x->next->next)
        {
            PSlow_x = PSlow_x->next;
            PFast_2x = PFast_2x->next->next;

            // they will collide before pointing to null, if the list is circular
            if (PSlow_x == PFast_2x)
            {
                // start another single step pointer from head
                ListNode *PtrFromHead = head;

                while (PSlow_x != PtrFromHead)
                {
                    PSlow_x = PSlow_x->next;
                    PtrFromHead = PtrFromHead->next;
                }

                return PSlow_x;
            }
        }
        return nullptr;
    }
};