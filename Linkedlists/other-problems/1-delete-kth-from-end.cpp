/*
Given a singly linked list and an integer k, remove_kth_from_back the kth last element from the list.
k is guaranteed to be smaller than the length of the list.
The list is very long, so making more than one pass is prohibitively expensive.

Do this in constant space and in one pass

*/

#include <iostream>

struct node_t
{
    int data;
    node_t *next;

    node_t() = delete;
    node_t(int v) : data(v), next(nullptr){};
};

struct list_t
{
public:
    list_t() { head = nullptr; };

    void
    insert(int);

    void
    print();

    void
    remove_kth_from_back(int);

    node_t *head;

    int size = 0;
};

void list_t::print()
{
    if (head)
    {
        node_t *tmp = head;
        while (tmp != nullptr)
        {
            std::cout << " " << tmp->data;
            tmp = tmp->next;
        }
        std::cout << "\nsize: " << size << "\n";
    }
}

void list_t::insert(int newData)
{
    if (!head)
    {
        head = new node_t(newData);
    }
    else
    {
        node_t *n = new node_t(newData);
        n->next = head;
        head = n;
    }
    ++size;
}

//_____SOLUTION______//

void list_t::remove_kth_from_back(int pos)
{
    node_t *slow = head;
    node_t *fast = head;

    while (pos >= 0)
    {
        --pos;
        fast = fast->next;
    }

    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    node_t *tmp = slow->next;
    slow->next = slow->next->next;
    delete tmp;
}

int main()
{

    list_t obj;

    for (int i = 50; i > 0; i -= 5)
    {
        obj.insert(i);
    }

    // obj.print();
    int pos = 3;
    obj.remove_kth_from_back(pos);

    obj.print();

    return 0;
}