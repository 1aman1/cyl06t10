
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

    void
    insert(int);

    void
    print();

    node_t *head;

    int size = 0;

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

int list_t::sum_recursive(node_t *curr_node)
{
    if (curr_node == nullptr)
        return 0;

    return curr_node->data + sum_recursive(curr_node->next);
}

int list_t::sum_iterative()
{
    if (head == nullptr)
        return 0;

    node_t *traverse = head;
    int sum = 0;

    while (traverse != nullptr)
    {
        sum += traverse->data;
        traverse = traverse->next;
    }

    return sum;
}

int main()
{

    list_t obj;

    for (int i = 10; i > 0; --i)
    {
        obj.insert(i);
    }

    // obj.print();
    std::cout << obj.sum_iterative() << "\n";
    std::cout << obj.sum_recursive(obj.head) << "\n";

    return 0;
}