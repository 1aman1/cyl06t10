#include <iostream>

struct Node
{
  int data;
  Node *next;

  Node(int x) : data(x), next(nullptr) {}
  ~Node() {}
};

class linked_list
{
private:
  Node *head;
  int SLL_size = 0;

public:
  linked_list();
  ~linked_list();

  int size();
  bool empty();
  void print();

  // function takes position (optionally) to insert, value to insert,
  bool insert(int, int);
  bool insert(int);

  // function removes the node at given position
  bool remove(int);
};

bool linked_list::empty()
{
  if (SLL_size == 0)
    return true;
  else
    return false;
}

int linked_list::size()
{
  return SLL_size;
}

linked_list::linked_list() : head(nullptr)
{
}

linked_list::~linked_list()
{
  if (!head)
    return;

  Node *keepNext = head;
  while (!keepNext)
  {
    keepNext = head->next;
    delete head;
  }
}

void linked_list::print()
{
  if (empty())
  {
    std::cout << "list empty\n";
    return;
  }

  Node *printer = head;
  int index = 1;
  while (printer)
  {
    std::cout << "pos " << index << "- " << printer->data << " :: ";
    printer = printer->next;
    index++;
  }
  std::cout << std::endl;
}

bool linked_list::insert(int value, int pos = -1)
{
  // position is out of bounds
  if (pos > size() || pos < -1)
  {
    std::cout << "out of bounds\n";
    return false;
  }

  // list is empty
  if (empty())
  {
    // create one node,
    head = new Node(value);

    SLL_size = 1;
    return true;
  }

  // when position 0, insert at front
  if (pos == 0)
  {
    Node *temp = new Node(value);
    temp->next = head;
    head = temp;

    SLL_size++;
    return true;
  }
  else
  {
    // position is > 0 and < size()
    int index = 0;

    // insert logic

    Node *curr;
    Node *prev;

    prev = head;
    curr = prev->next;

    while (index < pos - 1)
    {
      prev = curr;
      curr = curr->next;
      index++;
    }
    prev->next = new Node(value);
    prev->next->next = curr;

    SLL_size++;
    return true;
  }
}

bool linked_list::remove(int pos)
{
  // if position is negative or greater than size
  if (pos > (size() - 1) || pos < 0)
  {
    std::cout << "position invalid\n";
    return false;
  }

  else
  { // position is valid

    // is pos == 0
    if (pos == 0)
    {
      Node *temp = head;
      head = head->next;

      delete temp;
      SLL_size--;

      return true;
    }

    else
    {
      int index = 0;
      Node *curr = head;
      Node *NEXT = curr->next;

      while (index < pos - 1)
      {
        ++index;
        curr = NEXT;
        NEXT = NEXT->next;
      }
      curr->next = NEXT->next;

      delete NEXT;

      SLL_size--;
      return true;
    }
  }
}

/*
void insertMod(linked_list &mylist, int value, int pos = -1)
{
  if (mylist.insert(value, pos))
    std::cout << "insert Success\n";
  else
    std::cout << "insert failed\n";
}
*/
void removeMod(linked_list &mylist, int pos)
{
  if (mylist.remove(pos))
    std::cout << "Remove Success\n";
  else
    std::cout << "Remove failed\n";
}

int main()
{

  linked_list mylist;

  int choice = 1, input;
  while (choice)
  {
    std::cout << "1 : insert   "
              << "2 : print "
              << "3 : remove--- > ";
    std::cin >> input;

    switch (input)
    {

    case 1:
    {
      int value, pos, locationChoice = 0;
      std::cout << "input value -> ";
      std::cin >> value;
      std::cout << "Want to insert at specific location ? -1 is no";
      std::cin >> locationChoice;

      if (locationChoice != -1)
      {
        std::cout << "input position -> ";
        std::cin >> pos;
        std::cout << std::boolalpha << mylist.insert(pos, value);
      }
      else
      {
        std::cout << mylist.insert(value);
      }
      break;
    }

    case 2:
    {
      mylist.print();
      break;
    }

    case 3:
    {
      if (mylist.empty())
      {
        std::cout << "list already empty";
      }
      else
      {
        std::cout << "input position  -->";
        int pos;
        std::cin >> pos;
        removeMod(mylist, pos);
      }
    }
    }
    std::cout << "continue ?";
    std::cin >> choice;
  }

  return 0;
}
