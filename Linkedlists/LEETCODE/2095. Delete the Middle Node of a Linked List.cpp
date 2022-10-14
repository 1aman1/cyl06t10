class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head != nullptr && head->next != nullptr)
        {
            // >
            ListNode *PSlow_x = head;
            ListNode *PFast_2x = head;

            while (PFast_2x->next && PFast_2x->next->next)
            {
                PSlow_x = PSlow_x->next;
                PFast_2x = PFast_2x->next->next;
            }

            if (PFast_2x->next)
            {
                PSlow_x = PSlow_x->next;
            }

            // >
            ListNode *tmp = head;

            while (tmp->next != PSlow_x)
                tmp = tmp->next;

            tmp->next = PSlow_x->next;
            delete PSlow_x;

            return head;
        }

        delete head;
        return nullptr;
    }
};
