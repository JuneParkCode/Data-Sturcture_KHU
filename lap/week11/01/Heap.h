template <class ItemType>
void swap(ItemType &one, ItemType &two);

template <class ItemType>
// Assumes ItemType is either a built-in simple type or a class
// with overloaded relational operators.
struct HeapType
{
  void ReheapDown(int root, int bottom);
  void ReheapUp(int root, int bottom);
  ItemType *elements; // Array to be allocated dynamically
  int numElements;
};

template <class ItemType>
void Swap(ItemType &one, ItemType &two)
{
  ItemType temp;
  temp = one;
  one = two;
  two = temp;
}

/*
 *
 *  EX01 - a
 *  O(h) (h is height of tree)
 * 
*/

template <class ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom)
{
  int parent;
  bool reHeaped = false;

  while (bottom > root && !reHeaped)
  {
    parent = (bottom - 1) / 2;
    if (elements[parent] < elements[bottom])
    {
      Swap(elements[parent], elements[bottom]);
      bottom = parent;
    }
    else
    {
      reHeaped = true;
    }
  }
}

/*
 *
 *  EX01 - b
 *  O(h) (h is height of tree)
 * 
*/

template <class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom)
{
  int maxChild;
  int rightChild;
  int leftChild;
  bool reHeaped = false;

  leftChild = root * 2 + 1;
  while (leftChild <= bottom && !reHeaped)
  {
    if (leftChild == bottom)
      maxChild = leftChild;
    else
    {
      if (elements[leftChild] <= elements[rightChild])
        maxChild = rightChild;
      else
      {
        rightChild = root * 2 + 2;
        maxChild = leftChild;
      }
    }
    if (elements[root] < elements[maxChild])
    {
      Swap(elements[root], elements[maxChild]);
      root = maxChild;
      leftChild = root * 2 + 1;
    }
    else
      reHeaped = true;
  }
}
/*
template<class ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom)
// Post: Heap property is restored.
{
  int parent;

  if (bottom > root)
  {
    parent = (bottom-1) / 2;
    if (elements[parent] < elements[bottom])
    {
      Swap(elements[parent], elements[bottom]);
      ReheapUp(root, parent);
    }
  }
}
template <class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom)
// Post: Heap property is restored.
{
  int maxChild;
  int rightChild;
  int leftChild;

  leftChild = root*2+1;
  rightChild = root*2+2;
  if (leftChild <= bottom)
  {
    if (leftChild == bottom)
      maxChild = leftChild;
    else
    {
      if (elements[leftChild] <= elements[rightChild])
        maxChild = rightChild;
      else
        maxChild = leftChild;
    }
    if (elements[root] < elements[maxChild])
    {
      Swap(elements[root], elements[maxChild]);
      ReheapDown(maxChild, bottom);
    }
  }
}
*/