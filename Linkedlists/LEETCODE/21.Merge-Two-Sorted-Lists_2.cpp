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

        if (list1->val > list2->val)
            swap(list1, list2);

        list1->next = mergeTwoLists(list1->next, list2);

        return list1;
    }
};

int main()
{
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // ListNode *list2 = nullptr;
    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
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