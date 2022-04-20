#ifndef DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_HPP

template <class ItemType>
struct NodeType
{
    ItemType    info;
    NodeType    *next;
    NodeType    *prev;
};

template <class ItemType>
class DoubleLinkedList
{
private:
    NodeType<ItemType>  *head;
    NodeType<ItemType>  *rear;
    NodeType<ItemType>  *curPos;
    int                 length;
public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    bool        isFull() const;
    bool        isEmpty() const;
    void        makeEmpty();
    int         lengthIs() const;
    void        RetrieveItem(ItemType& item, bool& found);
    void        insertItem(ItemType item);
    void        deleteItem(ItemType item);
    void        resetList();
    void        getNextItem(ItemType &item);
    void        getPrevItem(ItemType &item);
    void        goToRear();
    void        goToHead();
    void        setHeader(ItemType item);
    void        setTrailer(ItemType item);
};

template <class ItemType>
DoubleLinkedList<ItemType>::DoubleLinkedList()
{
    this->head = new NodeType<ItemType>;
    this->rear = new NodeType<ItemType>;
    this->head->prev = NULL;
    this->head->next = this->rear;
    this->rear->prev = this->head;
    this->rear->next = NULL;
    this->curPos = this->head;
    this->length = 0;
}

template <class ItemType>
DoubleLinkedList<ItemType>::~DoubleLinkedList()
{
    NodeType<ItemType>  *node;
    NodeType<ItemType>  *next;

    node = this->head;
    if (node->next == this->head)
    {
        delete node;
    }
    else
    {
        while (node->next != NULL)
        {
            next = node->next;
            delete node;
            node = next;
        }
    }
}

template <class ItemType>
bool    DoubleLinkedList<ItemType>::isFull() const
{
    NodeType<ItemType>* location;
    try
    {
        location = new NodeType<ItemType>;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }
}

template <class ItemType>
void    DoubleLinkedList<ItemType>::makeEmpty()
{
    NodeType<ItemType>  *node;
    NodeType<ItemType>  *next;
    
    if (this->length == 0)
        return ;
    node = this->head->next;
    while (node != this->rear)
    {
        next = node->next;
        delete node;
        node = next;
    }
    this->length = 0;
}

template <class ItemType>
int     DoubleLinkedList<ItemType>::lengthIs() const
{
    return (this->length);
}

template <class ItemType>
void    DoubleLinkedList<ItemType>::RetrieveItem(ItemType& item, bool& found)
{
    NodeType<ItemType>  *node;

    node = this->head->next;
    while (node != this->rear)
    {
        node = node->next;
        if (node->info == item)
        {
            found = true;
            return ;
        }
    }
    found = false;
}

template <class ItemType>
void    DoubleLinkedList<ItemType>::insertItem(ItemType item)
{
    NodeType<ItemType>  *lastNode;
    NodeType<ItemType>  *newNode;

    lastNode = this->rear->prev;
    newNode = new NodeType<ItemType>;
    newNode->info = item;
    newNode->prev = lastNode;
    newNode->next = this->rear;
    lastNode->next = newNode;
    this->rear->prev = newNode;
    ++(this->length);
}

template <class ItemType>
void    DoubleLinkedList<ItemType>::deleteItem(ItemType item)
{
    NodeType<ItemType>  *node;

    node = this->head->next;
    while (node != this->rear)
    {
        node = node->next;
        if (node->info == item)
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
            --(this.length);
            return ;
        }
    }
}

template <class ItemType>
void    DoubleLinkedList<ItemType>::resetList()
{
    currentPos = this->head;
}

template <class ItemType>
void    DoubleLinkedList<ItemType>::getNextItem(ItemType &item)
{
    this->curPos = this->curPos->next;
    if (this->curPos != NULL)
        item = curPos->info;
}
template <class ItemType>
void    DoubleLinkedList<ItemType>::getPrevItem(ItemType &item)
{
    this->curPos = this->curPos->prev;
    if (this->curPos != NULL)
        item = curPos->info;
}

template <class ItemType>
void    DoubleLinkedList<ItemType>::goToHead()
{
    currentPos = this->head;
}

template <class ItemType>
void    DoubleLinkedList<ItemType>::goToRear()
{
    currentPos = this->rear;
}

template <class ItemType>
void    DoubleLinkedList<ItemType>::setHeader(ItemType item)
{
    this->head->info = item;
}

template <class ItemType>
void    DoubleLinkedList<ItemType>::setTrailer(ItemType item)
{
    this->rear->info = item;
}
#endif