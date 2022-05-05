// Header file for Queue ADT. 
class FullQueue
{};  

class EmptyQueue
{};  
 
template <class ItemType>
struct NodeType;

template <class ItemType>
class QueType
{
public: 
    QueType();
    // Class constructor.
    // Because there is a default constructor, the precondition 
    // that the queue has been initialized is omitted.
    QueType(QueType<ItemType> &otherQueue);
    // Parameterized class constructor.
    ~QueType();
    // Class destructor.
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
    // Post: If (queue is full) FullQueue exception is thrown
    //       else newItem is at rear of queue.
    void Dequeue(ItemType& item);
    // Function: Removes front item from the queue and returns it in item.
    // Post: If (queue is empty) EmptyQueue exception is thrown
    //       and item is undefined
    //       else front element has been removed from queue and
    //       item is a copy of removed element.
    void Copy(QueType<ItemType> &otherQueue);
    void operator=(QueType<ItemType> &otherQueue);
private:
  NodeType<ItemType>* front;
  NodeType<ItemType>* rear;
};

template <class ItemType>
struct NodeType
{
  ItemType info;
  NodeType* next;
};

template <class ItemType>
QueType<ItemType>::QueType()
{
    this->front = NULL;
    this->rear = NULL;
}

template <class ItemType>
QueType<ItemType>::QueType(QueType<ItemType> &otherQueue)
{
    this->front = NULL;
    this->rear = NULL;
    this->Copy(otherQueue);
}

template <class ItemType>
void    QueType<ItemType>::MakeEmpty()
{
    NodeType<ItemType>  *node;
    NodeType<ItemType>  *next;
    node = this->front;
    while (node)
    {
        next = node->next;
        delete (node);
        node = next;
    }
    this->front = NULL;
    this->rear = NULL;
}

template <class ItemType>
bool    QueType<ItemType>::IsEmpty() const
{
    return (this->front == NULL);    
}

template <class ItemType>
bool    QueType<ItemType>::IsFull() const
{
    try
    {
        NodeType<ItemType> newItem;
        
        newItem= new NodeType<ItemType>;
        delete (newItem);
        return (false);
    }
    catch(const std::bad_alloc exception)
    {
        std::cerr << e.what() << '\n';
        return (true);
    }
    
}

template <class ItemType>
void    QueType<ItemType>::Enqueue(ItemType item)
{
    NodeType<ItemType>  *newNode;

    if (this->IsFull())
        return ;
    newNode = new NodeType<ItemType>;
    newNode->info = item;
    newNode->next = NULL;
    this->rear->next = newNode;
    this->rear = newNode;
}

template <class ItemType>
void    QueType<ItemType>::Dequeue(ItemType &item)
{
    NodeType<ItemType>  *next;

    if (this->IsEmpty())
        return ;
    item = this->front->info;
    next = this->front->next;
    if (this->front == this->rear)
    {
        delete (this->front);
        this->rear = NULL;
        this->front = NULL;
    }
    else
    {
        delete (this->front);
        this->front = next;
    }
}

template <class ItemType>
void    QueType<ItemType>::Copy(QueType<ItemType> &otherQueue)
{
    NodeType<ItemType>  *node;

    this->MakeEmpty();
    node = otherQueue->front;
    while (node)
    {
        this->Enqueue(node->info);       
        node = node->next;
    }
}