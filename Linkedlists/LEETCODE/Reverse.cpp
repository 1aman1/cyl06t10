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
    ListNode* reverseList(ListNode* head) {
        if ( head == nullptr ) return head;
        
        if ( head->next == nullptr) return head;
        
        // reverse the list here
        ListNode *prev, *curr, *NEXT;
        
        curr = head;
        prev = nullptr;
        NEXT = nullptr;
        while ( curr ) {
            NEXT = curr->next;
            curr->next = prev;
            prev = curr;
            curr = NEXT;
        }
        
        head = prev;
        return head;
    }
};
