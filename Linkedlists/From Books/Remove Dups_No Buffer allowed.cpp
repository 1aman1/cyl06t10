#include <iostream>
#define DEBUG true
/*
removes elements from an unsorted singly linked head
no extra buffer allowed

n is length of linked head
->Space O(1)
->Time O(n*n)
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

    Node *head;

    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(3);

    print(head);

    // removal logic
    Node *current = head;
    while (current)
    {
        Node *traverser = current->next;
        // take current node and find it's occurrences in list further

        while (traverser)
        {
            if (current->data == traverser->data)
            { // matched
                current->next = traverser->next;
            }
            traverser = traverser->next;
        }
        current = current->next;
    }
    
    print(head);

    return 0;
}