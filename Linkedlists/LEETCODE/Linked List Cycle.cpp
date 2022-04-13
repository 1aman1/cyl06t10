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
    bool hasCycle(ListNode *head)
    {
        // set two pointers in list, singleStepPtr, DoubleStepPtr
        // they will collide before pointing to null, if the list is circular
        // otherwise, loop will brreak.

        // incase head empty
        if (head == nullptr || head->next == nullptr)
            return false;

        ListNode *singleStepPtr, *doubleStepPtr;

        singleStepPtr = doubleStepPtr = head;

        while (doubleStepPtr && doubleStepPtr->next && doubleStepPtr->next->next)
        {
            singleStepPtr = singleStepPtr->next;
            doubleStepPtr = doubleStepPtr->next->next;

            // they will collide before pointing to null, if the list is circular
            if (singleStepPtr == doubleStepPtr)
                return true;
        }

        return false;
    }
};