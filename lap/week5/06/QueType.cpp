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
  minimum_pos = -1;
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
  for (int i = 0; i < maxQue; ++i)
    items[i] = -1;
}
QueType::~QueType()         // Class destructor
{
}

void QueType::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
  for (int i = 0; i < maxQue; ++i)
    items[i] = -1;
  front = maxQue - 1;
  rear = maxQue - 1;
}

bool QueType::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
  int count = 0;
  for (int i = 0; i < maxQue; ++i)
    count += items[i] == -1;
  return (count == maxQue);
}

bool QueType::IsFull() const
// Returns true if the queue is full; false otherwise.
{
  int count = 0;
  for (int i = 0; i < maxQue; ++i)
    count += items[i] == -1;
  return (count == 0);
}

// 해결 못함...
// mindequeue가 있을 때, queue구조라고 할 수 있는걸까?
void QueType::Enqueue(ItemType newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.  
{
  if (IsFull())
    throw FullQueue();
  else
  {
    int idx = 0;
    while (items[idx] != -1)
      ++idx;;
    items[idx] = newItem;
    SetMinimumPos();
  }
}

void QueType::MinDequeue(ItemType &item)
{
  if (IsEmpty())
    throw EmptyQueue();
  else
  {
    item = items[minimum_pos];
    items[minimum_pos] = -1;
    SetMinimumPos();
  }
}

void  QueType::SetMinimumPos()
{
  unsigned int min = -1;
  for (int i = 0; i < maxQue; ++i)
  {
    if (min > (unsigned int) items[i])
    {
      min = items[i];
      minimum_pos = i;
    }
  }
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

  cout << "\n\n test2" << endl;
  cout << "\n input" <<endl;
  for (int i = 0; i < 5; ++i)
  {
    item = rand() % 10;
    myQ2.Enqueue(item);
    cout << item << endl;
  }
  
  cout << "\n output" <<endl;
  while (!myQ2.IsEmpty())
  {
    myQ2.MinDequeue(item);
    cout << item << endl;
  }
  return (0);
}