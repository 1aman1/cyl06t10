#include <iostream>

struct list_node
{
  int data;
  list_node *next;

  list_node(int x) : data(x), next(nullptr) {}
  ~list_node() {}
};

class linked_list
{
private:
  list_node *head;
  int list_size;

public:
  linked_list();
  ~linked_list();

  int size();
  bool empty();
  void print();

  // function takes value to insert, position (optionally)
  bool insert(int, int);

  // function removes the node at given position
  bool remove(int);
};

bool linked_list::empty()
{
  if (list_size == 0)
    return true;
  else
    return false;
}

int linked_list::size()
{
  return list_size;
}

linked_list::linked_list()
{
  head = nullptr;
  list_size = 0;
}

linked_list::~linked_list()
{
  if (!head)
    return;

  list_node *keepNext = head;
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

  list_node *printer = head;
  int index = 1;
  while (printer)
  {
    std::cout << "@" << index << "->" << printer->data << " :: ";
    printer = printer->next;
    index++;
  }
  std::cout << std::endl;
}

bool linked_list::insert(int value, int index)
{
  // abort case
  // position is out of bounds
  if (index > (size() + 1) || index < -1)
  {
    std::cout << "out of bounds\n";
    return false;
  }
  else
  {
    // list is empty
    if (empty())
    {
      // create one node,
      head = new list_node(value);

      list_size = 1;
      return true;
    }

    // when position 1, insert at front
    if (index == 1)
    {
      list_node *temp = new list_node(value);
      temp->next = head;
      head = temp;

      list_size++;
      return true;
    }

    // 1 < index  <= size()
    int pos = 1;

    // insert logic

    list_node *curr;
    list_node *prev;

    prev = head;
    curr = prev->next;

    while (pos < index - 1)
    {
      prev = curr;
      curr = curr->next;
      pos++;
    }
    prev->next = new list_node(value);
    prev->next->next = curr;

    list_size++;
    return true;
  }
}

bool linked_list::remove(int index)
{
  // abort case
  // if position is negative or greater than size
  if (1 > index || index > size())
  {
    std::cout << "Out Of Bounds\n";
    return false;
  }

  else
  { // index is valid

    if (index == 1)
    {
      list_node *temp = head;
      head = head->next;

      delete temp;
      list_size--;

      return true;
    }

    int counter = 1;
    list_node *prev = head;
    list_node *curr = prev->next;

    // curr is already one step ahead , so we need to exit the loop one step early
    while (counter < index - 1)
    {
      prev = curr;
      curr = curr->next;
      ++counter;
    }
    prev->next = curr->next;

    delete curr;

    list_size--;
    return true;
  }
}

int main()
{
  linked_list list_obj;

  int choice = 1, input;

  std::cout << "This Singly Linked list is 1 indexed\n";

  while (choice)
  {
    std::cout << "\n1: insert  "
              << "2: print "
              << "3: remove--- > ";
    std::cin >> input;
    std::cout << std::endl;

    switch (input)
    {

    case 1:
    {
      int value, index;
      std::cout << "insert value -> ";
      std::cin >> value;
      std::cout << "BY DEFAULT insert at front OR input index to insert? -1 is a No\n";
      std::cin >> index;

      if (index == -1) // insert at front
      {
        std::cout << std::boolalpha << list_obj.insert(value, 1) << std::endl;
      }
      else
      {
        std::cout << std::boolalpha << list_obj.insert(value, index) << std::endl;
      }

      break;
    }

    case 2:
    {
      list_obj.print();
      break;
    }

    case 3:
    { // remove case
      int index;
      std::cout << "BY DEFAULT remove at front OR input index to remove? -1 is a No\n";
      std::cin >> index;

      if (index == -1) // remove at front
      {
        std::cout << std::boolalpha << list_obj.remove(1) << std::endl;
      }
      else
      {
        std::cout << std::boolalpha << list_obj.remove(index) << std::endl;
      }
    }
    }

    // std::cout << "\ncontinue ?";
    // std::cin >> choice;
    choice = 1;
  }

  return 0;
}
