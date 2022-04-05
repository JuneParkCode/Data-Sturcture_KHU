#include "QueType.h"

QueType<ItemType>::QueType(int max)
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
QueType<ItemType>::QueType()          // Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = 501;
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new ItemType[maxQue];
}
QueType<ItemType>::~QueType()         // Class destructor
{
  delete [] items;
}

void QueType<ItemType>::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
  front = maxQue - 1;
  rear = maxQue - 1;
}

bool QueType<ItemType>::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
  return (rear == front);
}

bool QueType<ItemType>::IsFull() const
// Returns true if the queue is full; false otherwise.
{
  return ((rear + 1) % maxQue == front);
}

void QueType<ItemType>::Enqueue(ItemType newItem)
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

void QueType<ItemType>::Dequeue(ItemType& item)
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

// ex02
void QueType<ItemType>::ReplaceItem(ItemType oldItem, ItemType newItem)
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

void ReplaceItem(QueType <int> &queue, int olditem, int newitem)
{
  QueType<int>  tmpQ;
  ItemType      item;

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
