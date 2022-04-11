//* Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
//*/
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        /*
        find
        n - 1
        m->next
        nodes by traversing first
        */
        ListNode *traverse = list1, *n_prePtr = nullptr, *m_nxtPtr = nullptr;
        int i = a -1;

        while ( i ) {
            traverse = traverse->next;
            --i;
        }
        traverse = n_prePtr;

        i = b;

        traverse = list1;

        while ( i ) {
            traverse = traverse->next;
            --i;
        }
        m_nxtPtr = traverse->next;

        // wee have both pointers now, 
        // insert the list2 in betweek indexes by mending the pointers

        n_prePtr->next = list2;

        while ( list2->next ) {
            list2 = list2->next;
        }
        list2->next = m_nxtPtr;

        return list1;

    }
};

