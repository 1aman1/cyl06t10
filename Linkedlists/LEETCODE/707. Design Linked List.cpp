struct Node
{
    int val;
    Node *next;

    Node(int x) : val(x), next(nullptr)
    {
    }
};

class MyLinkedList
{

    Node *head;
    int size;

public:
    MyLinkedList()
    { // CTor
        head = nullptr;
        size = 0;
    }

    int get(int index)
    {
        // index validity for get
        if (index < 0 || index > size - 1)
            return -1;

        Node *traverse = head;

        while (index)
        {
            // iterate to the index
            traverse = traverse->next;
            --index;
        }

        return traverse->val;
    }

    void addAtHead(int val)
    {
        Node *newNode = new Node(val);

        newNode->next = head;
        head = newNode;

        ++size;
    }

    void addAtTail(int val)
    {
        Node *newNode = new Node(val);

        // if list is empty
        if (!head)
        {
            head = newNode;
        }

        // traverse till the end and append new node
        else
        {
            Node *tmp = head;

            // iterate to the index
            while (tmp->next)
            {
                tmp = tmp->next;
            }
            tmp->next = newNode;
        }

        ++size;
    }

    void addAtIndex(int index, int val)
    {
        // index validity for add
        if (index < 0 || index > size)
            return;

        if (index == 0)
        {
            addAtHead(val);
        }

        /* Need to debug
        else if ( index == size )  {
            addAtTail ( val );
        }
        */

        else
        {
            // using two pointers
            // prePtr closely follows currPtr

            Node *prePtr, *currPtr;

            prePtr = currPtr = head;

            // iterate to the index
            while (index)
            {
                prePtr = currPtr;
                currPtr = currPtr->next;
                --index;
            }

            // node in currPtr needs to be shifted forward
            // adjust prePtr->next and newNode->next to maintain list

            Node *newNode = new Node(val);
            prePtr->next = newNode;
            newNode->next = currPtr;
        }

        ++size;
    }

    void deleteAtIndex(int index)
    {
        // index validity for delete
        if (index < 0 || index > size - 1)
        {
            return;
        }

        Node *prePtr = nullptr, *currPtr = nullptr;

        if (index == 0)
        {
            // delete first element
            currPtr = head;
            head = head->next;
        }

        else
        {

            prePtr = nullptr;
            currPtr = head;

            // iterate to the index
            while (index)
            {
                prePtr = currPtr;
                currPtr = currPtr->next;
                --index;
            }
            // currPtr holds pointer to the node that has to be deleted
            // adjust prePtr && currPtr->next
            prePtr->next = currPtr->next;
        }

        delete currPtr;
        --size;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */