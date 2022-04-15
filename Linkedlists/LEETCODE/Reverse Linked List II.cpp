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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if ( !head || right - left < 0 ) return nullptr;

        // if left and right point to the same position, list can be returned as It is.
        if ( right - left == 0 ) return head;

        /* 1. traverse list
        2. when index comes in left to right range OR LtR, push elements into the stack
        3. traverse the same list again, 
        4. when index arrives in LtR, overwrite the corresponding part of list
        */

        ListNode* traverse = head;
        stack<int> myStack;

        // 1.
        for ( int i = 1; i <= right; ++i ) {            
            
            // 2. 
            if ( i >= left ) {
                myStack.push( traverse->val );
            }
            traverse = traverse->next;
        }

        // 3.
        traverse = head;
        for ( int i = 1; i <= right; ++i ) {            
            
            // 4. 
            if ( i >= left ) {
                traverse->val = myStack.top();
                myStack.pop();
            }
            traverse = traverse->next;
        }

        return head;
    }
};