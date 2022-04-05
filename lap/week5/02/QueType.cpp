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
  delete [] items;
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
EX 02
*/

void QueType::ReplaceItem(ItemType oldItem, ItemType newItem)
{
  int idx = this->front;
  while (true)
  {
    ItemType &item = this->items[idx];
    if (item == oldItem)
      item = newItem;
    if (idx ==  this->rear)
      break;
    idx = (idx + 1) % this->maxQue;
  }
}

void ReplaceItem(QueType &queue, int olditem, int newitem)
{
  QueType   tmpQ;
  ItemType  item;

  while (!queue.IsEmpty())
  {
    queue.Dequeue(item);
    if (item == olditem)
      item = newitem;
    tmpQ.Enqueue(item);
  }
  while (!tmpQ.IsEmpty())
  {
    tmpQ.Dequeue(item);
    queue.Enqueue(item);
  }
}

#include <random>
#include <ctime>
#include <iostream>
using namespace std;
  
int main(void)
{
  QueType   myQ;
  QueType   myQ2;
  ItemType  item;

  srand(time(NULL));
  cout << "INPUT!!!!" << endl;
  for (int i = 0; i < 20; ++i)
  {
    item = rand() % 10;
    cout << item << endl;
    myQ.Enqueue(item);
    myQ2.Enqueue(item);
  }

  
  ItemType  oldItem = rand() % 10;
  ItemType  newItem = rand() % 10;
  ReplaceItem(myQ, oldItem, newItem);
  cout << "\n\nTEST 1 : client function" << endl;
  cout << oldItem << " is replaced to " << newItem <<endl;

  cout << "\n\nOUTPUT!!!!" << endl;
  while (!myQ.IsEmpty())
  {
    myQ.Dequeue(item);
    cout << item << endl;
  }

  myQ2.ReplaceItem(oldItem, newItem);
  cout << "\n\nTEST 2 : member function" << endl;
  cout << oldItem << " is replaced to " << newItem <<endl;

  cout << "\n\nOUTPUT!!!!" << endl;
  while (!myQ2.IsEmpty())
  {
    myQ2.Dequeue(item);
    cout << item << endl;
  }
  return (0);
}