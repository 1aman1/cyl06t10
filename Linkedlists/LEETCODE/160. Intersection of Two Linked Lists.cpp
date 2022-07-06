class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        /*
        two list heads are given,
        1. we will gather length of the two different lists by keeping one counter
        prepare two pointers A,B so that we can move either of them based on the
        length difference
        traverse two lists at same time,
        match their next pointers and break the loop if they same/ intersecting
        */

        if (!headA || !headB)
            return nullptr;

        // 1.
        ListNode *traverseA = nullptr, *traverseB = nullptr;
        int lengthA, lengthB, diff;

        traverseA = headA;
        traverseB = headB;
        lengthA = lengthB = 0;

        while (traverseA)
        {
            ++lengthA;
            traverseA = traverseA->next;
        }
        while (traverseB)
        {
            ++lengthB;
            traverseB = traverseB->next;
        }

        (lengthA < lengthB ? diff = lengthB - lengthA : diff = lengthA - lengthB);

        // move the pointer of longer list

        traverseA = headA;
        traverseB = headB;

        if (lengthA > lengthB)
        {

            while (diff)
            {
                traverseA = traverseA->next;
                --diff;
            }
        }
        else
        {

            while (diff)
            {
                traverseB = traverseB->next;
                --diff;
            }
        }

        // return the node when inntersection found

        while (traverseA && traverseB)
        {
            if (traverseA == traverseB)
            {
                return traverseA;
            }
            traverseA = traverseA->next;
            traverseB = traverseB->next;
        }
        return nullptr;
    }
};