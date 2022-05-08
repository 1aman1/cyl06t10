/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * }; */

class Solution
{
public:
    int pairSum(ListNode *head)
    {
        // reverse the list from middle
        // then add the corresponding values, so that twin pairs get added
        // compare the sum with previous items

        ListNode *singleStepPtr, *doubleStepPtr, *middlePtr;
        middlePtr = singleStepPtr = doubleStepPtr = head;

        while (doubleStepPtr && doubleStepPtr->next && doubleStepPtr->next->next)
        {
            singleStepPtr = singleStepPtr->next;
            doubleStepPtr = doubleStepPtr->next->next;
        }

        // singleStepPtr points to the middle

        singleStepPtr = singleStepPtr->next;
        singleStepPtr = reverseList(singleStepPtr);

        //
        int sum = -1;

        while (singleStepPtr)
        {
            sum = max(sum, singleStepPtr->val + middlePtr->val);
            singleStepPtr = singleStepPtr->next;
            middlePtr = middlePtr->next;
        }
        return sum;
    };

    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        // reverse the list here
        ListNode *prev, *curr, *NEXT;

        curr = head;
        prev = nullptr;
        NEXT = nullptr;
        while (curr)
        {
            NEXT = curr->next;
            curr->next = prev;
            prev = curr;
            curr = NEXT;
        }

        head = prev;
        return head;
    }
};