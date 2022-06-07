// Definition of class PQType, which represents the Priority Queue ADT
class FullPQ
{
};
class EmptyPQ
{
};
#include "SortedType.h"

/* PQLLTYPE으로 작성해야하나, 편의상 PQTYPE로 작성함...*/
template <class ItemType>
class PQType
{
public:
  PQType();  // parameterized class constructor
  ~PQType(); // class destructor

  void MakeEmpty();
  // Function: Initializes the queue to an empty state.
  // Post: Queue is empty.

  bool IsEmpty() const;
  // Function: Determines whether the queue is empty.
  // Post: Function value = (queue is empty)

  bool IsFull() const;
  // Function: Determines whether the queue is full.
  // Post: Function value = (queue is full)

  void Enqueue(ItemType newItem);
  // Function: Adds newItem to the rear of the queue.
  // Post: if (the priority queue is full) exception FullPQ is thrown;
  //       else newItem is in the queue.

  void Dequeue(ItemType &item);
  // Function: Removes element with highest priority from the queue
  // and returns it in item.
  // Post: If (the priority queue is empty) exception EmptyPQ is thrown;
  //       else highest priority element has been removed from queue.
  //       item is a copy of removed element.
private:
  int length;
  SortedType<ItemType> linkedList;
  // int maxItems;
};

template <class ItemType>
PQType<ItemType>::PQType()
{
  length = 0;
}

template <class ItemType>
void PQType<ItemType>::MakeEmpty()
{
  length = 0;
  this->linkedList.MakeEmpty();
}

template <class ItemType>
PQType<ItemType>::~PQType()
{
}

template <class ItemType>
void PQType<ItemType>::Dequeue(ItemType &item)
// Post: element with highest priority has been removed
//       from the queue; a copy is returned in item.
{
  if (length == 0)
    throw EmptyPQ();
  else
  {
    this->linkedList.ResetList();
    this->linkedList.GetNextItem(item);
    this->linkedList.DeleteItem(item);
    --(this.length);
  }
}

template <class ItemType>
void PQType<ItemType>::Enqueue(ItemType newItem)
// Post: newItem is in the queue.
{
  if (this->IsFull())
    throw FullPQ();
  else
  {
    this->linkedList.InsertItem(newItem);
    ++(this.length);
  }
}
template <class ItemType>
bool PQType<ItemType>::IsFull() const
// Post: Returns true if the queue is full; false, otherwise.
{
  return this->linkedList.IsFull();
}

template <class ItemType>
bool PQType<ItemType>::IsEmpty() const
// Post: Returns true if the queue is empty; false, otherwise.
{
  return length == 0;
}
