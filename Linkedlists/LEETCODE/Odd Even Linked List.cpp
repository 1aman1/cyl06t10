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
    ListNode *oddEvenList(ListNode *head)
    {
        /*
        we will inter weave the list so that the nodes at even position are adjacent to one another,
        like wise for odd nodes

        1. keep odd to first node, even to odd->next node
        2. store even head to append to the list later
        3. update pointers in a way that odd points to node next to next, same for even
        4. Once sequencing done, append the even list to odd list in the end
        */

        if (!head)
            return head;

        ListNode *odd, *even, *evenHead;

        // 1.
        odd = head;
        even = head->next;

        // 2.
        evenHead = even;

        while (even && even->next)
        {
            // 3.
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }

        // 4.
        odd->next = evenHead;

        return head;
    }
};