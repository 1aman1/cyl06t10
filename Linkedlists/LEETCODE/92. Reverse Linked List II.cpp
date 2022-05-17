// #include<stack>
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        
        /* 1. traverse list
        2. when index comes in left to right range OR LtR, push elements into the stack
        3. traverse the same list again,
        4. when index arrives in LtR, overwrite the corresponding part of list
        */
        
    }
};