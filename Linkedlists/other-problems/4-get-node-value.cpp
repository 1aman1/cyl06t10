
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

    int get_node_value_iterative(int);

    int get_node_value_recursive(node_t *, int);
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

int list_t::get_node_value_recursive(node_t *curr_node, int pos)
{
    if (curr_node == nullptr)
        return -1;

    if (pos == 1)
        return curr_node->data;

    return get_node_value_recursive(curr_node->next, --pos);
}

int list_t::get_node_value_iterative(int pos)
{
    if (head == nullptr)
        return -1;

    node_t *traverse = head;

    int count = 1;
    while (traverse != nullptr)
    {
        if (count == pos)
            return traverse->data;

        count += 1;
        traverse = traverse->next;
    }
    return -1;
}

int main()
{

    list_t obj;

    for (int i = 10; i > 0; --i)
    {
        obj.insert(i);
    }

    obj.print();

    std::cout << std::boolalpha << obj.get_node_value_iterative(5) << "\n";
    std::cout << std::boolalpha << obj.get_node_value_iterative(50) << "\n";

    std::cout << std::boolalpha << obj.get_node_value_recursive(obj.head, 5) << "\n";
    std::cout << std::boolalpha << obj.get_node_value_recursive(obj.head, 50) << "\n";

    return 0;
}