
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

    bool find_iterative(int);

    bool find_recursive(node_t *, int);
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

bool list_t::find_recursive(node_t *curr_node, int target)
{
    if (curr_node == nullptr)
        return false;

    if (curr_node->data == target)
        return true;

    return find_recursive(curr_node->next, target);
}

bool list_t::find_iterative(int target)
{
    if (head == nullptr)
        return false;

    node_t *traverse = head;

    while (traverse)
    {
        if (traverse->data == target)
            return true;
        traverse = traverse->next;
    }
    return false;
}

int main()
{

    list_t obj;

    for (int i = 10; i > 0; --i)
    {
        obj.insert(i);
    }

    // obj.print();
    std::cout << std::boolalpha << obj.find_iterative(5) << "\n";
    std::cout << std::boolalpha << obj.find_iterative(50) << "\n";

    std::cout << std::boolalpha << obj.find_recursive(obj.head, 5) << "\n";
    std::cout << std::boolalpha << obj.find_recursive(obj.head, 50) << "\n";

    return 0;
}