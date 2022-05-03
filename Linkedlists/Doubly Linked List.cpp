#include <iostream>
#define DEBUG true
/*
It has one more member in list_node i.e.,
prev pointer alongwith legacy next pointer
*/

struct list_node
{
  int data;
  list_node *next;
  list_node *prev;

  list_node(int x) : data(x),
                     next(nullptr),
                     prev(nullptr) {}
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
  // DLL can print rev using prev
  void printRev();

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

void linked_list::printRev()
{
  if (empty())
  {
    std::cout << "list empty\n";
    return;
  }

  list_node *printer = head;
  int index = 1;
  while (printer->next != nullptr)
  {
    index++;
    printer = printer->next;
  }

  while (printer)
  {
    std::cout << "@" << index << "->" << printer->data << " :: ";
    printer = printer->prev;
    index--;
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
      head->prev = temp;
      head = temp;

      list_size++;
      return true;
    }

    // 1 < index  <= size()

    list_node *curr = head;
    int pos = 1;

    while (pos < index - 1)
    {
      curr = curr->next;
      pos++;
    }

    list_node *newNode = new list_node(value);
    newNode->next = curr->next;
    curr->next = newNode;
    newNode->prev = curr;

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
      temp->next->prev = nullptr;

      delete temp;
      list_size--;

      return true;
    }

    int counter = 1;
    list_node *curr = head;

    while (counter < index)
    {
      curr = curr->next;
      ++counter;
    }

    DEBUG == true ? std::cout << __LINE__ << "" << std::endl : std::cout << "";
    curr->prev->next = curr->next;
    DEBUG == true ? std::cout << __LINE__ << "" << std::endl : std::cout << "";
    if (curr->next != nullptr)
      curr->next->prev = curr->prev;

    delete curr;

    list_size--;
    return true;
  }
}

int main()
{
  linked_list list_obj;

  int choice = 1, input;

  std::cout << "This Doubly Linked list is 1 indexed\n";

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
      std::cout << "\nReverse Order";
      list_obj.printRev();
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
