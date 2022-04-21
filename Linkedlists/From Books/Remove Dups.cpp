#include <iostream>
#include <set>

/*
removes elements from an unsorted singly linked list
takes up extra buffer to keep track if element was seen previously

n is length of linked list
->Space O(n)
->Time O(n)
*/

struct Node
{
    int data;
    Node *next;

    Node(int x) : data(x), next(nullptr) {}
    ~Node() {}
};

void print(Node *tmp)
{
    while (tmp)
    {
        std::cout << tmp->data << "->";
        tmp = tmp->next;
    }
    std::cout << std::endl;
}

int main()
{

    Node *list;

    list = new Node(1);
    list->next = new Node(2);
    list->next->next = new Node(2);
    list->next->next->next = new Node(4);
    list->next->next->next->next = new Node(3);
    list->next->next->next->next->next = new Node(3);

    print(list);

    std::set<int> buffer;

    // removal logic, takes O(n)
    Node *current;
    Node *previous;

    previous = nullptr;
    current = list;

    while (current)
    {
        if (buffer.find(current->data) != buffer.end())
        { // element present

            previous->next = current->next;
        }
        else
        { // not present
            buffer.insert(current->data);
            previous = current;
        }
        current = current->next;
    }

    print(list);

    return 0;
}