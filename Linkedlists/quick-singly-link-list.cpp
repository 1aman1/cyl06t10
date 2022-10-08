#include <iostream>

/*
a 10 minute linked list
*/

struct node_t
{
    int data;
    node_t *next;

    node_t(int x) : data(x),
                    next(nullptr){};

    node_t() = delete;
};

class list_t
{
private:
    node_t *head;
    int size;

public:
    list_t() : head(nullptr), size(0){};

    // insert by value
    void
    insert(int);

    void
    remove();

    void
    print();

    int
    get_size();
};

int list_t::get_size()
{
    return size;
}

void list_t::remove()
{
    node_t *head_hook = head;
    head = head->next;
    delete head_hook;

    --size;
}

void list_t::insert(int item)
{
    node_t *new_node = new node_t(item);

    // std::cout << "data :" << new_node->data;
    new_node->next = head;
    head = new_node;

    ++size;
}

void list_t::print()
{
    if (size != 0)
    {
        node_t *temp = head;

        std::cout << "\nHead~ ";
        while (temp)
        {
            std::cout << temp->data << " : ";
            temp = temp->next;
        }
    }
    else
        std::cout << "\nlist empty!\n";
}

int main()
{
    list_t list_interface;

    list_interface.insert(1);
    list_interface.print();

    list_interface.remove();
    list_interface.print();

    list_interface.insert(2);
    list_interface.insert(1);
    list_interface.print();

    list_interface.remove();
    list_interface.print();

    list_interface.remove();
    list_interface.print();

    return 0;
}