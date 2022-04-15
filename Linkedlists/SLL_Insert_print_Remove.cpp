#include <iostream>
using namespace std;

struct Node{

  int data;
  Node* next;

  Node(int x): data(x),next(nullptr) {}
  ~Node() {}

};

class linked_list {
private:
  Node* head;
  int SLL_size = 0;
public:
  linked_list();
  ~linked_list();

  int size();
  bool empty();
  void print();

// function takes value, and (optionally) position to insert
  bool insert(int, int = -1);

// function removes the node at given position
  bool remove(int);
};

bool linked_list::empty() {
  // if size is 0, return true else false
  if ( SLL_size == 0 )
    return true;
  else 
    return false;
} 

int linked_list::size(){
  return SLL_size;
}

linked_list::linked_list() : head(nullptr) {
}

linked_list::~linked_list() {
  if(!head)
    return;

  Node* keepNext = head;
  while(!keepNext)
  {
    keepNext = head->next; 
    delete head;
  }
}

void linked_list::print(){

  // if size zero, print emtpy
  // else continue
  if ( empty() ) {
    cout << "list empty\n";
    return;
  }
  
  Node* printer = head;
  int index = 1;
  while(printer){
    cout << "pos " << index << "- " << printer->data << " :: ";
    printer = printer->next;
    index++;
  }
  cout << endl;
}

bool linked_list::insert(int value, int pos) {
  
  // position is out of bounds
  if ( pos > size() || pos < -1 ) {
      cout << "out of bounds\n";
      return false;
  }

  // list is empty
  if( empty() ) {
    // create one node, 
    head = new Node(value);
    
    SLL_size = 1;
    return true;
  }
  
  // when position not given, insert in the end
  if( pos == -1) {
      Node* temp = head;
      // insert logic

      while(temp->next)  temp=temp->next;
      temp->next = new Node(value);
  
      SLL_size++;
      return true;        
  }

  // when position 0, insert at front
  if ( pos == 0 ) {
    Node* temp = new Node(value);
    temp->next = head;
    head = temp;
    
    SLL_size++;
    return true;
  }
  else {    
  // position is > 0 and < size()

    int index = 0;
    
    Node* curr;
    Node* prev;

    // insert logic
    prev = head;
    curr = prev->next;
  
    while ( index < pos - 1 ) {
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

bool linked_list::remove(int pos) {
  // if position is negative or greater than size
  if ( pos > ( size()-1 )   || pos < 0 ) {
    cout << "position invalid\n";
    return false;
  }
  
  else {  // position is valid

    // is pos == 0
    if  ( pos == 0 ) {
      Node* temp = head;
      head = head->next;
  
      delete temp;
      SLL_size--;
      
      return true;
    }
      
    else {
      int index = 0;
      Node* curr = head;
      Node* NEXT = curr->next;
      
      while ( index < pos -1 ) {
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

void insertMod( linked_list &mylist, int value, int pos = -1 ) {
  if ( mylist.insert(value, pos) )
    cout << "insert Success\n";
  else
    cout << "insert failed\n";
}

void removeMod( linked_list &mylist, int pos) {
  if ( mylist.remove( pos ) ) 
    cout << "Remove Success\n";
  else
    cout << "Remove failed\n";
}

int main() {

  linked_list mylist;

  int choice = 1, input;
  while ( choice ) {
    cout << "1 : insert   2 : print 3 : remove--- > " ;
    cin >> input;
    
    switch(input) {
      
      case 1: {
        int value, pos;
        cout << "input value -> ";
        cin >> value;  
        cout << "input position -> ";
        cin >> pos;
      
        insertMod(mylist, value, pos);
        break;
      }
      
      case 2: {
        mylist.print();
        break;
      }

      case 3: {
        if ( mylist.empty() ) {
          cout << "list already empty";
        }
        else {
          cout << "input position  -->";
          int pos;
          cin >> pos;
          removeMod(mylist, pos);  
        }
      }
    }
    cout << "continue ?";
    cin >> choice;
  }
  
  return 0;
}
