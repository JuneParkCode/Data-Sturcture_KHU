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
EX 04
*/

int QueType::Length() const
{
  if (this->front < this->rear)
    return (this->rear - this->front);
  else
    return (this->maxQue - this->front + this->rear);  
}

int Length(QueType &queue)
{
  ItemType  item;
  QueType   tmp;
  int       len;

  len = 0;
  while (!queue.IsEmpty())
  {
    queue.Dequeue(item);
    tmp.Enqueue(item);
    ++len;
  }
  while (!tmp.IsEmpty())
  {
    tmp.Dequeue(item);
    queue.Enqueue(item);
  }
  return (len);
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

  
  
  for (int i = 0; i < 500; ++i)
  {
    item = rand() % 10;
    myQ.Enqueue(item);
  }
  for (int i = 0; i < 200; ++i)
  {
    myQ.Dequeue(item);
  }
  for (int i = 0; i < 100; ++i)
  {
    item = rand() % 10;
    myQ.Enqueue(item);
  }
  cout << "\n\n===TEST 1 : member function===" << endl;
  cout << myQ.Length() <<endl;
  cout << Length(myQ) << endl;
  return (0);
}