
/*
Sum
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
    list_t() { head = nullptr; };
    // list_t(node_t *head) : head(head){};

    void
    insert(int);

    void
    print();

    node_t *head;

    int sum_iterative();

    int sum_recursive(node_t *);
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
        std::cout << "\n";
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
}

//_____SOLUTION______//

void zapper(list_t list1, list_t list2)
{
    node_t *zipper = list1.head;

    node_t *current1 = list1.head->next;
    node_t *current2 = list2.head;

    int pos = 0;

    while (current1 != nullptr && current2 != nullptr)
    {
        if (pos & 1)
        {
            zipper->next = current1;
            current1 = current1->next;
        }
        else
        {
            zipper->next = current2;
            current2 = current2->next;
        }

        zipper = zipper->next;
        ++pos;
    }

    if (current2 == nullptr)
        zipper->next = current1;
    if (current1 == nullptr)
        zipper->next = current2;
}

int main()
{
    list_t list_one;
    list_t list_two;

    for (int i = 6; i > 0; --i)
    {
        if (i & 1)
            list_one.insert(i);
        else
            list_two.insert(i);
    }

    list_one.print();
    list_two.print();

    zapper(list_one, list_two);

    list_one.print();

    return 0;
}