// This file contains the code for the routines in the text.
// It is not complete and will not compile.
#include "SortedType.h"
#include <iostream>

template<class ItemType>
void FindItem(NodeType<ItemType>* listData, 
              ItemType item,
              NodeType<ItemType>*& location, 
              NodeType<ItemType>*& predLoc,
              bool& found)
// Assumption: ItemType is a type for which the operators ''<'' and
//      "==" are defined as either an appropriate built-in type or a
//      class that overloads these operations.
// Pre: List is not empty.
// Post:If there is an element someItem whose key matches item's
//      key, then found = true; otherwise, found = false.
//      If found, location contains the address of someItem and
//      predLoc contains the address of someItem's predecessor;
//      otherwise, location contains the address of item's logical
//      successor and predLoc contains the address of item's
//      logical predecessor.
{
  bool moreToSearch = true;

  location = listData->next;
  predLoc = listData;
  found = false;

  while (moreToSearch && !found)
  {
    if (item < location->info)
      moreToSearch = false;
    else if (item == location->info)
      found = true;
    else
    {
      predLoc = location;
      location = location->next;
      moreToSearch = (location != listData->next);
    }
  }
}

template<class ItemType>
void SortedType<ItemType>::InsertItem(ItemType item)
{
  NodeType<ItemType>* newNode;
  NodeType<ItemType>* predLoc;
  NodeType<ItemType>* location;
  bool found;
  
  newNode = new NodeType<ItemType>;
  newNode->info = item;
  if (listData != NULL)
  {
    FindItem(listData, item, location, predLoc, found);
    newNode->next = predLoc->next;
    predLoc->next = newNode;
    // If this is last node in list, reassign listData.
    if (listData->info < item)
      listData = newNode;
  }
  else // Inserting into an empty list.
  {
    listData = newNode;
    newNode->next = newNode;
  }
  length++;
}

template<class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item)
{
  NodeType<ItemType>* location;
  NodeType<ItemType>* predLoc;
  bool found;
  
  FindItem(listData, item, location, predLoc, found);
  if (predLoc == location) // Only node in list?
    listData = NULL;
  else
  {
    predLoc->next = location->next;
    if (location == listData) // Deleting last node in list?
      listData = predLoc;
  }
  delete location;
  length--;
}

template<class ItemType>
void recursive_print(NodeType<ItemType> *node, NodeType<ItemType> *head)
{
  if (node->next != head)
    recursive_print(node->next, head);
  std::cout << node->info << "\n";
}

template<class ItemType>
void SortedType<ItemType>::PrintReverse()
{
  if (this->listData == NULL)
    return ;
  recursive_print(this->listData->next, this->listData->next);
}