#include <new>
// Definition of class PQType, which represents the Priority Queue ADT
class FullPS
{
};
class EmptyPS
{
};

template <class ItemType>
struct NodeType;

template <class ItemType>
class PSType
{
public:
  PSType();  // parameterized class constructor
  ~PSType(); // class destructor

  bool IsEmpty() const;

  bool IsFull() const;

  void Push(ItemType newItem);

  void Pop(ItemType &item);

private:
  int length;
  size_t timeStamp;
  NodeType<ItemType> *top;
};

template <class ItemType>
struct NodeType
{
  ItemType info;
  size_t timeStamp;
  NodeType<ItemType> *next;
};

template <class ItemType>
PSType<ItemType>::PSType()
{
  this->top = nullptr;
  this->length = 0;
  this->timeStamp = 0;
}

template <class ItemType>
PSType<ItemType>::~PSType()
{
  NodeType<ItemType> *topNode;
  NodeType<ItemType> *nextNode;

  topNode = this->top;
  while (topNode)
  {
    nextNode = topNode->next;
    delete topNode;
    topNode = nextNode;
  }
}

template <class ItemType>
bool PSType<ItemType>::IsEmpty() const
{
  return (this->length == 0);
}

template <class ItemType>
bool PSType<ItemType>::IsFull() const
{
  NodeType<ItemType> *location;
  try
  {
    location = new NodeType<ItemType>;
    delete (location);
    return (false);
  }
  catch (std::bad_alloc exception)
  {
    return (true);
  }
}

/* O(1) */
template <class ItemType>
void PSType<ItemType>::Push(ItemType item)
{
  if (this->IsFull())
    throw(FullPS());

  NodeType<ItemType> *newNode = new NodeType<ItemType>;

  // set node
  newNode->info = item;
  newNode->timeStamp = this->timeStamp;
  // add to top
  newNode->next = this->top;
  this->top = newNode;
  //
  ++length;
  ++(this->timeStamp);
}

/* O(n) */
template <class ItemType>
void PSType<ItemType>::Pop(ItemType &item)
{
  if (this->IsEmpty())
    throw(EmptyPS());

  NodeType<ItemType> *topNode;
  NodeType<ItemType> *lstTopNode;
  NodeType<ItemType> *node;
  unsigned int timeMax;

  lstTopNode = this->top;
  if (length > 1)
  {
    node = this->top;
    timeMax = 0;
    // N개 만큼 순회를 항상 해야한다. (최댓값을 찾기 위해)
    while (node)
    {
      if (timeMax < node->timeStamp)
      {
        timeMax = node->timeStamp;
        topNode = node;
      }
      node = node->next;
    }
    item = topNode->info;

    // swap with current top (list) node
    int tmpTime = lstTopNode->timeStamp;
    int tmpInfo = lstTopNode->info;

    lstTopNode->info = topNode->info;
    lstTopNode->timeStamp = topNode->timeStamp;

    topNode->info = tmpInfo;
    topNode->timeStamp = tmpTime;
  }
  else
  {
    item = this->top->info;
  }
  this->top = lstTopNode->next;
  delete (lstTopNode);
  --length;
}