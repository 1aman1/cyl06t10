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
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head != nullptr && head->next != nullptr)
        {
            ListNode *singleSpeedPtr = head;
            ListNode *doubleSpeedPtr = head;

            while (doubleSpeedPtr->next && doubleSpeedPtr->next->next)
            {

                // singleSpeedPtr moves one step at a time
                singleSpeedPtr = singleSpeedPtr->next;

                //  doubleSpeedPtr moves two steps at a time
                doubleSpeedPtr = doubleSpeedPtr->next->next;
            }

            if (doubleSpeedPtr->next)
            {
                // when the length is even, adjust the singleSpeedPtr one more step ahead.
                singleSpeedPtr = singleSpeedPtr->next;
            }

            // singleSpeedPtr now points to the middle node,
            // Deletion below

            ListNode *temp = head;

            while (temp->next != singleSpeedPtr)
                temp = temp->next;

            temp->next = singleSpeedPtr->next;
            delete singleSpeedPtr;

            return head;
        }

        delete head;
        return nullptr;
    }
};
