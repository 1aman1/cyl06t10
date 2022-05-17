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
    ListNode *addAtTail(int val, ListNode *head)
    {
        ListNode *newNode = new ListNode(val);

        // if list is empty
        if (!head)
        {
            head = newNode;
        }

        // traverse till the end and append new node
        else
        {
            ListNode *tmp = head;

            // iterate to the index
            while (tmp->next)
            {
                tmp = tmp->next;
            }
            tmp->next = newNode;
        }

        return head;
    }

    ListNode *removeElements(ListNode *head, int val)
    {

        // return nullptr if list empty
        if (!head)
            return nullptr;

        /* 1. traverse the list
        2. create another list with non-matching values
        */

        ListNode *traverse, *head2;

        head2 = nullptr;
        traverse = head;

        while (traverse)
        {
            if (traverse->val != val)
            {
                head2 = addAtTail(traverse->val, head2);
            }
            traverse = traverse->next;
        }

        return head2;
    }
};