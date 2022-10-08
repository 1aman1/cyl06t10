#include <iostream>

using namespace std;
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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1 || !list2)
            return list1 ? list1 : list2;

        ListNode *current1 = list1;
        ListNode *current2 = list2;

        ListNode *newHead = nullptr;
        ListNode *tail = nullptr;

        if (list1->val < list2->val)
        {
            newHead = current1;
            current1 = current1->next;
        }
        else
        {
            newHead = current2;
            current2 = current2->next;
        }

        tail = newHead;

        while (current1 && current2)
        {
            if (current1->val < current2->val)
            {
                tail->next = current1;
                current1 = current1->next;
            }
            else
            {
                tail->next = current2;
                current2 = current2->next;
            }
            tail = tail->next;
        }
        if (current1)
            tail->next = current1;
        if (current2)
            tail->next = current2;

        return newHead;
    }
};

int main()
{
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // ListNode *list2 = nullptr;
    ListNode *list2 = new ListNode(1);
    // list2->next = new ListNode(3);
    // list2->next->next = new ListNode(4);
    // list2->next->next->next = new ListNode(5);

    Solution obj;
    ListNode *sorted = obj.mergeTwoLists(list1, list2);

    while (sorted)
    {
        cout << sorted->val << " ";
        sorted = sorted->next;
    }

    return 0;
}