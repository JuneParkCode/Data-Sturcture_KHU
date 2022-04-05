#include "QueType.h"

QueType::QueType(int max)
// Parameterized class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = max + 1;
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new ItemType[maxQue];
}
QueType::QueType()          // Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = 501;
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new ItemType[maxQue];
}
QueType::~QueType()         // Class destructor
{
}

void QueType::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
  front = maxQue - 1;
  rear = maxQue - 1;
}

bool QueType::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
  return (rear == front);
}

bool QueType::IsFull() const
// Returns true if the queue is full; false otherwise.
{
  return ((rear + 1) % maxQue == front);
}

void QueType::Enqueue(ItemType newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.  
{
  if (IsFull())
    throw FullQueue();
  else
  {
    rear = (rear +1) % maxQue;
    items[rear] = newItem;
  }
}

void QueType::Dequeue(ItemType& item)
// Post: If (queue is not empty) the front of the queue has been 
//       removed and a copy returned in item; 
//       othersiwe a EmptyQueue exception has been thrown.
{
  if (IsEmpty())
    throw EmptyQueue();
  else
  {
    front = (front + 1) % maxQue;
    item = items[front];
  }
}

/*
EX 03
*/


bool QueType::Identical(QueType queue)
{
  int       idx_this = (this->front + 1) % this -> maxQue;
  ItemType  item1;
  ItemType  item2;

  while (!queue.IsEmpty())
  {
    item1 = this->items[idx_this];
    queue.Dequeue(item2);
    if (item1 != item2)
      return (false);
    if (idx_this == this->rear)
      return (true) ;
    idx_this = (idx_this = idx_this + 1 ) % this->maxQue;
  }
  return (false);
}

bool Identical(QueType queue1, QueType queue2)
{
  ItemType item1;
  ItemType item2;

  while (!queue1.IsEmpty() && !queue2.IsEmpty())
  { 
    queue1.Dequeue(item1);
    queue2.Dequeue(item2);
    if (item1 != item2)
      return (false);
  }
  return (queue1.IsEmpty() && queue2.IsEmpty());
}


#include <random>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;
  
int main(void)
{
  QueType   myQ;
  QueType   myQ2;
  ItemType  item;

  srand(time(NULL));

  
  cout << "\n\n===TEST 1 : member function===" << endl;
  cout << "\n\nINPUT!!!!" << endl;  
  for (int i = 0; i < 20; ++i)
  {
    item = rand() % 10;
    cout << "in -> q1, q2 : "<< item << endl;
    myQ.Enqueue(item);
    myQ2.Enqueue(item);
  }
  cout << "\n\nRES1 : " << (myQ.Identical(myQ2) ? "EQUAL" : "NOT EQUAL")<<endl;

  cout << "DEQ q1" <<endl;
  myQ.Dequeue(item);
  cout << "RES2 : " << (myQ.Identical(myQ2) ?  "EQUAL" : "NOT EQUAL") <<endl;

  QueType   myQ3;
  QueType   myQ4;
  cout << "\n\n===TEST 2 : client function===" << endl;
  for (int i = 0; i < 20; ++i)
  {
    item = rand() % 10;
    cout << "in -> q1, q2 : "<< item << endl;
    myQ3.Enqueue(item);
    myQ4.Enqueue(item);
  }
  cout << "\n\nRES : " << (Identical(myQ3, myQ4) ? "EQUAL" : "NOT EQUAL") <<endl;

  cout << "DEQ q1" <<endl;
  myQ3.Dequeue(item);
  cout << "RES : " << (Identical(myQ3, myQ4) ? "EQUAL" : "NOT EQUAL") <<endl;



  return (0);
}