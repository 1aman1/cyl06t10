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
    vector<int> myVec;
    /*
    1. store the linked list in a vector
    1.b. optionally delete the linked list too
    2. return random number within size of vector using rand()
    */

    Solution(ListNode *head)
    {
        ListNode *traverse = head;
        while (traverse)
        {
            // 1.
            myVec.push_back(traverse->val);

            // 1.b.
            head = head->next;
            delete traverse;
            traverse = head;
        }
    }

    int getRandom()
    {
        // 2.
        return myVec[rand() % myVec.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */